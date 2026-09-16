from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    arguments = [
        DeclareLaunchArgument(
            'model_path', default_value='/home/msms/Downloads/best.pt'),
        DeclareLaunchArgument('confidence_threshold', default_value='0.5'),
        DeclareLaunchArgument(
            'color_topic',
            default_value='/camera/camera/color/image_raw'),
        DeclareLaunchArgument(
            'depth_topic',
            default_value='/camera/camera/aligned_depth_to_color/image_raw'),
        DeclareLaunchArgument(
            'camera_info_topic',
            default_value='/camera/camera/color/camera_info'),
        DeclareLaunchArgument('min_depth', default_value='0.1'),
        DeclareLaunchArgument('max_depth', default_value='5.0'),
    ]

    detector = Node(
        package='realsense_yolo_3d',
        executable='detector_node',
        name='realsense_yolo_3d',
        output='screen',
        parameters=[{
            'model_path': LaunchConfiguration('model_path'),
            'confidence_threshold': LaunchConfiguration(
                'confidence_threshold'),
            'color_topic': LaunchConfiguration('color_topic'),
            'depth_topic': LaunchConfiguration('depth_topic'),
            'camera_info_topic': LaunchConfiguration('camera_info_topic'),
            'min_depth': LaunchConfiguration('min_depth'),
            'max_depth': LaunchConfiguration('max_depth'),
        }],
    )
    return LaunchDescription(arguments + [detector])
