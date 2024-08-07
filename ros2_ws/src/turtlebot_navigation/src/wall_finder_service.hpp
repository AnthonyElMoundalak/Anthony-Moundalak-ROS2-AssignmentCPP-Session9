#ifndef WALL_FINDER_SERVICE_HPP
#define WALL_FINDER_SERVICE_HPP

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


class WallFinderService : public rclcpp::Node
{
  public:
    WallFinderService();

  private:
    void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg);
    void find_closest_wall_callback(const std::shared_ptr<my_interface::srv::FindClosestWall::Request> request, std::shared_ptr<my_interface::srv::FindClosestWall::Response> response);
    void check_closest_distance();
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr vel_pub;
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_sub;
    rclcpp::Service<my_interface::srv::FindClosestWall>::SharedPtr srv;
    std::shared_ptr<my_interface::srv::FindClosestWall::Response> response;
    geometry_msgs::msg::Twist twist;
    double closest_wall_distance;
    
};


#endif
