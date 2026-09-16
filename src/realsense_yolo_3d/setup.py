from glob import glob
from setuptools import find_packages, setup

package_name = 'realsense_yolo_3d'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
         ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='msms',
    maintainer_email='msms@todo.todo',
    description='YOLO and RealSense aligned-depth 3D detector.',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'detector_node = realsense_yolo_3d.detector_node:main',
        ],
    },
)
