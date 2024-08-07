#ifndef ROBOT_DRIVER_HPP
#define ROBOT_DRIVER_HPP

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "std_msgs/msg/string.hpp"
#include "my_interface/srv/find_closest_wall.hpp"

using namespace std::chrono_literals;


class RobotDriver : public rclcpp::Node
{
  public:
    RobotDriver();

  private:
    void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg);
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr vel_pub;
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_sub;
    rclcpp::Client<my_interface::srv::FindClosestWall>::SharedPtr client;
    std::shared_ptr<my_interface::srv::FindClosestWall::Request> request;
    geometry_msgs::msg::Twist twist;
    
};


#endif
