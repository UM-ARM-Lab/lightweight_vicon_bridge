#include <ros/ros.h>
#include <iostream>
#include <string>
#include <lightweight_vicon_bridge/MocapState.h>
#include <tf/transform_broadcaster.h>

std::unique_ptr<tf::TransformBroadcaster> g_tf_broadcaster;
std::string g_transform_prefix;
bool g_override_timestamps;

void MocapMsgCB(lightweight_vicon_bridge::MocapState msg)
{
    for (size_t idx_o = 0; idx_o < msg.tracked_objects.size(); idx_o++)
    {
        lightweight_vicon_bridge::MocapObject current_object = msg.tracked_objects[idx_o];
        for (size_t idx_s = 0; idx_s < current_object.segments.size(); idx_s++)
        {
            lightweight_vicon_bridge::MocapSegment current_segment = current_object.segments[idx_s];
            if (!current_segment.occluded)
            {
                /* Get the full segment name */
                std::string full_segment_name = g_transform_prefix + "/" + current_object.name + "/" + current_segment.name;
                /* Convert to a TF transform and publish */
                tf::Transform current_tf;
                current_tf.setOrigin(tf::Vector3(current_segment.transform.translation.x, current_segment.transform.translation.y, current_segment.transform.translation.z));
                current_tf.setRotation(tf::Quaternion(current_segment.transform.rotation.x, current_segment.transform.rotation.y, current_segment.transform.rotation.z, current_segment.transform.rotation.w));
                /* Publish TF */
                if (!g_override_timestamps)
                {
                    tf::StampedTransform current_tf_msg(current_tf, msg.header.stamp, msg.header.frame_id, full_segment_name);
                    g_tf_broadcaster->sendTransform(current_tf_msg);
                }
                else
                {
                    tf::StampedTransform current_tf_msg(current_tf, ros::Time::now(), msg.header.frame_id, full_segment_name);
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
    nhp.param(std::string("tracker_topic"), tracker_topic, std::string("mocap_tracking"));
    nhp.param(std::string("transform_prefix"), g_transform_prefix, std::string("mocap"));
    nhp.param(std::string("override_timestamps"), g_override_timestamps, false);
    if (g_override_timestamps)
    {
        ROS_WARN("Parameter override_timestamps is set to TRUE - TF publisher will overwrite the timestamps from the mocap system with the current time. USE CAREFULLY!");
    }
    else
    {
        ROS_INFO("Parameter override_timestamps is set to FALSE - TF publisher will use the timestamps from the mocap system.");
    }
    // Create the TF broadcaster
    g_tf_broadcaster = std::unique_ptr<tf::TransformBroadcaster>(new tf::TransformBroadcaster());
    // Create the mocap data subscriber
    ros::Subscriber mocap_sub = nh.subscribe(tracker_topic, 1, MocapMsgCB);
    // Start streaming data
    ROS_INFO("Streaming data...");
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
