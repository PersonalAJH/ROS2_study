
#if 1 


// Executor 사용 예제
int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>();

    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();  // 멀티스레드로 콜백 처리 시작

    rclcpp::shutdown();
    return 0;
}

#else if


// 이 예제에서 보면 spin 과 spin_some(ROS1의 spin once와 비슷)의 차이를 확인할 수 있는데 spin 은 
int main(int argc, char **argv){

    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("parking_node");
    rclcpp::WallRate loop_rate(100);

    Parking_Node parking_node(node);
    parking_node.setup();

    while(rclcpp::ok()){

        printf("test \n");

        // rclcpp::spin(node);  -> 이러면 subscribe 가 들어오기 전까지(정확히는 callback function) 이곳에서 멈춤
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }


    return 0;
}




#else



#endif
