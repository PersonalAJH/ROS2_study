#include "rclcpp/rclcpp.hpp"
// #include <sensor_msgs/msg/JointState.h>
// #include <sensor_msgs/msg/Imu.hpp>

// #include <torooc_msgs/HeaderedString.h>
// #include <std_msgs/String.h>
#include "std_msgs/msg/string.hpp"
// #include "geometry_msgs/msg/vector3.hpp"
//#include <tf/transform_datatypes.h>
#include <vector>
#include <list>
#include <queue>


using namespace std;

class MsgCallback {
public:
	list<string> 	storage_list;
    queue<string>   storage_queue;
    vector<string>  storage_vector;

	void callback(const std_msgs::msg::String::SharedPtr msg) {
    	storage_list.push_back(msg->data);
        storage_queue.push(msg->data);
        storage_vector.push_back(msg->data);
	}
};


class TopicManager{
public:
  TopicManager(std::shared_ptr<rclcpp::Node> node) 
    : node_(node){
    // Initialize Publishers

    // Initialize Subscribers
    cmdSub = node_->create_subscription<std_msgs::msg::String>(
      "/robot/action", 10, std::bind(&MsgCallback::callback, &topicCB, std::placeholders::_1));

    Pub1 = node_->create_publisher<std_msgs::msg::String>("/robot/pub1", 10);
    Pub2 = node_->create_publisher<std_msgs::msg::String>("/robot/pub2", 10);
    Pub3 = node_->create_publisher<std_msgs::msg::String>("/robot/pub3", 10);
  }

  bool getActionIfExist(string &msg){
    return topicCB.getIfExist(msg);
  }


  void publish1(Vector3f status){
    auto topic_msg1 = std_msgs::msg::String();
    topic_msg1.data = std::to_string(status(0));
    Pub1->publish(topic_msg1);

  }

  void publish2(string event){
    auto topic_msg2 = std_msgs::msg::String();
    topic_msg2.data = event;
    Pub2->publish(topic_msg3);
  }

  void publish3() {
    auto topic_msg3 = std_msgs::msg::String();
    Pub3->publish(topic_msg3);
  }



private:
  // Declare Publishers
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr Pub1, Pub2, Pub3;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr cmdSub;


  MsgCallback topicCB;

  std::shared_ptr<rclcpp::Node> node_;
};