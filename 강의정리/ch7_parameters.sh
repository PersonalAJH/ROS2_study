ros2 run turtlesim turtlesim_node
ros2 run turtlesim turtle_teleop_key


# 파라미터 목록 확인 명령어
ros2 param list

#ros2 param describe 노드명 파라미터
ros2 param describe /turtlesim background_b

#파라미터 읽기
# ros2 param get <node_name> <parameter_name>
ros2 param get /turtlesim background_b

#파라미터 쓰기
# ros2 param set <node_name> <parameter_name> <value>
ros2 param get /turtlesim background_b 148

#파라미터 저장 (yaml 형식으로 저장)
ros2 param dump /turtlesim

#파라미터 삭제
ros2 param delete /turtlesim background_b