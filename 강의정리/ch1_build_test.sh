source /opt/ros/foxy/setup.bash
mkdir -p ~/robot_ws/src     # p option is create automatically in interval folder if they are not exist
cd ~/robot_ws           
colcon build --symlink-install