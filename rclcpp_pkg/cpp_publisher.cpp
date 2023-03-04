#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
// #include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals; // 나중에 auto day = 14d; auto twoDays = 48h;  week = 24h*7; auto duration  = 5ms; 이런식으로 이용가능

class cppPublisher : public rclcpp::Node
{
    public:
    cppPublisher() : Node("helloworld_publisher"), count(0)
    {
        auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        cpp_publisher_ = this->create_puiblisher<std_msgs::msg::String>("hellowworld",qos_profile);
        timer_ = this->create_wall_timer(1s, std::bind(&cppPublisher::publish_helloworld_msg, this));
    }

    private:
    //현재 나와있는 예제는 member function 방식으로 callback 함수가 짜여 있는데 lambda 방식으로도 가능 
    void publish_helloworld_msg(){
        auto msg = std_msgs::msg::String();
        msg.data = "Hello World: " + std::to_string(count++);
        RCLCPP_INFO(this->get_logger(), "Published message : '%s'",msg,data.c_str());
        printf("test \n");
        helloworld_publisher->publish(msg);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharePtr cpp_publisher_;
    sizae_t count_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<cppPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}








/*
#include "rclcpp/rclcpp.hpp"
using namespace std::chrono_literals;
void timer_callback() {
    printf("call back funtion\n");
}

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("cpp_publisher");
    
    auto duration = 1s;
    auto timer = node->create_wall_timer(duration, timer_callback);
    
    rclcpp::spin(node);
    rclcpp::shutdown();
    
    return 0;
}
*/