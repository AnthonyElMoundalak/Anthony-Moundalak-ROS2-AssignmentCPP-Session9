#include "wall_finder_service.hpp"
#include <algorithm> 
#include <chrono>


using namespace std::chrono_literals;

WallFinderService::WallFinderService():Node("wall_finder_service"){
    
    // Create a service server for FindClosestWall
    srv = this->create_service<my_interface::srv::FindClosestWall>("find_closest_wall", std::bind(&WallFinderService::find_closest_wall_callback, this, std::placeholders::_1, std::placeholders::_2));
    
    // Initialize publisher to the /cmd_vel topic and subscriber to the /scan topic
    scan_sub = this->create_subscription<sensor_msgs::msg::LaserScan>("/scan", 10, std::bind(&WallFinderService::scan_callback, this, std::placeholders::_1));
    vel_pub = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    
    twist = geometry_msgs::msg::Twist();

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Starting service...");
}

void WallFinderService::find_closest_wall_callback(const std::shared_ptr<my_interface::srv::FindClosestWall::Request> request, std::shared_ptr<my_interface::srv::FindClosestWall::Response> response){
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Finding closest wall...");
    twist.linear.x = 0.2;
    vel_pub->publish(twist);

    timer_ = this->create_wall_timer(100ms, std::bind(&WallFinderService::check_closest_distance, this));

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Moving forward...");
    
    // Send success response

    response->success = true;
}

void WallFinderService::check_closest_distance(){
    if(closest_wall_distance < 0.5){
        twist.linear.x = 0.0;
        vel_pub->publish(twist);
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Arrive to the wall...");
        timer_->cancel();
    }
    else{
        twist.linear.x = 0.2;
        vel_pub->publish(twist);
        // RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Min distance: %.2f", closest_wall_distance);
    }
}

void WallFinderService::scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg){
    // Find the minimum distance to a wall in the laser scan data
    closest_wall_distance = *std::min_element(msg->ranges.begin(), msg->ranges.end());
}


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto wall_finder_service = std::make_shared<WallFinderService>();
  rclcpp::spin(wall_finder_service);
  rclcpp::shutdown();
  return 0;
}
