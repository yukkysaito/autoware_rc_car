#! /bin/bash
cd ~/Autoware/ros/
source ./devel/setup.sh
./run

sleep 3

source ~/workspace/autoware_rc_car/catkin_ws/devel/setup.sh
roslaunch demo_launch demo.launch 
