
#include <iostream>
#include <string>
#include <Client.h>
#include "rclcpp/rclcpp.hpp"
#include "lightweight_vicon_bridge/msg/mocap_marker_array.hpp"
#include "lightweight_vicon_bridge/msg/mocap_marker.hpp"
#include <visualization_msgs/msg/marker_array.hpp>
#include <visualization_msgs/msg/marker.h>



visualization_msgs::msg::Marker
make_marker_viz(const std::string &tracker_frame_name, const rclcpp::Time &frame_time, unsigned int idx, double x,
                double y, double z);

int main(int argc, char **argv) {

    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("raw_marker_bridge");
    RCLCPP_INFO(node->get_logger(), "Starting raw marker bridge...");
    RCLCPP_INFO(node->get_logger(), "Loading parameters...");
    
    std::string viz_topic = "mocap_markers_viz";
    std::string tracker_hostname = node->declare_parameter<std::string>("tracker_hostname", "10.10.10.5");
    int tracker_port =  node->declare_parameter<int>("tracker_port", 801);
    std::string tracker_frame_name = node->declare_parameter<std::string>("tracker_frame_name", "mocap_world");
    std::string tracker_name = node->declare_parameter<std::string>("tracker_name", "mocap");
    std::string tracker_topic = node->declare_parameter<std::string>("tracker_topic", "mocap_tracking");
    std::string stream_mode = node->declare_parameter<std::string>("stream_mode", "ServerPush");
    bool use_sim_time = node->get_parameter("use_sim_time").as_bool();
    
    
    
  if (use_sim_time)
    {
        RCLCPP_INFO(node->get_logger(), "Parameter use_sim_time set, waiting until we have valid timing data");
        while (node->now().seconds() <= 0.02)
        {
           rclcpp::spin_some(node);
        }
    }
    // Check the stream mode
        if (stream_mode == std::string("ServerPush") || stream_mode == std::string("ClientPullPreFetch") || stream_mode == std::string("ClientPull"))
    {
        RCLCPP_INFO(node->get_logger(), "Starting in %s mode", stream_mode.c_str());

    }
    else
    {
        RCLCPP_FATAL(node->get_logger(), "Invalid stream mode %s, valid options are ServerPush, ClientPullPreFetch, and ClientPull", stream_mode.c_str());
        exit(-1);
    }
    // Assemble the full hostname
    tracker_hostname = tracker_hostname + ":" + std::to_string(tracker_port);
    RCLCPP_INFO(node->get_logger(), "Connecting to Vicon Tracker (DataStream SDK) at hostname %s", tracker_hostname.c_str());
    
    // Make the ROS publisher
    rclcpp::Publisher<lightweight_vicon_bridge::msg::MocapMarkerArray>::SharedPtr mocap_pub = node->create_publisher<lightweight_vicon_bridge::msg::MocapMarkerArray>(tracker_topic, 1);
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr viz_pub = node->create_publisher<visualization_msgs::msg::MarkerArray>(viz_topic, 10);
    
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
        RCLCPP_FATAL(node->get_logger(), "Invalid stream mode");

        exit(-2);
    }
    // Start streaming data
    RCLCPP_INFO(node->get_logger(), "Streaming data...");
    while (rclcpp::ok()) {
        // Get a new frame and process it
        if (sdk_client.GetFrame().Result == ViconDataStreamSDK::CPP::Result::Success) {
            const auto total_latency = sdk_client.GetLatencyTotal().Total;
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

            lightweight_vicon_bridge::msg::MocapMarkerArray state_msg;

            state_msg.header.frame_id = tracker_frame_name;
            state_msg.header.stamp = frame_time;
            state_msg.tracker_name = tracker_name;
            visualization_msgs::msg::MarkerArray viz_msg;
            // Get the unlabeled markers
            unsigned int unlabelled_markers = sdk_client.GetUnlabeledMarkerCount().MarkerCount;
            for (unsigned int idx = 0; idx < unlabelled_markers; idx++) {
                const auto position = sdk_client.GetUnlabeledMarkerGlobalTranslation(idx);

                const auto x = position.Translation[0] * 0.001;
                const auto y = position.Translation[1] * 0.001;
                const auto z = position.Translation[2] * 0.001;

                lightweight_vicon_bridge::msg::MocapMarker marker_msg;
                marker_msg.index = idx;
                marker_msg.position.x = x;
                marker_msg.position.y = y;
                marker_msg.position.z = z;
                state_msg.markers.push_back(marker_msg);

                const auto marker_viz_msg = make_marker_viz(tracker_frame_name, frame_time, idx, x, y, z);
                viz_msg.markers.push_back(marker_viz_msg);
            }
       
            mocap_pub->publish(state_msg);
            viz_pub->publish(viz_msg);
        }
        // Handle ROS stuff
        rclcpp::spin_some(node);

    }
    sdk_client.DisableUnlabeledMarkerData();
    sdk_client.Disconnect();
    return 0;
}

visualization_msgs::msg::Marker
make_marker_viz(const std::string &tracker_frame_name, const rclcpp::Time &frame_time, unsigned int idx, const double x,
                const double y, const double z) {
    visualization_msgs::msg::Marker marker_viz_msg;
    marker_viz_msg.action = visualization_msgs::msg::Marker::ADD;
    marker_viz_msg.type = visualization_msgs::msg::Marker::SPHERE_LIST;
    marker_viz_msg.header.frame_id = tracker_frame_name;
    marker_viz_msg.header.stamp = frame_time;
    marker_viz_msg.color.a = 1.0;
    marker_viz_msg.color.r = 0.2;
    marker_viz_msg.color.g = 0.2;
    marker_viz_msg.color.b = 0.2;
    marker_viz_msg.scale.x = 0.005;
    marker_viz_msg.ns = std::to_string(idx);
    marker_viz_msg.pose.position.x = x;
    marker_viz_msg.pose.position.y = y;
    marker_viz_msg.pose.position.z = z;
    marker_viz_msg.pose.orientation.w = 1;
    return marker_viz_msg;
}