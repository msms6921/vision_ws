"""Fuse YOLO RGB detections with RealSense aligned depth."""

import math
import os
from typing import Any, Dict, List, Optional, Sequence, Tuple

import cv2
from cv_bridge import CvBridge
from message_filters import ApproximateTimeSynchronizer, Subscriber
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import CameraInfo, Image
from std_msgs.msg import Header

from vision_interfaces.msg import DetectedObject, DetectedObjectArray


class RealSenseYolo3DNode(Node):
    """Detect every object and publish camera-optical-frame XYZ positions."""

    def __init__(self) -> None:
        """Configure parameters, publishers and synchronized subscribers."""
        super().__init__('realsense_yolo_3d')
        self._declare_parameters()
        self.bridge = CvBridge()
        self.camera_info: Optional[CameraInfo] = None
        self.model: Optional[Any] = None
        self._last_model_error = ''

        self.detection_pub = self.create_publisher(
            DetectedObjectArray, '/object_detections_3d', 10)
        self.image_pub = self.create_publisher(
            Image, '/object_detection/image', qos_profile_sensor_data)

        self.create_subscription(
            CameraInfo,
            str(self.get_parameter('camera_info_topic').value),
            self.camera_info_callback,
            qos_profile_sensor_data,
        )

        # RGB와 aligned depth는 같은 시각의 장면이어야 하므로 근사 시간 동기화를 사용한다.
        self.color_sub = Subscriber(
            self, Image, str(self.get_parameter('color_topic').value),
            qos_profile=qos_profile_sensor_data)
        self.depth_sub = Subscriber(
            self, Image, str(self.get_parameter('depth_topic').value),
            qos_profile=qos_profile_sensor_data)
        self.synchronizer = ApproximateTimeSynchronizer(
            [self.color_sub, self.depth_sub],
            queue_size=int(self.get_parameter('sync_queue_size').value),
            slop=float(self.get_parameter('sync_slop').value),
        )
        self.synchronizer.registerCallback(self.synchronized_image_callback)

        self.load_model()
        # A missing/transiently unreadable model must not kill the ROS node.
        self.model_retry_timer = self.create_timer(5.0, self._retry_model)
        self.get_logger().info(
            'Publishing 3D detections on /object_detections_3d and annotated '
            'images on /object_detection/image')

    def _declare_parameters(self) -> None:
        self.declare_parameter('model_path', '/home/msms/Downloads/best.pt')
        self.declare_parameter('confidence_threshold', 0.5)
        self.declare_parameter(
            'color_topic', '/camera/camera/color/image_raw')
        self.declare_parameter(
            'depth_topic',
            '/camera/camera/aligned_depth_to_color/image_raw')
        self.declare_parameter(
            'camera_info_topic', '/camera/camera/color/camera_info')
        self.declare_parameter('min_depth', 0.1)
        self.declare_parameter('max_depth', 5.0)
        self.declare_parameter('depth_roi_ratio', 0.2)
        self.declare_parameter('depth_roi_min_size', 7)
        self.declare_parameter('sync_queue_size', 10)
        self.declare_parameter('sync_slop', 0.08)
        self.declare_parameter('yolo_image_size', 640)

    def load_model(self) -> None:
        """Load the configured Ultralytics model without terminating on error."""
        model_path = str(self.get_parameter('model_path').value)
        if not os.path.isfile(model_path):
            self._log_model_error(f'Model file does not exist: {model_path}')
            return
        try:
            # Import lazily so dependency/model problems leave a live ROS node.
            from ultralytics import YOLO
            self.model = YOLO(model_path)
            self._last_model_error = ''
            self.get_logger().info(f'Loaded YOLO model: {model_path}')
        except Exception as exc:  # external ML stack may raise many exception types
            self.model = None
            self._log_model_error(f'Could not load YOLO model: {exc}')

    def _log_model_error(self, message: str) -> None:
        if message != self._last_model_error:
            self.get_logger().error(message)
            self._last_model_error = message

    def _retry_model(self) -> None:
        if self.model is None:
            self.load_model()

    def camera_info_callback(self, msg: CameraInfo) -> None:
        """Cache color intrinsics; fx/fy are focal lengths, cx/cy principal point."""
        if msg.k[0] > 0.0 and msg.k[4] > 0.0:
            self.camera_info = msg
        else:
            self.get_logger().warning(
                'Ignoring CameraInfo with invalid focal length',
                throttle_duration_sec=5.0)

    def synchronized_image_callback(
            self, color_msg: Image, depth_msg: Image) -> None:
        """Process one approximately synchronized RGB/aligned-depth pair."""
        try:
            color = self.bridge.imgmsg_to_cv2(
                color_msg, desired_encoding='bgr8')
            depth = self.bridge.imgmsg_to_cv2(
                depth_msg, desired_encoding='passthrough')
        except Exception as exc:
            self.get_logger().error(
                f'Image conversion failed: {exc}', throttle_duration_sec=2.0)
            return

        annotated = color.copy()
        header = self._output_header(color_msg, depth_msg)
        detections: List[DetectedObject] = []

        if self.camera_info is None:
            self.get_logger().warning(
                'Waiting for color CameraInfo; publishing no 3D detections',
                throttle_duration_sec=5.0)
        elif self.model is not None:
            try:
                boxes = self.run_yolo(color)
                detections = self._make_detections(
                    boxes, depth, depth_msg.encoding, color.shape[:2], header)
                self.draw_detections(annotated, boxes, detections)
            except Exception as exc:
                # A bad frame or inference must not stop subsequent frames.
                self.get_logger().error(
                    f'Detection frame failed: {exc}',
                    throttle_duration_sec=2.0)

        self.publish_detections(header, detections)
        self._publish_annotated_image(annotated, color_msg.header)

    def _output_header(self, color_msg: Image, depth_msg: Image) -> Header:
        header = Header()
        header.stamp = color_msg.header.stamp
        # CameraInfo belongs to the color intrinsics and normally names the
        # color optical frame. Fall back gracefully when a driver leaves it blank.
        info_frame = self.camera_info.header.frame_id if self.camera_info else ''
        header.frame_id = (
            info_frame or depth_msg.header.frame_id or color_msg.header.frame_id)
        return header

    def run_yolo(self, image: np.ndarray) -> List[Dict[str, Any]]:
        """Return all YOLO boxes above the configured confidence threshold."""
        confidence = float(self.get_parameter('confidence_threshold').value)
        image_size = int(self.get_parameter('yolo_image_size').value)
        result = self.model.predict(
            source=image, conf=confidence, imgsz=image_size,
            verbose=False)[0]
        if result.boxes is None:
            return []

        xyxy = result.boxes.xyxy.detach().cpu().numpy()
        confs = result.boxes.conf.detach().cpu().numpy()
        classes = result.boxes.cls.detach().cpu().numpy().astype(int)
        names = result.names
        return [
            {
                'bbox': tuple(float(value) for value in coords),
                'confidence': float(score),
                'class_id': int(class_id),
                'class_name': str(
                    names.get(class_id, class_id)
                    if isinstance(names, dict) else names[class_id]),
            }
            for coords, score, class_id in zip(xyxy, confs, classes)
        ]

    def _make_detections(
            self, boxes: Sequence[Dict[str, Any]], depth: np.ndarray,
            encoding: str, color_shape: Tuple[int, int],
            header: Header) -> List[DetectedObject]:
        detections = []
        color_h, color_w = color_shape
        if depth.ndim != 2 or color_h <= 0 or color_w <= 0:
            return detections

        depth_h, depth_w = depth.shape
        for box in boxes:
            try:
                x1, y1, x2, y2 = box['bbox']
                x1 = float(np.clip(x1, 0, color_w - 1))
                x2 = float(np.clip(x2, 0, color_w - 1))
                y1 = float(np.clip(y1, 0, color_h - 1))
                y2 = float(np.clip(y2, 0, color_h - 1))
                if x2 <= x1 or y2 <= y1:
                    continue
                u, v = (x1 + x2) / 2.0, (y1 + y2) / 2.0

                # aligned depth should match RGB. If resolutions differ, only
                # map the sampling coordinates; XYZ still uses color pixels/K.
                depth_bbox = (
                    x1 * depth_w / color_w, y1 * depth_h / color_h,
                    x2 * depth_w / color_w, y2 * depth_h / color_h)
                z = self.get_valid_depth(depth, encoding, depth_bbox)
                if z is None:
                    continue
                xyz = self.pixel_to_3d(u, v, z)
                if xyz is None:
                    continue
                x, y, z = xyz

                detected = DetectedObject()
                detected.header = header
                detected.class_name = box['class_name']
                detected.class_id = box['class_id']
                detected.confidence = box['confidence']
                detected.bbox_x1, detected.bbox_y1 = x1, y1
                detected.bbox_x2, detected.bbox_y2 = x2, y2
                detected.center_u, detected.center_v = u, v
                detected.position.x = x
                detected.position.y = y
                detected.position.z = z
                detected.distance = math.sqrt(x * x + y * y + z * z)
                detections.append(detected)
            except Exception as exc:
                self.get_logger().warning(
                    f'Skipping invalid detection: {exc}',
                    throttle_duration_sec=2.0)
        return detections

    def get_valid_depth(
            self, depth: np.ndarray, encoding: str,
            bbox: Tuple[float, float, float, float]) -> Optional[float]:
        """Return median valid depth in a small central bounding-box ROI."""
        scale = self._depth_scale(encoding)
        if scale is None:
            self.get_logger().warning(
                f'Unsupported depth encoding: {encoding}',
                throttle_duration_sec=5.0)
            return None

        x1, y1, x2, y2 = bbox
        center_x, center_y = (x1 + x2) / 2.0, (y1 + y2) / 2.0
        ratio = float(self.get_parameter('depth_roi_ratio').value)
        minimum = max(1, int(self.get_parameter('depth_roi_min_size').value))
        roi_w = max(minimum, int(round((x2 - x1) * ratio)))
        roi_h = max(minimum, int(round((y2 - y1) * ratio)))
        left = max(0, int(round(center_x - roi_w / 2.0)))
        right = min(depth.shape[1], int(round(center_x + roi_w / 2.0)) + 1)
        top = max(0, int(round(center_y - roi_h / 2.0)))
        bottom = min(depth.shape[0], int(round(center_y + roi_h / 2.0)) + 1)
        if left >= right or top >= bottom:
            return None

        values_m = depth[top:bottom, left:right].astype(np.float64) * scale
        min_depth = float(self.get_parameter('min_depth').value)
        max_depth = float(self.get_parameter('max_depth').value)
        valid = values_m[
            np.isfinite(values_m) & (values_m > 0.0) &
            (values_m >= min_depth) & (values_m <= max_depth)]
        if valid.size == 0:
            return None
        # Median suppresses holes (zero), speckles and isolated edge outliers.
        return float(np.median(valid))

    @staticmethod
    def _depth_scale(encoding: str) -> Optional[float]:
        normalized = encoding.upper()
        if normalized in ('16UC1', 'MONO16'):
            return 0.001  # RealSense uint16 depth is millimetres.
        if normalized == '32FC1':
            return 1.0  # float depth is represented in metres.
        return None

    def pixel_to_3d(
            self, u: float, v: float,
            z: float) -> Optional[Tuple[float, float, float]]:
        """Deproject a color pixel with pinhole camera intrinsics."""
        if self.camera_info is None:
            return None
        # K = [fx, 0, cx, 0, fy, cy, ...]. Optical coordinates are
        # +X right, +Y down and +Z forward from the camera.
        fx, fy = self.camera_info.k[0], self.camera_info.k[4]
        cx, cy = self.camera_info.k[2], self.camera_info.k[5]
        if fx <= 0.0 or fy <= 0.0 or not math.isfinite(z):
            return None
        x = (u - cx) * z / fx
        y = (v - cy) * z / fy
        return float(x), float(y), float(z)

    def publish_detections(
            self, header: Header,
            detections: Sequence[DetectedObject]) -> None:
        """Publish all valid 3D objects from a synchronized frame pair."""
        message = DetectedObjectArray()
        message.header = header
        message.objects = list(detections)
        self.detection_pub.publish(message)

    @staticmethod
    def draw_detections(
            image: np.ndarray, boxes: Sequence[Dict[str, Any]],
            detections: Sequence[DetectedObject]) -> None:
        """Overlay class, confidence and metric position on the RGB image."""
        # Draw boxes without depth in orange; valid 3D detections in green.
        height, width = image.shape[:2]
        for box in boxes:
            x1, y1, x2, y2 = box['bbox']
            x1, x2 = int(np.clip(x1, 0, width - 1)), int(np.clip(x2, 0, width - 1))
            y1, y2 = int(np.clip(y1, 0, height - 1)), int(np.clip(y2, 0, height - 1))
            u, v = round((x1 + x2) / 2), round((y1 + y2) / 2)
            # A box can be clipped/rounded by a fraction of a pixel between
            # processing and drawing, so use a small center tolerance.
            item = next((candidate for candidate in detections
                         if candidate.class_id == box['class_id']
                         and abs(candidate.center_u - u) <= 2.0
                         and abs(candidate.center_v - v) <= 2.0), None)
            color = (0, 200, 0) if item else (0, 140, 255)
            cv2.rectangle(image, (x1, y1), (x2, y2), color, 2)
            lines = [f"{box['class_name']} {box['confidence']:.2f}"]
            if item:
                lines.extend([
                    f'X:{item.position.x:.2f} Y:{item.position.y:.2f} '
                    f'Z:{item.position.z:.2f}',
                    f'D:{item.distance:.2f}m',
                ])
                cv2.circle(image, (u, v), 3, color, -1)
            else:
                lines.append('depth: invalid')
            for line_index, line in enumerate(lines):
                text_y = max(15, y1 - 8 - (len(lines) - 1 - line_index) * 18)
                cv2.putText(
                    image, line, (x1, text_y), cv2.FONT_HERSHEY_SIMPLEX,
                    0.5, color, 1, cv2.LINE_AA)

    def _publish_annotated_image(
            self, image: np.ndarray, source_header: Header) -> None:
        try:
            message = self.bridge.cv2_to_imgmsg(image, encoding='bgr8')
            message.header = source_header
            self.image_pub.publish(message)
        except Exception as exc:
            self.get_logger().error(
                f'Annotated image publish failed: {exc}',
                throttle_duration_sec=2.0)


def main(args: Optional[Sequence[str]] = None) -> None:
    """Run the detector until ROS shutdown or a keyboard interrupt."""
    rclpy.init(args=args)
    node = RealSenseYolo3DNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        # ros2 launch may deliver another SIGINT while cleanup is underway.
        try:
            node.destroy_node()
            if rclpy.ok():
                rclpy.shutdown()
        except KeyboardInterrupt:
            pass


if __name__ == '__main__':
    main()
