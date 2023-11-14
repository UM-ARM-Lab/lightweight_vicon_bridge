// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lightweight_vicon_bridge:msg/MocapMarker.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER__BUILDER_HPP_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lightweight_vicon_bridge/msg/detail/mocap_marker__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lightweight_vicon_bridge
{

namespace msg
{

namespace builder
{

class Init_MocapMarker_position
{
public:
  explicit Init_MocapMarker_position(::lightweight_vicon_bridge::msg::MocapMarker & msg)
  : msg_(msg)
  {}
  ::lightweight_vicon_bridge::msg::MocapMarker position(::lightweight_vicon_bridge::msg::MocapMarker::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lightweight_vicon_bridge::msg::MocapMarker msg_;
};

class Init_MocapMarker_name
{
public:
  explicit Init_MocapMarker_name(::lightweight_vicon_bridge::msg::MocapMarker & msg)
  : msg_(msg)
  {}
  Init_MocapMarker_position name(::lightweight_vicon_bridge::msg::MocapMarker::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_MocapMarker_position(msg_);
  }

private:
  ::lightweight_vicon_bridge::msg::MocapMarker msg_;
};

class Init_MocapMarker_index
{
public:
  Init_MocapMarker_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MocapMarker_name index(::lightweight_vicon_bridge::msg::MocapMarker::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_MocapMarker_name(msg_);
  }

private:
  ::lightweight_vicon_bridge::msg::MocapMarker msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lightweight_vicon_bridge::msg::MocapMarker>()
{
  return lightweight_vicon_bridge::msg::builder::Init_MocapMarker_index();
}

}  // namespace lightweight_vicon_bridge

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER__BUILDER_HPP_
