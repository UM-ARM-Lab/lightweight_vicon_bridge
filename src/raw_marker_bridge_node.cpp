#include <ros/ros.h>
#include <iostream>
#include <string>
#include <lightweight_vicon_bridge/MocapMarkerArray.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <Client.h>

visualization_msgs::Marker
make_marker_viz(const std::string &tracker_frame_name, const ros::Time &frame_time, unsigned int idx, double x,
                double y, double z);

int main(int argc, char **argv) {
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
    std::string viz_topic = "mocap_markers_viz";
    std::string stream_mode;
    bool use_sim_time = false;
    nhp.param(std::string("tracker_hostname"), tracker_hostname, std::string("192.168.2.161"));
    nhp.param(std::string("tracker_port"), tracker_port, std::string("801"));
    nhp.param(std::string("tracker_frame_name"), tracker_frame_name, std::string("mocap_world"));
    nhp.param(std::string("tracker_name"), tracker_name, std::string("mocap"));
    nhp.param(std::string("tracker_topic"), tracker_topic, std::string("mocap_markers"));
    nhp.param(std::string("stream_mode"), stream_mode, std::string("ServerPush"));
    nhp.param(std::string("use_sim_time"), use_sim_time, false);
    if (use_sim_time) {
        ROS_INFO("Parameter use_sim_time set, waiting until we have valid timing data");
        // Handle the sim time issue
        while (ros::Time::now().toSec() <= 0.02) {
            ros::spinOnce();
        }
    }
    // Check the stream mode
    if (stream_mode == std::string("ServerPush") || stream_mode == std::string("ClientPullPreFetch") ||
        stream_mode == std::string("ClientPull")) {
        ROS_INFO("Starting in %s mode", stream_mode.c_str());
    } else {
        ROS_FATAL("Invalid stream mode %s, valid options are ServerPush, ClientPullPreFetch, and ClientPull",
                  stream_mode.c_str());
        exit(-1);
    }
    // Assemble the full hostname
    tracker_hostname = tracker_hostname + ":" + tracker_port;
    ROS_INFO("Connecting to Vicon Tracker (DataStream SDK) at hostname %s", tracker_hostname.c_str());
    // Make the ROS publisher
    ros::Publisher mocap_pub = nh.advertise<lightweight_vicon_bridge::MocapMarkerArray>(tracker_topic, 1, false);
    ros::Publisher viz_pub = nh.advertise<visualization_msgs::MarkerArray>(viz_topic, 10, false);
    // Initialize the DataStream SDK
    ViconDataStreamSDK::CPP::Client sdk_client;
    ROS_INFO("Connecting to server...");
    sdk_client.Connect(tracker_hostname);
    usleep(10000);
    while (!sdk_client.IsConnected().Connected && ros::ok()) {
        ROS_WARN("...taking a while to connect, trying again...");
        sdk_client.Connect(tracker_hostname);
        usleep(10000);
    }
    ROS_INFO("...connected!");
    // Enable data
    sdk_client.EnableUnlabeledMarkerData();
    // Set the axes (right-handed, X-forwards, Y-left, Z-up, same as ROS)
    sdk_client.SetAxisMapping(ViconDataStreamSDK::CPP::Direction::Forward, ViconDataStreamSDK::CPP::Direction::Left,
                              ViconDataStreamSDK::CPP::Direction::Up);
    // Set streaming mode
    if (stream_mode == "ServerPush") {
        sdk_client.SetStreamMode(ViconDataStreamSDK::CPP::StreamMode::ServerPush);
    } else if (stream_mode == "ClientPullPreFetch") {
        sdk_client.SetStreamMode(ViconDataStreamSDK::CPP::StreamMode::ClientPullPreFetch);
    } else if (stream_mode == "ClientPull") {
        sdk_client.SetStreamMode(ViconDataStreamSDK::CPP::StreamMode::ClientPull);
    } else {
        ROS_FATAL("Invalid stream mode");
        exit(-2);
    }
    // Start streaming data
    ROS_INFO("Streaming data...");
    while (ros::ok()) {
        // Get a new frame and process it
        if (sdk_client.GetFrame().Result == ViconDataStreamSDK::CPP::Result::Success) {
            const auto total_latency = sdk_client.GetLatencyTotal().Total;
            const ros::Duration latency_duration(total_latency);
            const auto current_time = ros::Time::now();
            ros::Time raw_frame_time(0.0);
            if (current_time.toSec() > latency_duration.toSec()) {
                raw_frame_time = current_time - latency_duration;
            } else {
                ROS_WARN("(INVALID FRAME TIME) Latency estimate is greater than current time, leaving time at zero");
            }
            const ros::Time frame_time = raw_frame_time;
            lightweight_vicon_bridge::MocapMarkerArray state_msg;
            state_msg.header.frame_id = tracker_frame_name;
            state_msg.header.stamp = frame_time;
            state_msg.tracker_name = tracker_name;
            visualization_msgs::MarkerArray viz_msg;
            // Get the unlabeled markers
            unsigned int unlabelled_markers = sdk_client.GetUnlabeledMarkerCount().MarkerCount;
            for (unsigned int idx = 0; idx < unlabelled_markers; idx++) {
                const auto position = sdk_client.GetUnlabeledMarkerGlobalTranslation(idx);

                const auto x = position.Translation[0] * 0.001;
                const auto y = position.Translation[1] * 0.001;
                const auto z = position.Translation[2] * 0.001;

                lightweight_vicon_bridge::MocapMarker marker_msg;
                marker_msg.index = idx;
                marker_msg.position.x = x;
                marker_msg.position.y = y;
                marker_msg.position.z = z;
                state_msg.markers.push_back(marker_msg);

                const auto marker_viz_msg = make_marker_viz(tracker_frame_name, frame_time, idx, x, y, z);
                viz_msg.markers.push_back(marker_viz_msg);
            }
            mocap_pub.publish(state_msg);
            viz_pub.publish(viz_msg);
        }
        // Handle ROS stuff
        ros::spinOnce();
    }
    sdk_client.DisableUnlabeledMarkerData();
    sdk_client.Disconnect();
    return 0;
}

visualization_msgs::Marker
make_marker_viz(const std::string &tracker_frame_name, const ros::Time &frame_time, unsigned int idx, const double x,
                const double y, const double z) {
    visualization_msgs::Marker marker_viz_msg;
    marker_viz_msg.action = visualization_msgs::Marker::ADD;
    marker_viz_msg.type = visualization_msgs::Marker::SPHERE;
    marker_viz_msg.header.frame_id = tracker_frame_name;
    marker_viz_msg.header.stamp = frame_time;
    marker_viz_msg.color.a = 1.0;
    marker_viz_msg.color.r = 0.6;
    marker_viz_msg.color.g = 0.6;
    marker_viz_msg.color.b = 0.6;
    marker_viz_msg.scale.x = 0.013;
    marker_viz_msg.scale.y = 0.013;
    marker_viz_msg.scale.z = 0.013;
    marker_viz_msg.ns = std::to_string(idx);
    marker_viz_msg.pose.position.x = x;
    marker_viz_msg.pose.position.y = y;
    marker_viz_msg.pose.position.z = z;
    marker_viz_msg.pose.orientation.w = 1;
    return marker_viz_msg;
}
