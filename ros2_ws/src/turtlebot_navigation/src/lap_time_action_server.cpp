#include "lap_time_action_server.hpp"

using namespace std::chrono_literals;

LapTimeActionServer::LapTimeActionServer():Node("lap_time_action_server"){
    action_server = rclcpp_action::create_server<MeasureLapTime>(
        this, 
        "MeasureLapTime", 
        std::bind(&LapTimeActionServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
        std::bind(&LapTimeActionServer::handle_cancel, this, std::placeholders::_1),
        std::bind(&LapTimeActionServer::handle_accepted, this, std::placeholders::_1)
    );
    
    odom_subscriber = this->create_subscription<nav_msgs::msg::Odometry>("/odom", 10, std::bind(&LapTimeActionServer::odom_callback, this, std::placeholders::_1));
    scan_subscriber = this->create_subscription<sensor_msgs::msg::LaserScan>("/scan", 10, std::bind(&LapTimeActionServer::scan_callback, this, std::placeholders::_1));

    start_lap = false;
    lap_count = 0;
    new_lap = false;
}

rclcpp_action::GoalResponse LapTimeActionServer::handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const MeasureLapTime::Goal> goal)
{
    RCLCPP_INFO(this->get_logger(), "Received request to measure lap time");
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse LapTimeActionServer::handle_cancel(
    const std::shared_ptr<GoalHandleMeasureLapTime> goal_handle)
{
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    return rclcpp_action::CancelResponse::ACCEPT;
}

void LapTimeActionServer::handle_accepted(const std::shared_ptr<GoalHandleMeasureLapTime> goal_handle){
    using namespace std::placeholders;
    std::thread{std::bind(&LapTimeActionServer::execute_callback, this, _1), goal_handle}.detach();
}


void LapTimeActionServer::execute_callback(const std::shared_ptr<GoalHandleMeasureLapTime> goal_handle){

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Received lap time goal");

    rclcpp::Rate rate(10);

    while(!start_lap){
        // rclcpp::spin_some(this->get_node_base_interface());
        // rclcpp::sleep_for(10ms);
        // if(!start_lap){
        //     RCLCPP_INFO(this->get_logger(), "fffffffffffffffffff");
        // }
        // else{
        //     RCLCPP_INFO(this->get_logger(), "ttttttttttttttttttt");
        // }

        // std::this_thread::sleep_for(std::chrono::microseconds(100));

        rate.sleep();
    }

    while(!start_position_x.has_value() || !start_position_y.has_value()){
        // rclcpp::spin_some(shared_from_this());
        // rclcpp::sleep_for(10ms);
        start_position_x = current_position_x;
        start_position_y = current_position_y;
        start_time = std::chrono::steady_clock::now();
        // RCLCPP_INFO(this->get_logger(), "Odometry callback: x = %.2f, y = %.2f", current_position_x, current_position_y);

        rate.sleep();

        // std::this_thread::sleep_for(std::chrono::microseconds(100));
    }

    RCLCPP_INFO(this->get_logger(), "x = %.2f, y = %.2f", start_position_x.value(), start_position_y.value());

    auto feedback_msg = std::make_shared<MeasureLapTime::Feedback>();
    start_time = std::chrono::steady_clock::now();

    while(rclcpp::ok()){
        // rclcpp::spin_some(shared_from_this());

        double elapsed_time = std::chrono::duration<double>(std::chrono::steady_clock::now() - start_time).count();
        feedback_msg->elapsed_time = static_cast<float>(elapsed_time);
        goal_handle->publish_feedback(feedback_msg);

        if (current_position_y > 1.0) {
            new_lap = true;
        }

        if (current_position_x > 1.0 && current_position_y > -0.01 && current_position_y < 0.01 && new_lap){
            new_lap = false;
            double lap_time = std::chrono::duration<double>(std::chrono::steady_clock::now() - start_time).count();
            lap_times.push_back(lap_time);
            lap_count++;
            RCLCPP_INFO(this->get_logger(), "Lap %d completed in %.2f seconds", lap_count, lap_time);
            start_time = std::chrono::steady_clock::now();
        }

        if (goal_handle->is_canceling()) {
            goal_handle->canceled(std::make_shared<MeasureLapTime::Result>());
            return;
        }

        if (lap_count > 3) {
            break;
        }
        rate.sleep();

        // std::this_thread::sleep_for(std::chrono::microseconds(100));

    }

    auto result = std::make_shared<MeasureLapTime::Result>();
    result->total_time = static_cast<float>(std::accumulate(lap_times.begin(), lap_times.end(), 0.0));
    goal_handle->succeed(result);
    RCLCPP_INFO(this->get_logger(), "Total time for all laps: %.2f seconds", result->total_time);

}


void LapTimeActionServer::scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg){

    if (*std::min_element(msg->ranges.begin(), msg->ranges.end()) < 0.5) {
        start_lap = true;
        // RCLCPP_INFO(this->get_logger(), "trueeeeeee");
    }
    else {
        start_lap = false;
        // RCLCPP_INFO(this->get_logger(), "falseeeeeeeee");
    }
    // RCLCPP_INFO(this->get_logger(), "HHHHHEEEEEERRRREEEEEEEEE");
}


void LapTimeActionServer::odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg){

    current_position_x = msg->pose.pose.position.x;
    current_position_y = msg->pose.pose.position.y;
    current_time = std::chrono::steady_clock::now();
    // RCLCPP_INFO(this->get_logger(), "ODOOOMMMMMMM");
}



int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto lap_time_action_server = std::make_shared<LapTimeActionServer>();
    // rclcpp::executors::MultiThreadedExecutor executor;
    // executor.add_node(lap_time_action_server);
    // executor.spin();
    rclcpp::spin(lap_time_action_server);
    // lap_time_action_server->process();
    rclcpp::shutdown();
    return 0;
}
