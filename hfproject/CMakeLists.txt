cmake_minimum_required(VERSION 3.8)
project(hfproject)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


add_definitions(-D_LINUX)
add_definitions(-DNON_MATLAB_PARSING)
add_definitions(-DMAX_EXT_API_CONNECTIONS=255)
add_definitions(-DEXPORT_FLAG)




# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)


find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

include_directories(
	${ament_INCLUDE_DIRS}
 	${ament_INCLUDE_DIRS}/message
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  # 현재
	${PROJECT_SOURCE_DIR}/src
)


add_library(testLib
	src/ParameterGetter.cpp
  # 라이브러리에 추가해야 할 파일들
  # ${CMAKE_CURRENT_SOURCE_DIR}/Comm.cpp
)

add_executable(human_following_node
	src/HumanFollowingNode.cpp
)


ament_target_dependencies(testLib
 rclcpp sensor_msgs std_msgs geometry_msgs
)


ament_target_dependencies(human_following_node
 rclcpp sensor_msgs std_msgs geometry_msgs
)


target_link_libraries(human_following_node
  testLib
  # 외부 라이브러리가 필요할 때의 예시 
  # ${CMAKE_CURRENT_SOURCE_DIR}/include/libjsoncpp.a
  ${ament_LIBRARIES}
  rt
)


install(DIRECTORY launch param
    DESTINATION share/${PROJECT_NAME}
)


#install(TARGETS human_following_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)

install(TARGETS human_following_node
  DESTINATION lib/${PROJECT_NAME})



## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

install(TARGETS testLib
    DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)









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
