cmake_minimum_required(VERSION 3.8)
project(turtlebot_navigation)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(my_interface REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(robot_driver src/robot_driver.cpp)
add_executable(wall_finder_service src/wall_finder_service.cpp)
add_executable(lap_time_action_server src/lap_time_action_server.cpp)
add_executable(lap_time_action_client src/lap_time_action_client.cpp)

ament_target_dependencies(
  robot_driver
  rclcpp
  my_interface
  geometry_msgs
  sensor_msgs
  # rosdl_default_runtime
  # rosdl_typesupport_cpp
  )

ament_target_dependencies(
  wall_finder_service
  rclcpp
  my_interface
  geometry_msgs
  sensor_msgs
  # rosdl_default_runtime
  # rosdl_typesupport_cpp
  )

ament_target_dependencies(
  lap_time_action_server
  rclcpp
  rclcpp_action
  my_interface
  geometry_msgs
  sensor_msgs
  nav_msgs
  # rosdl_default_runtime
  # rosdl_typesupport_cpp
)

ament_target_dependencies(
  lap_time_action_client
  rclcpp
  rclcpp_action
  my_interface
  # rosdl_default_runtime
  # rosdl_typesupport_cpp
)

include_directories(include
${rclcpp_INCLUDE_DIRS}
${rclcpp_action_INCLUDE_DIRS}
${my_interface_INCLUDE_DIRS}
${geometry_msgs_INCLUDE_DIRS}
${sensor_msgs_INCLUDE_DIRS}
${nav_msgs_INCLUDE_DIRS}
# ${rosdl_default_runtime_INCLUDE_DIRS}
# ${rosdl_typesupport_cpp_INCLUDE_DIRS}
)

install(TARGETS robot_driver wall_finder_service lap_time_action_server lap_time_action_client
DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)


ament_package()
