cmake_minimum_required(VERSION 3.5)
project(msg_srv_action_interface_example)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)


##===============================================
#Declare ROS messages, service and actions 
##===============================================
set(msg_files "msg/ArithmeticArgument.msg")
set(srv_files "srv/ArithmeticOperator.srv")
set(action_files "action/ArithmeticChecker.action")

rosidl_generate_interfaces(${PROJECT_NAME}
${msg_files}
${srv_files}
${action_files}
DEPENDENCIES builtin_interfaces
)


##=================================
#MAcro for ament package
##=================================

ament_export_dependecies(rosidl_default_runtime)
ament_package()
