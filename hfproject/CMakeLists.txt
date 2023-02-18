cmake_minimum_required(VERSION 3.5)
project(hfproject)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

#Wall 옵션은 컴파일중에 warning을 띄울껀지에 대한 옵션
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

# customize  파일이 있을경우
#set(msg_files
#  "msg/Count.msg"
#  )

#set(srv_files
#  "srv/Count.srv"
#  )

#set(action_files
#  "action/Count.action"
#  )


# include directory들 설정
#include_directories(
#  include
#)

#set은 기본 CMAKE와 같이 =과 같은 설정
#set(PUBLISHER_NODE_NAME publisher)
#set(SUBSCRIBER_NODE_NAME subscriber)
#set(dependencies
#  "examples_msgs"
#  "rclcpp"
#)

add_executable(${PUBLISHER_NODE_NAME} src/publisher/main.cpp src/publisher/counter.cpp)
ament_target_dependencies(${PUBLISHER_NODE_NAME} ${dependencies})

add_executable(${SUBSCRIBER_NODE_NAME} src/subscriber/main.cpp src/subscriber/observer.cpp)
ament_target_dependencies(${SUBSCRIBER_NODE_NAME} ${dependencies})





if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
