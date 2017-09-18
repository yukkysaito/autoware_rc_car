#generic install
sudo apt-get install git build-essential emacs

#ros install
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
sudo apt-get update
sudo apt-get install ros-kinetic-desktop-full
sudo rosdep init
rosdep update
echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
source ~/.bashrc
sudo apt-get install python-rosinstall

# autoware install
sudo apt-get install ros-kinetic-desktop-full ros-kinetic-nmea-msgs ros-kinetic-nmea-navsat-driver ros-kinetic-sound-play ros-kinetic-jsk-visualization ros-kinetic-grid-map ros-kinetic-gps-common
sudo apt-get install ros-kinetic-controller-manager ros-kinetic-ros-control ros-kinetic-ros-controllers ros-kinetic-gazebo-ros-control ros-kinetic-joystick-drivers
sudo apt-get install libnlopt-dev freeglut3-dev qtbase5-dev libqt5opengl5-dev libssh2-1-dev libarmadillo-dev libpcap-dev gksu libgl1-mesa-dev libglew-dev
cd $HOME
git clone https://github.com/CPFL/Autoware.git
cd ~/Autoware/ros/src
source /opt/ros/indigo/setup.bash
catkin_init_workspace
cd ../
./catkin_make_release

# ros-arduino install
sudo apt-get install arduino
sudo apt-get install ros-kinetic-rosserial-arduino
sudo apt-get install ros-kinetic-rosserial
mkdir -p $HOME/sketchbook/libraries
cd $HOME/sketchbook/libraries
rm -rf ros_lib
rosrun rosserial_arduino make_libraries.py .

# imu-ros install
# http://wiki.ros.org/razor_imu_9dof
sudo apt-get install python-wxgtk3.0
sudo apt-get install ros-kinetic-razor-imu-9dof
roscd razor_imu_9dof/config
cp razor.yaml my_razor.yaml
#in my_razor.yaml
# port: /dev/ttyUSB0 -> port: /dev/IMU
sudo apt-get install ros-kinetic-rviz-imu-plugin

#intel realsense r200
#http://wiki.ros.org/action/fullsearch/RealSense
wget -O enable_kernel_sources.sh http://bit.ly/en_krnl_src
bash ./enable_kernel_sources.sh

# structure sensor-ros install
sudo apt-get install -y g++ python libusb-1.0-0-dev freeglut3-dev doxygen graphviz default-jdk
sudo apt-get install ros-kinetic-openni2_camera ros-kinetic-openni2_launch

# vsec install
echo "Installing VSEC"
sudo apt-get install qtcreator qt-sdk libudev-dev libqt5serialport5-dev
git clone https://github.com/vedderb/bldc-tool
cd bldc-tool
qmake -qt=qt5
make clean && make

sudo apt-get install ros-kinetic-ackermann-msgs ros-kinetic-serial
