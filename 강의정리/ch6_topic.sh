#토픽 리스트 확인
ros2 topic list -t

#토픽 정보 확인
ros2 topic info /turtle1/cmd_vel

#토픽 에코
ros2 topic echo /turtle1/cmd_vel

# 토픽 대역폭 확인
ros2 topic bw /turtle1/cmd_vel

# 토픽 주기 확인
ros2 topic hz /turtle1/cmd_vel

#토픽 지연 시간 확인
ros2 topic delay /turtle1/cmd_vel

# 토픽 직접 publish
#ros2 topic pub <topic_name> <msg_type> "<args>"
ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x:2.0,y:0.0,z:0.0}, angular: {x:0.0, y:0.0, z:1.8}}"

#내가 쓰는 방법은 --once 이후부분을 yaml 파일로 대체하여 사용
# --once 대신 --rate 1 옵션을 추가하여 지속적으로 토픽을 쏴줄수도 있다.


#토픽 서비스 액션 비교

#           토픽      서비스      액션
# 연속성      연속성      일회성      복합
# 방향성      단방향      양방향      양방향
# 동기성      비동기      동기        동기 + 비동기
# 다자간      가능        1:1         1:1
# 노드        Publisher  Server       Server
#             Sublisher   Client      Client
test
