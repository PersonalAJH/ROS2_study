#1. 지역설정
sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8

# 2. 소스설정
sudo apt update&&sudo apt install curl gnupg2 lsb-release
sudo curl -sSL https://raw.githubusercontent.com/ros/riosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gnupg2

# 2. ROS 2 GPG key 
sudo apt update && sudo apt install curl
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
멧-
# 3. source list 저장소 추가
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

# 4. ROS2 패키지 설치 
sudo apt update
sudo apt install ros-foxy-desktop ros-foxy-rmw-fastrtps* ros-foxy-rmw-cyclonedds*

# 4.ROS 풀버전 설치
sudo apt install ros-foxy-desktop python3-argcomplete

# 4. Base version install 
sudo apt install ros-foxy-ros-base python3-argcomplete

#if fail to undetermined error ip 
# sudo apt update --fix-missing && sudo apt upgrade

#ROS 패키지 설치확인
source /opt/ros/foxy/setup.bash
ros2 run demo_nodes_cpp talker