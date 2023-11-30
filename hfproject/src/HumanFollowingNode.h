/*
 * Copyright (c) 2023, Junghwan.
 * All rights reserved.
 *
 */

#include <iostream>
#include <map>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "MessageManager/TopicManager.hpp"

using namespace std;

class HumanFollowingNode{
public:
	HumanFollowingNode(TopicManager *tm, int robot_version);
	void run();

private:
	std::shared_ptr<rclcpp::Node> node_;
    int                 robot_version_;
	TopicManager			*TpManager;
};

