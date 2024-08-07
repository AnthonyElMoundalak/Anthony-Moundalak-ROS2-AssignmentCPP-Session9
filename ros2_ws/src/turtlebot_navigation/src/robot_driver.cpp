#include "robot_driver.hpp"

using namespace std::chrono_literals;

RobotDriver::RobotDriver():Node("robot_driver"){
  client = this->create_client<my_interface::srv::FindClosestWall>("find_closest_wall");
  while (!client->wait_for_service(1s))
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
  }
  request = std::make_shared<my_interface::srv::FindClosestWall::Request>();

  // Initialize subscriber to the /scan topic and publisher to the /cmd_vel topic
  scan_sub = this->create_subscription<sensor_msgs::msg::LaserScan>("/scan", 10, std::bind(&RobotDriver::scan_callback, this, std::placeholders::_1));
  vel_pub = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
  
  twist = geometry_msgs::msg::Twist();

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Waiting for FindClosestWall service...");

  auto future = client->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) ==
    rclcpp::FutureReturnCode::SUCCESS)
  {
    auto response = future.get();
    if (response->success) {
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Arrived to the closest wall...");
      scan_sub = this->create_subscription<sensor_msgs::msg::LaserScan>("/scan", 10, std::bind(&RobotDriver::scan_callback, this, std::placeholders::_1));
    } else {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Does not arrived to the wall...");
    }
  }
  
}


void RobotDriver::scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg){
  if (msg->ranges[0] < 0.5){
    twist.linear.x = 0.0;
    twist.angular.z = -2.0;
  }
  else if (msg->ranges[25] < 0.55){
    twist.linear.x = 0.0;
    twist.angular.z = -0.3;
  }
  else{
    twist.linear.x = 0.2;
    twist.angular.z = 0.0;
  }
  vel_pub->publish(twist);
}


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto robot_driver = std::make_shared<RobotDriver>();
  rclcpp::spin(robot_driver);
  rclcpp::shutdown();
  return 0;
}
