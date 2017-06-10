#! /bin/bash
cd ~/workspace/Autoware/ros/
./run

sleep 3

roslaunch razor_imu_9dof razor-pub.launch&
rosrun rosserial_python serial_node.py _port:=/dev/ArduinoNano&
roslaunch realsense_camera r200_nodelet_rgbd.launch  &
source ~/workspace/catkin_ws/devel/setup.sh
roslaunch twist_cmd_converter twist_cmd_converter.launch &
roslaunch tf_publisher tf_local.launch &
