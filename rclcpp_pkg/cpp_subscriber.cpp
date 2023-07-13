#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
// #include "geometry_msgs/Twist.hpp"

using std::placeholder::_1;

class HelloworldSubscriber :public rclcpp::Node
{
public:
HelloworldSubscriber() : Node("Helloworld_subscriber"){
    auto qos_profile = rclcpp::Qos(rclcpp::KeepLast(10));
    helloworld_subscriber_ = this->create_subscription<std_msgs::msg::String>("helloworld",qos_profile,std::bind(&HelloworldSubscriber::subscribe_topic_message, this, _1));
}

private:
void subscribe_topic_message(const std_msgs::msg::String::SharedPtr msg) const{
    RCLCPP_INFO(this->get_logger(), "Received message : '%s' ",msg->data.c_str());
}
rclcpp::Subscription<std_msgs::msg::String>::SharedPtr helloworld_subscriber_;

};

int main(int argc, char *argv[]){
    rclcpp::init(argc,argv);
    auto node = std::make_shared<HelloworldSubscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
