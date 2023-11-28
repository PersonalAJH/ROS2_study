// 13장 토픽 프로그래밍(C++)

// 토픽 : 비동기식 단방향 메세지 송수신 방식 
// Publisher 와 Subscirber 간의 통신이다 

// Arguement Class 생성자에서 Node Option 를 인자로 받는데 이 객체를 통해서 context, arguments, intra-process communication, parameter, allocator 같은 Node 생성을 위한 다양한 옵션을 정할 수 있다. 

// Node 선언에서 첫번째 매개변수에는 노드의 이름을 두번째는 Node Option을 명시한다

// 여기서는 Callback 함수를 std::bind 를 사용하지 않고 람다 표현식으로 묶어 놓았다. 
// 람다 표현식 : 람다 표현식은 C++11부터 도입된 기능으로, 익명 함수를 생성하여 사용할 수 있게 해줍니다. 람다는 간단한 함수나 함수 객체를 인라인으로 정의하고 사용할 때 편리하며, 주로 함수 객체를 정의할 필요 없이 함수형 프로그래밍 스타일로 코드를 작성할 때 사용됩니다.



// 굉장히 기본적으로 짠다면

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class JHNode : public rclcpp::Node {
public:
    JHNode() : Node("jh_node") {


        //람다형
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "input_topic",  // Subscribe할 topic 이름
            10,             // QoS 프로파일 (메시지 큐 사이즈)
            [this](const std_msgs::msg::String::SharedPtr msg) {
                // Subscribe한 메시지를 처리하는 콜백 함수
                // Publish할 메시지 생성
                auto output_msg = std::make_shared<std_msgs::msg::String>();
                output_msg->data = "Received: " + msg->data;

                // Publish할 topic 이름
                publisher_->publish(output_msg);
            }
        );

        // std::bind 사용
        subscription2_ = this->create_subscription<std_msgs::msg::String>(
            "input_topic",  // Subscribe할 topic 이름
            10,             // QoS 프로파일 (메시지 큐 사이즈)
            std::bind(&MyNode::myCallback, this, std::placeholders::_1)
        );

        publisher_ = this->create_publisher<std_msgs::msg::String>(
            "output_topic",  // Publish할 topic 이름
            10              // QoS 프로파일 (메시지 큐 사이즈)
        );
    }

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription2_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<JHNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

