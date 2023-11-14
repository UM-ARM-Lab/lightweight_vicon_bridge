// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lightweight_vicon_bridge:msg/MocapObject.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_OBJECT__BUILDER_HPP_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_OBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lightweight_vicon_bridge/msg/detail/mocap_object__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lightweight_vicon_bridge
{

namespace msg
{

namespace builder
{

class Init_MocapObject_segments
{
public:
  explicit Init_MocapObject_segments(::lightweight_vicon_bridge::msg::MocapObject & msg)
  : msg_(msg)
  {}
  ::lightweight_vicon_bridge::msg::MocapObject segments(::lightweight_vicon_bridge::msg::MocapObject::_segments_type arg)
  {
    msg_.segments = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lightweight_vicon_bridge::msg::MocapObject msg_;
};

class Init_MocapObject_name
{
public:
  Init_MocapObject_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MocapObject_segments name(::lightweight_vicon_bridge::msg::MocapObject::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_MocapObject_segments(msg_);
  }

private:
  ::lightweight_vicon_bridge::msg::MocapObject msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lightweight_vicon_bridge::msg::MocapObject>()
{
  return lightweight_vicon_bridge::msg::builder::Init_MocapObject_name();
}

}  // namespace lightweight_vicon_bridge

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_OBJECT__BUILDER_HPP_
