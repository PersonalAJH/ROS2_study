from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    # 같은 패키지 내의 2개의 노드
    package_1_node_1 = Node(
        package='package_1',
        executable='ex_node_1',
        name='junghwan1',
        output='screen',
        emulate_tty=True
    )  

    package_1_node_2 = Node(
        package='package_1',
        executable='ex_node_2',
        name='junghwan2',
        output='screen',
        emulate_tty=False,
        respawn=True  # 비정상 종료 시 노드 자동 재시작 활성화
    )  

    # 다른 패키지
    package_2_node_1 = Node(
        package='package_2',
        executable='ex_node_3',
        name='junghwan3',
        output='screen',
        emulate_tty=True,
        parameters=[
            {'parameter1': False},
            {'parameter2': 640},
            {'parameter3': '/dev/video0'},
        ],
        condition=IfCondition(EnvironmentVariable('LAUNCH_EXAMPLE', default_value='false'))     # export LAUNCH_EXAMPLE=true   이런식으로 어떤 환경변수 값들에 따라서 설정이 변경됨
    )

    ld.add_action(package_1_node_1)
    ld.add_action(package_1_node_2)
    ld.add_action(package_2_node_1)
    return ld





    # ROS1 에서도 respawn 도 가능함
    # <launch>
    # <node name="example_node"
    #       pkg="example_package"
    #       type="example_node"
    #       respawn="true"  # 비정상 종료 시 노드 자동 재시작 활성화
    #       output="screen"/>
    # </launch>

