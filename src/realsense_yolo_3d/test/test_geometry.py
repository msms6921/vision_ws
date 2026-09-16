"""Unit tests for depth filtering and pinhole deprojection."""

from types import SimpleNamespace

import numpy as np
from sensor_msgs.msg import CameraInfo

from realsense_yolo_3d.detector_node import RealSenseYolo3DNode


class GeometryFixture(RealSenseYolo3DNode):
    """Minimal object accepted by the node's side-effect-free geometry methods."""

    def __init__(self):
        """Provide parameters and color-camera intrinsics."""
        self.parameters = {
            'depth_roi_ratio': 1.0,
            'depth_roi_min_size': 1,
            'min_depth': 0.1,
            'max_depth': 5.0,
        }
        self.camera_info = CameraInfo()
        self.camera_info.k = [600.0, 0.0, 320.0,
                              0.0, 600.0, 240.0,
                              0.0, 0.0, 1.0]

    def get_parameter(self, name):
        """Mimic the small rclpy parameter API surface under test."""
        return SimpleNamespace(value=self.parameters[name])


def test_depth_encoding_scales():
    """Convert RealSense uint16 millimetres but retain float metres."""
    assert RealSenseYolo3DNode._depth_scale('16UC1') == 0.001
    assert RealSenseYolo3DNode._depth_scale('32FC1') == 1.0
    assert RealSenseYolo3DNode._depth_scale('rgb8') is None


def test_depth_roi_uses_median_and_ignores_invalid_values():
    """Discard holes/non-finite samples and reject isolated outliers."""
    fixture = GeometryFixture()
    depth = np.array([
        [0.0, np.nan, np.inf],
        [1000.0, 1100.0, 5000.0],
        [900.0, 1000.0, 1000.0],
    ], dtype=np.float64)
    value = RealSenseYolo3DNode.get_valid_depth(
        fixture, depth, '16UC1', (0.0, 0.0, 2.0, 2.0))
    assert value == 1.0


def test_pixel_to_3d_uses_color_intrinsics():
    """Deproject right/down pixels to positive optical X/Y coordinates."""
    fixture = GeometryFixture()
    xyz = RealSenseYolo3DNode.pixel_to_3d(
        fixture, u=380.0, v=270.0, z=2.0)
    assert xyz == (0.2, 0.1, 2.0)
