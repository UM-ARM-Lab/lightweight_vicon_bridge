// #include <ros/ros.h>
// #include <iostream>
// #include <string>
// #include <lightweight_vicon_bridge/MocapState.h>
// #include <Client.h>

#include <iostream>
#include <string>
#include <Client.h>
#include "rclcpp/rclcpp.hpp"
#include "lightweight_vicon_bridge/msg/mocap_state.hpp"



int main(int argc, char** argv)
{
    // rclcpp::init(argc, argv, "lightweight_vicon_bridge");
    rclcpp::init(argc, argv);
    lightweight_vicon_bridge::msg::MocapState sss;

    // Create a Node
    // rclcpp::NodeHandle nh;
    // rclcpp::NodeHandle nhp("~");
    auto node = rclcpp::Node::make_shared("lightweight_vicon_bridge");

    // RCLCPP_INFO("Starting lightweight vicon bridge...");
    RCLCPP_INFO(node->get_logger(), "Starting lightweight vicon bridge...");
    // RCLCPP_INFO("Loading parameters...");
    RCLCPP_INFO(node->get_logger(), "Loading parameters...");


    // Get parameters with default values
    // std::string tracker_hostname;
    // std::string tracker_port;
    // std::string tracker_frame_name;
    // std::string tracker_name;
    // std::string tracker_topic;
    // std::string stream_mode;
     bool use_sim_time = false;
    // nhp.param(std::string("tracker_hostname"), tracker_hostname, std::string("192.168.2.161"));
    // nhp.param(std::string("tracker_port"), tracker_port, std::string("801"));
    // nhp.param(std::string("tracker_frame_name"), tracker_frame_name, std::string("mocap_world"));
    // nhp.param(std::string("tracker_name"), tracker_name, std::string("mocap"));
    // nhp.param(std::string("tracker_topic"), tracker_topic, std::string("mocap_tracking"));
    // nhp.param(std::string("stream_mode"), stream_mode, std::string("ServerPush"));
    // nhp.param(std::string("use_sim_time"), use_sim_time, false);

    std::string tracker_hostname = node->declare_parameter<std::string>("tracker_hostname", "10.10.10.5");
    std::string tracker_port = node->declare_parameter<std::string>("tracker_port", "801");
    std::string tracker_frame_name = node->declare_parameter<std::string>("tracker_frame_name", "mocap_world");
    std::string tracker_name = node->declare_parameter<std::string>("tracker_name", "mocap");
    std::string tracker_topic = node->declare_parameter<std::string>("tracker_topic", "mocap_tracking");
    std::string stream_mode = node->declare_parameter<std::string>("stream_mode", "ServerPush");
//    use_sim_time = node->declare_parameter<bool>("use_sim_time", false);


    if (use_sim_time)
    {
        // RCLCPP_INFO("Parameter use_sim_time set, waiting until we have valid timing data");
        RCLCPP_INFO(node->get_logger(), "Parameter use_sim_time set, waiting until we have valid timing data");

        // Handle the sim time issue
        // while (rclcpp::Time::now().toSec() <= 0.02)
        // {
        //     rclcpp::spinOnce();
        // }
        while (node->now().seconds() <= 0.02)
        {
           rclcpp::spin_some(node);
        }
    }


    // Check the stream mode
    if (stream_mode == std::string("ServerPush") || stream_mode == std::string("ClientPullPreFetch") || stream_mode == std::string("ClientPull"))
    {
        // RCLCPP_INFO("Starting in %s mode", stream_mode.c_str());
        RCLCPP_INFO(node->get_logger(), "Starting in %s mode", stream_mode.c_str());

    }
    else
    {
        RCLCPP_FATAL(node->get_logger(), "Invalid stream mode %s, valid options are ServerPush, ClientPullPreFetch, and ClientPull", stream_mode.c_str());
        exit(-1);
    }
    // Assemble the full hostname
    tracker_hostname = tracker_hostname + ":" + tracker_port;
    RCLCPP_INFO(node->get_logger(), "Connecting to Vicon Tracker (DataStream SDK) at hostname %s", tracker_hostname.c_str());
    // Make the ROS publisher
//    rclcpp::Publisher mocap_pub = nh.advertise<lightweight_vicon_bridge::MocapState>(tracker_topic, 1, false);
    rclcpp::Publisher<lightweight_vicon_bridge::msg::MocapState>::SharedPtr mocap_pub = node->create_publisher<lightweight_vicon_bridge::msg::MocapState>(tracker_topic, 1);
    // Initialize the DataStream SDK
    ViconDataStreamSDK::CPP::Client sdk_client;
    RCLCPP_INFO(node->get_logger(), "Connecting to server...");
    sdk_client.Connect(tracker_hostname);
    usleep(10000);
    while (!sdk_client.IsConnected().Connected && rclcpp::ok())
    {
        RCLCPP_WARN(node->get_logger(), "...taking a while to connect, trying again...");
        sdk_client.Connect(tracker_hostname);
        usleep(10000);
    }
    RCLCPP_INFO(node->get_logger(), "...connected!");
    // Enable data
    sdk_client.EnableSegmentData();
    // Set the axes (right-handed, X-forwards, Y-left, Z-up, same as ROS)
    sdk_client.SetAxisMapping(ViconDataStreamSDK::CPP::Direction::Forward, ViconDataStreamSDK::CPP::Direction::Left, ViconDataStreamSDK::CPP::Direction::Up);
    // Set streaming mode
    if (stream_mode == "ServerPush")
    {
        sdk_client.SetStreamMode(ViconDataStreamSDK::CPP::StreamMode::ServerPush);
    }
    else if (stream_mode == "ClientPullPreFetch")
    {
        sdk_client.SetStreamMode(ViconDataStreamSDK::CPP::StreamMode::ClientPullPreFetch);
    }
    else if (stream_mode == "ClientPull")
    {
        sdk_client.SetStreamMode(ViconDataStreamSDK::CPP::StreamMode::ClientPull);
    }
    else
    {
        RCLCPP_FATAL(node->get_logger(), "Invalid stream mode");
        exit(-2);
    }
    // Start streaming data
    RCLCPP_INFO(node->get_logger(), "Streaming data...");
    while (rclcpp::ok())
    {
        // Get a new frame and process it
        if (sdk_client.GetFrame().Result == ViconDataStreamSDK::CPP::Result::Success)
        {
            const double total_latency = sdk_client.GetLatencyTotal().Total;
            const rclcpp::Duration latency_duration = rclcpp::Duration::from_seconds(total_latency);
            const rclcpp::Time current_time = node->now();
            rclcpp::Time raw_frame_time(0.0);
            if (current_time.seconds() > latency_duration.seconds())
            {
                raw_frame_time = current_time - latency_duration;
            }
            else
            {
                RCLCPP_WARN(node->get_logger(), "(INVALID FRAME TIME) Latency estimate is greater than current time, leaving time at zero");
            }
            const rclcpp::Time frame_time = raw_frame_time;
            lightweight_vicon_bridge::msg::MocapState state_msg;
            state_msg.header.frame_id = tracker_frame_name;
            state_msg.header.stamp = frame_time;
            state_msg.tracker_name = tracker_name;
            // Loop through the tracked objects and add them to the message
            const unsigned int objects = sdk_client.GetSubjectCount().SubjectCount;
            for (unsigned int idx_o = 0; idx_o < objects; idx_o++)
            {
                const std::string object_name = sdk_client.GetSubjectName(idx_o).SubjectName;
                lightweight_vicon_bridge::msg::MocapObject object_msg;
                object_msg.name = object_name;
                // Loop through the segments of the object
                const unsigned int segments = sdk_client.GetSegmentCount(object_name).SegmentCount;
                for (unsigned int idx_s = 0; idx_s < segments; idx_s++)
                {
                    const std::string segment_name = sdk_client.GetSegmentName(object_name, idx_s).SegmentName;
                    const ViconDataStreamSDK::CPP::Output_GetSegmentGlobalTranslation segment_position = sdk_client.GetSegmentGlobalTranslation(object_name, segment_name);
                    const ViconDataStreamSDK::CPP::Output_GetSegmentGlobalRotationQuaternion segment_rotation = sdk_client.GetSegmentGlobalRotationQuaternion(object_name, segment_name);
                    lightweight_vicon_bridge::msg::MocapSegment segment_msg;
                    segment_msg.name = segment_name;
                    /* Note - Vicon SDK uses millimeters for position */
                    segment_msg.transform.translation.x = segment_position.Translation[0] * 0.001;
                    segment_msg.transform.translation.y = segment_position.Translation[1] * 0.001;
                    segment_msg.transform.translation.z = segment_position.Translation[2] * 0.001;
                    segment_msg.transform.rotation.x = segment_rotation.Rotation[0];
                    segment_msg.transform.rotation.y = segment_rotation.Rotation[1];
                    segment_msg.transform.rotation.z = segment_rotation.Rotation[2];
                    segment_msg.transform.rotation.w = segment_rotation.Rotation[3];
                    // Determine if the object is occluded or not
                    if (segment_position.Occluded || segment_rotation.Occluded)
                    {
                        segment_msg.occluded = true;
                    }
                    else
                    {
                        segment_msg.occluded = false;
                    }
                    // Store the segment
                    object_msg.segments.push_back(segment_msg);
                }
                // Store the object
                state_msg.tracked_objects.push_back(object_msg);
            }
            // Finish the message and publish
            mocap_pub->publish(state_msg);
        }
        // Handle ROS stuff
        rclcpp::spin_some(node);
    }
    sdk_client.DisableSegmentData();
    sdk_client.Disconnect();
    return 0;
}