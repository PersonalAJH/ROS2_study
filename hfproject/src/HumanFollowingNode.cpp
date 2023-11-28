/*
 * Copyright (c) 2023, Junghwan
 * All rights reserved.
 *
 **/
// #include <ros/ros.h>


// #include <std_msgs/String.h>
#include "stdafx.h"
#include <memory>
#include <utility>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/time_source.hpp"
#include "std_msgs/msg/header.hpp"
#include "std_msgs/msg/string.hpp"

#include "HumanFollowingNode.h"

using namespace std;

HumanFollowingNode::HumanFollowingNode(shared_ptr<Node> node, int robot_version)
: node_(node), robot_version_(robot_version) {
    printf("initial code \n");
}

void HumanFollowingNode::run()
{
	//something to run
	printf("running \n");
}

int main(int argc, char** argv)
{
	//node 설정

	rclcpp::init(argc, argv);
	auto node = rclcpp::Node::make_shared("Human_following");
	
	 HumanFollowingNode robot(node, 1);

	rclcpp::Rate loop_rate(25); //40ms

	node->declare_parameter("robot_version", "default_name");
	std::string robot_version_;
	node->get_parameter("robot_version", robot_version_);

	if(robot_version_ == "robot1"){
		while (rclcpp::ok()) {
				rclcpp::spin_some(node);
				robot.run();
				loop_rate.sleep(); // 지정된 주기마다 루프를 실행
		}
		rclcpp::shutdown();
	}

	//음.. ctrl C 나 이런식으로 노드를 종료할 때 마무리되는걸 작성하면됨 
	// 만약에 로봇이 계속 움직이고 있다면 멈추는 코드가 있으면 됨

	return 0;

}

