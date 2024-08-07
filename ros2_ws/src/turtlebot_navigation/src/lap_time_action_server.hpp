#ifndef LAP_TIME_ACTION_SERVER_HPP
#define LAP_TIME_ACTION_SERVER_HPP

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <optional>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "std_msgs/msg/string.hpp"
#include "my_interface/action/measure_lap_time.hpp"

using namespace std::chrono_literals;


class LapTimeActionServer : public rclcpp::Node
{
  public:
    using MeasureLapTime = my_interface::action::MeasureLapTime;
    using GoalHandleMeasureLapTime = rclcpp_action::ServerGoalHandle<MeasureLapTime>;
    LapTimeActionServer();

  private:
    void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg);
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg);
    void execute_callback(const std::shared_ptr<GoalHandleMeasureLapTime> goal_handle);
    void handle_accepted(const std::shared_ptr<GoalHandleMeasureLapTime> goal_handle);
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp_action::Server<MeasureLapTime>::SharedPtr action_server;
    rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const MeasureLapTime::Goal> goal);
    rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleMeasureLapTime> goal_handle);
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscriber;
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_subscriber;
    geometry_msgs::msg::Twist twist;
    std::optional<double> start_position_x;
    std::optional<double> start_position_y;
    double current_position_x;
    double current_position_y;
    std::chrono::steady_clock::time_point start_time;
    std::chrono::steady_clock::time_point current_time;
    std::vector<double> lap_times;
    bool start_lap;
    int lap_count;
    bool new_lap;
    
};


#endif
