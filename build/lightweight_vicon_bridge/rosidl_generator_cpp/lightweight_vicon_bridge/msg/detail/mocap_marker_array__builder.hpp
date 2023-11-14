// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lightweight_vicon_bridge:msg/MocapMarkerArray.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER_ARRAY__BUILDER_HPP_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lightweight_vicon_bridge/msg/detail/mocap_marker_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lightweight_vicon_bridge
{

namespace msg
{

namespace builder
{

class Init_MocapMarkerArray_markers
{
public:
  explicit Init_MocapMarkerArray_markers(::lightweight_vicon_bridge::msg::MocapMarkerArray & msg)
  : msg_(msg)
  {}
  ::lightweight_vicon_bridge::msg::MocapMarkerArray markers(::lightweight_vicon_bridge::msg::MocapMarkerArray::_markers_type arg)
  {
    msg_.markers = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lightweight_vicon_bridge::msg::MocapMarkerArray msg_;
};

class Init_MocapMarkerArray_tracker_name
{
public:
  explicit Init_MocapMarkerArray_tracker_name(::lightweight_vicon_bridge::msg::MocapMarkerArray & msg)
  : msg_(msg)
  {}
  Init_MocapMarkerArray_markers tracker_name(::lightweight_vicon_bridge::msg::MocapMarkerArray::_tracker_name_type arg)
  {
    msg_.tracker_name = std::move(arg);
    return Init_MocapMarkerArray_markers(msg_);
  }

private:
  ::lightweight_vicon_bridge::msg::MocapMarkerArray msg_;
};

class Init_MocapMarkerArray_header
{
public:
  Init_MocapMarkerArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MocapMarkerArray_tracker_name header(::lightweight_vicon_bridge::msg::MocapMarkerArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MocapMarkerArray_tracker_name(msg_);
  }

private:
  ::lightweight_vicon_bridge::msg::MocapMarkerArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lightweight_vicon_bridge::msg::MocapMarkerArray>()
{
  return lightweight_vicon_bridge::msg::builder::Init_MocapMarkerArray_header();
}

}  // namespace lightweight_vicon_bridge

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER_ARRAY__BUILDER_HPP_
