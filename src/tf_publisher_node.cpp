#include <rclcpp/rclcpp.hpp>
#include <iostream>
#include <string>
#include "lightweight_vicon_bridge/msg/mocap_state.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/msg/transform_stamped.hpp"



std::unique_ptr<tf2_ros::TransformBroadcaster> g_tf_broadcaster;
bool g_override_timestamps;

void MocapMsgCB(lightweight_vicon_bridge::msg::MocapState msg)
{
    const std::string& mocap_name = msg.tracker_name;
    for (size_t idx_o = 0; idx_o < msg.tracked_objects.size(); idx_o++)
    {
        const lightweight_vicon_bridge::msg::MocapObject current_object = msg.tracked_objects[idx_o];
        for (size_t idx_s = 0; idx_s < current_object.segments.size(); idx_s++)
        {
            const lightweight_vicon_bridge::msg::MocapSegment current_segment = current_object.segments[idx_s];
            if (!current_segment.occluded)
            {
                /* Get the full segment name */
                const std::string full_segment_name = mocap_name + "_" + current_object.name + "_" + current_segment.name;
                /* Convert to a TF transform and publish */
                geometry_msgs::msg::TransformStamped current_tf_msg;
                current_tf_msg.header.stamp =rclcpp::Clock().now();
                current_tf_msg.header.frame_id = msg.header.frame_id;
                current_tf_msg.child_frame_id = full_segment_name;
                current_tf_msg.transform.translation.x = current_segment.transform.translation.x;
                current_tf_msg.transform.translation.y = current_segment.transform.translation.y;
                current_tf_msg.transform.translation.z = current_segment.transform.translation.z;
                current_tf_msg.transform.rotation.x = current_segment.transform.rotation.x;
                current_tf_msg.transform.rotation.y = current_segment.transform.rotation.y;
                current_tf_msg.transform.rotation.z = current_segment.transform.rotation.z;
                current_tf_msg.transform.rotation.w = current_segment.transform.rotation.w;
                /* Publish TF */
                if (!g_override_timestamps)
                {
                    current_tf_msg.header.stamp = msg.header.stamp;
                    g_tf_broadcaster->sendTransform(current_tf_msg);
                }
                else
                {
                    g_tf_broadcaster->sendTransform(current_tf_msg);
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("lightweight_vicon_bridge_tf_publisher");
    RCLCPP_INFO(node->get_logger(), "Starting lightweight vicon bridge TF publisher......");
    bool use_sim_time = node->declare_parameter<bool>("test_use_sim_time", false);
    std::string tracker_topic = node->declare_parameter<std::string>("tracker_topic", "mocap_tracking");
    g_override_timestamps = node->declare_parameter<bool>("override_timestamps",false);
    if (use_sim_time)
    {
        RCLCPP_INFO(node->get_logger(), "Parameter use_sim_time set, waiting until we have valid timing data");

        // Handle the sim time issue
        while (node->now().seconds() <= 0.02)
        {
           rclcpp::spin_some(node);
        }
    }
    if (g_override_timestamps)
    {
        RCLCPP_INFO(node->get_logger(), "Parameter override_timestamps is set to TRUE - TF publisher will overwrite the timestamps from the mocap system with the current time. USE CAREFULLY!");
    }
    else
    {
        RCLCPP_INFO(node->get_logger(), "Parameter override_timestamps is set to FALSE - TF publisher will use the timestamps from the mocap system.");
    }
    // Create the TF broadcaster
    g_tf_broadcaster = std::make_unique<tf2_ros::TransformBroadcaster>(*node);
    // Create the mocap data subscriber
    rclcpp::Subscription<lightweight_vicon_bridge::msg::MocapState>::SharedPtr mocap_sub = node->create_subscription<lightweight_vicon_bridge::msg::MocapState>(tracker_topic, 1, MocapMsgCB);
    // Start streaming data
    RCLCPP_INFO(node->get_logger(),"Broadcasting transforms...");
    rclcpp::Rate spin_rate(200.0);
    while (rclcpp::ok())
    {
        // Handle ROS stuff
        rclcpp::spin_some(node);
        // Sleep briefly
        spin_rate.sleep();
    }
    return 0;
}
