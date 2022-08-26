#include <ros/ros.h>
#include <iostream>
#include <string>
#include <lightweight_vicon_bridge/MocapState.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>

std::unique_ptr<tf2_ros::TransformBroadcaster> g_tf_broadcaster;
bool g_override_timestamps;

void MocapMsgCB(lightweight_vicon_bridge::MocapState msg)
{
    const std::string& mocap_name = msg.tracker_name;
    for (size_t idx_o = 0; idx_o < msg.tracked_objects.size(); idx_o++)
    {
        const lightweight_vicon_bridge::MocapObject current_object = msg.tracked_objects[idx_o];
        for (size_t idx_s = 0; idx_s < current_object.segments.size(); idx_s++)
        {
            const lightweight_vicon_bridge::MocapSegment current_segment = current_object.segments[idx_s];
            if (!current_segment.occluded)
            {
                /* Get the full segment name */
                const std::string full_segment_name = mocap_name + "_" + current_object.name + "_" + current_segment.name;
                /* Convert to a TF transform and publish */
                geometry_msgs::TransformStamped current_tf_msg;
                current_tf_msg.header.stamp = ros::Time::now();
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
    ros::init(argc, argv, "lightweight_vicon_bridge_tf_publisher");
    ROS_INFO("Starting lightweight vicon bridge TF publisher...");
    ros::NodeHandle nh;
    ros::NodeHandle nhp("~");
    std::string tracker_topic;
    bool use_sim_time = false;
    nhp.param(std::string("tracker_topic"), tracker_topic, std::string("mocap_tracking"));
    nhp.param(std::string("override_timestamps"), g_override_timestamps, false);
    nhp.param(std::string("use_sim_time"), use_sim_time, false);
    if (use_sim_time)
    {
        ROS_INFO("Parameter use_sim_time set, waiting until we have valid timing data");
        // Handle the sim time issue
        while (ros::Time::now().toSec() <= 0.02)
        {
            ros::spinOnce();
        }
    }
    if (g_override_timestamps)
    {
        ROS_WARN("Parameter override_timestamps is set to TRUE - TF publisher will overwrite the timestamps from the mocap system with the current time. USE CAREFULLY!");
    }
    else
    {
        ROS_INFO("Parameter override_timestamps is set to FALSE - TF publisher will use the timestamps from the mocap system.");
    }
    // Create the TF broadcaster
    g_tf_broadcaster = std::unique_ptr<tf2_ros::TransformBroadcaster>(new tf2_ros::TransformBroadcaster());
    // Create the mocap data subscriber
    ros::Subscriber mocap_sub = nh.subscribe(tracker_topic, 1, MocapMsgCB);
    // Start streaming data
    ROS_INFO("Broadcasting transforms...");
    ros::Rate spin_rate(200.0);
    while (ros::ok())
    {
        // Handle ROS stuff
        ros::spinOnce();
        // Sleep briefly
        spin_rate.sleep();
    }
    return 0;
}
