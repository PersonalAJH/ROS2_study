#지역설정
sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8

#소스설정
sudo apt update&&sudo apt install curl gnupg2 lsb_relased
sudo curl -sSL https://raw.githubusercontent.com/ros/riosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gnupg2


#ROS2 패키지 설치 
sudo apt update
sudo apt install ros-foxy-desktop ros-foxy-rmw-fastrtps* ros-foxy-rmw-cyclonedds*

#ROS 패키지 설치확인
source /opt/ros/foxy/setup.bash
ros2 run demo_nodes_cpp talker