import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from std_msgs.msg import String
# from geometry_msgs.msg import Twist

class Example_publisher(Node):
    
    def __init__(self):
        super().__init__('ex_publisher')
        qos_profile = QoSProfile(depth=10)
        self.ex_publisher = self.create_publisher(String, 'helloworld', qos_profile)
        self.timer= self.create_timer(1,self.publish_helloworld_msg)
        self.count = 0

    def publish_hello_msg(self):
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
    