import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from std_msgs.msg import String

class Example_Subscriber(Node):

    def __init__(self):
        super().__init__('Helloworld_subscriber')
        qos_profile = QoSProfile(dept = 10)
        self.helloworld_subscriber = self.create_subscription(      #메세지 타입은 String, 노드 이름은 ex_subscriber 콜백함수는 subscribe_topic_message
            'String',
            'ex_subscriber',
            self.subscribe_topic_message,
            qos_profile
        )

    def subscribe_topic_message(self.msg):
        self.get_logger().info('Received message: {0}'.format(msg.data))

def main(args = None):
    rclpy.init(args=args)
    node = Example_Subscriber()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('key board inteurppptptptpptpttpttt ')
    finally:
        node.destory_node()
        rclpy.shutdown()

if __name__== '__main__':
    main()