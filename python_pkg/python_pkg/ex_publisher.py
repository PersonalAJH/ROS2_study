import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile        #QoS는 ROS의 퍼블리셔 설정을 위한 라이브러리
from std_msgs.msg import String
# from geometry_msgs.msg import Twist

class Example_publisher(Node):
    
    def __init__(self):
        super().__init__('ex_publisher')
        qos_profile = QoSProfile(depth=10)      # Publisher 의 buffer를 10개로 지정-> 혹시나 통신상태가 원활하지 못할 경우
        self.ex_publisher = self.create_publisher(String, 'helloworld', qos_profile)
        self.timer= self.create_timer(1,self.publish_helloworld_msg)
        self.count = 0

    def publish_helloworld_msg(self):
        msg = String()
        msg.data = 'hello world " {0}'.format(self.count)
        self.ex_publisher.publish(msg)
        self.get_logger().info('Published message: {0}'.format(msg.data))
        self.count += 1


def main(args = None):
    rclpy.init(args = args)
    node = Example_publisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Keyboard Interrupt (SIGINT)')
    finally:
        node.destory_node()
        rclpy.shutdown()

if __name__ =='__main__':
    main()
    