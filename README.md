# Anthony-Moundalak-ROS2-AssignmentCPP-Session9

# ROS 2 Robot Navigation and Monitoring System

This repository contains a set of ROS 2 nodes and configurations for a robot navigation and monitoring system. The system includes functionality for wall detection, lap time measurement, and action client-server interaction.

## Overview

- **`robot_driver.hpp` and `robot_driver.cpp`:** Implements a ROS 2 node that drives a robot based on laser scan data. It subscribes to laser scan data, controls the robot’s movement, and communicates with a service to find the closest wall.

- **`wall_finder_service.hpp` and `wall_finder_service.cpp`:** Implements a ROS 2 service server that responds to requests for finding the closest wall. It uses laser scan data to determine the proximity to the closest wall and provides appropriate responses.

- **`lap_time_action_server.hpp` and `lap_time_action_server.cpp`:** Implements a ROS 2 action server that measures lap times for the robot. It uses odometry and laser scan data to track lap times and provides feedback and results to the action client.

- **`lap_time_action_client.hpp` and `lap_time_action_client.cpp`:** Implements a ROS 2 action client that sends goals to the lap time action server. It waits for the action server to complete the goal, receives feedback, and retrieves the result.

## Installation

1. **Clone the repository:**

    ```bash
    git clone <repository_url>
    cd <repository_directory>
    ```

2. **Build the package:**

    ```bash
    colcon build
    ```

3. **Source the workspace:**

    ```bash
    source install/setup.bash
    ```

## Launch File

The launch file is used to start all necessary nodes together. It is configured to launch the `robot_driver`, `wall_finder_service`, `lap_time_action_server`, and `lap_time_action_client` nodes.

## Usage

### Gazebo Setup

To run the Gazebo simulation with the TurtleBot3 model, use the following commands:

```bash
export TURTLEBOT3_MODEL=burger
ros2 launch turtlebot3_gazebo turtlebot3_dqn_stage1.launch.py
```

### Running Simulation

To run the Simulation, run the launch file using the following command:

```bash
ros2 launch turtlebot_navigation my_robot_launch.py
```