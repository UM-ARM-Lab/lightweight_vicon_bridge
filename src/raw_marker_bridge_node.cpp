#include <ros/ros.h>
#include <iostream>
#include <string>
#include <lightweight_vicon_bridge/MocapMarkerArray.h>
#include <Client.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "raw_marker_bridge");
    ROS_INFO("Starting raw marker bridge...");
    ros::NodeHandle nh;
    ros::NodeHandle nhp("~");
    ROS_INFO("Loading parameters...");
    std::string tracker_hostname;
    std::string tracker_port;
    std::string tracker_frame_name;
    std::string tracker_name;
    std::string tracker_topic;
    std::string stream_mode;
    bool use_sim_time = false;
    nhp.param(std::string("tracker_hostname"), tracker_hostname, std::string("192.168.2.161"));
    nhp.param(std::string("tracker_port"), tracker_port, std::string("801"));
    nhp.param(std::string("tracker_frame_name"), tracker_frame_name, std::string("mocap_world"));
    nhp.param(std::string("tracker_name"), tracker_name, std::string("mocap"));
    nhp.param(std::string("tracker_topic"), tracker_topic, std::string("mocap_markers"));
    nhp.param(std::string("stream_mode"), stream_mode, std::string("ServerPush"));
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
    // Check the stream mode
    if (stream_mode == std::string("ServerPush") || stream_mode == std::string("ClientPullPreFetch") || stream_mode == std::string("ClientPull"))
    {
        ROS_INFO("Starting in %s mode", stream_mode.c_str());
    }
    else
    {
        ROS_FATAL("Invalid stream mode %s, valid options are ServerPush, ClientPullPreFetch, and ClientPull", stream_mode.c_str());
        exit(-1);
    }
    // Assemble the full hostname
    tracker_hostname = tracker_hostname + ":" + tracker_port;
    ROS_INFO("Connecting to Vicon Tracker (DataStream SDK) at hostname %s", tracker_hostname.c_str());
    // Make the ROS publisher
    ros::Publisher mocap_pub = nh.advertise<lightweight_vicon_bridge::MocapMarkerArray>(tracker_topic, 1, false);
    // Initialize the DataStream SDK
    ViconDataStreamSDK::CPP::Client sdk_client;
    ROS_INFO("Connecting to server...");
    sdk_client.Connect(tracker_hostname);
    usleep(10000);
    while (!sdk_client.IsConnected().Connected && ros::ok())
    {
        ROS_WARN("...taking a while to connect, trying again...");
        sdk_client.Connect(tracker_hostname);
        usleep(10000);
    }
    ROS_INFO("...connected!");
    // Enable data
    sdk_client.EnableUnlabeledMarkerData();
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
        ROS_FATAL("Invalid stream mode");
        exit(-2);
    }
    // Start streaming data
    ROS_INFO("Streaming data...");
    while (ros::ok())
    {
        // Get a new frame and process it
        if (sdk_client.GetFrame().Result == ViconDataStreamSDK::CPP::Result::Success)
        {
            const double total_latency = sdk_client.GetLatencyTotal().Total;
            const ros::Duration latency_duration(total_latency);
            const ros::Time current_time = ros::Time::now();
            ros::Time raw_frame_time(0.0);
            if (current_time.toSec() > latency_duration.toSec())
            {
                raw_frame_time = current_time - latency_duration;
            }
            else
            {
                ROS_WARN("(INVALID FRAME TIME) Latency estimate is greater than current time, leaving time at zero");
            }
            const ros::Time frame_time = raw_frame_time;
            lightweight_vicon_bridge::MocapMarkerArray state_msg;
            state_msg.header.frame_id = tracker_frame_name;
            state_msg.header.stamp = frame_time;
            state_msg.tracker_name = tracker_name;
            // Get the unlabeled markers
            unsigned int unlabelled_markers = sdk_client.GetUnlabeledMarkerCount().MarkerCount;
            for (unsigned int idx = 0; idx < unlabelled_markers; idx++)
            {
                ViconDataStreamSDK::CPP::Output_GetUnlabeledMarkerGlobalTranslation position = sdk_client.GetUnlabeledMarkerGlobalTranslation(idx);
                lightweight_vicon_bridge::MocapMarker marker_msg;
                marker_msg.index = idx;
                marker_msg.position.x = position.Translation[0] * 0.001;
                marker_msg.position.y = position.Translation[1] * 0.001;
                marker_msg.position.z = position.Translation[2] * 0.001;
                state_msg.markers.push_back(marker_msg);
            }
            mocap_pub.publish(state_msg);
        }
        // Handle ROS stuff
        ros::spinOnce();
    }
    sdk_client.DisableUnlabeledMarkerData();
    sdk_client.Disconnect();
    return 0;
}
