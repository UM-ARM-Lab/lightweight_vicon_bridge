// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lightweight_vicon_bridge:msg/MocapSegment.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_SEGMENT__BUILDER_HPP_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_SEGMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lightweight_vicon_bridge/msg/detail/mocap_segment__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lightweight_vicon_bridge
{

namespace msg
{

namespace builder
{

class Init_MocapSegment_occluded
{
public:
  explicit Init_MocapSegment_occluded(::lightweight_vicon_bridge::msg::MocapSegment & msg)
  : msg_(msg)
  {}
  ::lightweight_vicon_bridge::msg::MocapSegment occluded(::lightweight_vicon_bridge::msg::MocapSegment::_occluded_type arg)
  {
    msg_.occluded = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lightweight_vicon_bridge::msg::MocapSegment msg_;
};

class Init_MocapSegment_transform
{
public:
  explicit Init_MocapSegment_transform(::lightweight_vicon_bridge::msg::MocapSegment & msg)
  : msg_(msg)
  {}
  Init_MocapSegment_occluded transform(::lightweight_vicon_bridge::msg::MocapSegment::_transform_type arg)
  {
    msg_.transform = std::move(arg);
    return Init_MocapSegment_occluded(msg_);
  }

private:
  ::lightweight_vicon_bridge::msg::MocapSegment msg_;
};

class Init_MocapSegment_name
{
public:
  Init_MocapSegment_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MocapSegment_transform name(::lightweight_vicon_bridge::msg::MocapSegment::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_MocapSegment_transform(msg_);
  }

private:
  ::lightweight_vicon_bridge::msg::MocapSegment msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lightweight_vicon_bridge::msg::MocapSegment>()
{
  return lightweight_vicon_bridge::msg::builder::Init_MocapSegment_name();
}

}  // namespace lightweight_vicon_bridge

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_SEGMENT__BUILDER_HPP_
