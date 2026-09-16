# realsense_yolo_3d

ROS 2 Humble node that combines YOLO RGB detections with aligned RealSense
depth and publishes camera-optical-frame 3D object positions.

The supplied model uses the `C3k2` layer, so Ultralytics 8.2.x is too old.
Install a compatible release before building:

```bash
python3 -m pip install --user -r ~/vision_ws/src/realsense_yolo_3d/requirements.txt
```

```bash
cd ~/vision_ws
source /opt/ros/humble/setup.bash
colcon build --symlink-install
source install/setup.bash
ros2 launch realsense_yolo_3d detector.launch.py
```

Main outputs:

- `/object_detections_3d` (`vision_interfaces/msg/DetectedObjectArray`)
- `/object_detection/image` (`sensor_msgs/msg/Image`)
