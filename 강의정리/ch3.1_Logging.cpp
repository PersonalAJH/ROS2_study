/*
로그 
ROS2에서 로그를 남기기 위해 logger 와 logging(rclcpp,rclpy) 라이브러리를 사용함
로그가 저장되는 디렉토리는 
ls ~/.ros/log 파일에 생성됨 (Foxt 버전에는 로그가 저장되는 경로를 변경할 수 없지만 Galatic 부터는 변경 가능)

로그 수준은 총 5개로 DEBUG, INFO, WARN, ERROR, FATAL 이다. 


RCLCPP 에서 로그를 출력하기 위해서 제공하는 매크로 함수는
http://docs.ros2.org/latest/api/rclcpp/logging_8hpp.html
http://docs.ros2.org/latest/api/recutils/logging__macros_8h.html 을 확인

예를 들어서 
&{SEVERITY} 에는 DEBUG, INFO, WARN, ERROR, FATAL을 넣으면 됨

RCLCPP_&{SEVERITY} 는 Formatting을 지원하는 출력함수 
RCLCPP_&{SEVERITY}_ONCE 딱 한번만 출력되는 함수
RCLCPP_&{SEVERITY}_SKIPFIRST : 두번째 호출부터 출력되는 함수 등이 있다. 


*/

//  source code 중 
    

#include "rclcpp/rclcpp.hpp"

class JHNode : public rclcpp::Node {
public:
  JHNode() : Node("jh_node") {
    RCLCPP_DEBUG(this->get_logger(), "Initializing JHNode");
  }


  bool debug_function(int i) {
    // 사용자 정의 디버그 함수
    // 이 함수가 true를 반환하면 로깅 메시지가 출력됩니다.
    return (i % 3 == 0); // true
  }

  void doSomething() {
    //RCLCPP_DEBUG_FUNCTION 은 이 함수의 이름이 직접 나오는 로깅 그래서 어떤 일을 하면 로그에 그 함수의 이름이 생김
    RCLCPP_DEBUG_FUNCTION(this->get_logger());
    
    //debug function이 있을 때
    int i = 12; // 예시로 i를 12로 설정
    RCLCPP_DEBUG_FUNCTION(
        get_logger(),
        [&i]() -> bool {return debug_function_to_evaluate(i);},
        "Count divides into 12 (function evaluated to true)");
  }
};

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<JHNode>();
  node->doSomething();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
