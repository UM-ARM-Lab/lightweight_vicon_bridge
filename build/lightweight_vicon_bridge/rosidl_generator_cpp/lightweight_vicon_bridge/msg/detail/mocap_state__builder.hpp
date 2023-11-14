// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lightweight_vicon_bridge:msg/MocapState.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__BUILDER_HPP_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lightweight_vicon_bridge/msg/detail/mocap_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lightweight_vicon_bridge
{

namespace msg
{

namespace builder
{

class Init_MocapState_tracked_objects
{
public:
  explicit Init_MocapState_tracked_objects(::lightweight_vicon_bridge::msg::MocapState & msg)
  : msg_(msg)
  {}
  ::lightweight_vicon_bridge::msg::MocapState tracked_objects(::lightweight_vicon_bridge::msg::MocapState::_tracked_objects_type arg)
  {
    msg_.tracked_objects = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lightweight_vicon_bridge::msg::MocapState msg_;
};

class Init_MocapState_tracker_name
{
public:
  explicit Init_MocapState_tracker_name(::lightweight_vicon_bridge::msg::MocapState & msg)
  : msg_(msg)
  {}
  Init_MocapState_tracked_objects tracker_name(::lightweight_vicon_bridge::msg::MocapState::_tracker_name_type arg)
  {
    msg_.tracker_name = std::move(arg);
    return Init_MocapState_tracked_objects(msg_);
  }

private:
  ::lightweight_vicon_bridge::msg::MocapState msg_;
};

class Init_MocapState_header
{
public:
  Init_MocapState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MocapState_tracker_name header(::lightweight_vicon_bridge::msg::MocapState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MocapState_tracker_name(msg_);
  }

private:
  ::lightweight_vicon_bridge::msg::MocapState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lightweight_vicon_bridge::msg::MocapState>()
{
  return lightweight_vicon_bridge::msg::builder::Init_MocapState_header();
}

}  // namespace lightweight_vicon_bridge

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__BUILDER_HPP_
