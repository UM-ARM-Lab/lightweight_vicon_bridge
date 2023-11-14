// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lightweight_vicon_bridge:msg/MocapState.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__TRAITS_HPP_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lightweight_vicon_bridge/msg/detail/mocap_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'tracked_objects'
#include "lightweight_vicon_bridge/msg/detail/mocap_object__traits.hpp"

namespace lightweight_vicon_bridge
{

namespace msg
{

inline void to_flow_style_yaml(
  const MocapState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: tracker_name
  {
    out << "tracker_name: ";
    rosidl_generator_traits::value_to_yaml(msg.tracker_name, out);
    out << ", ";
  }

  // member: tracked_objects
  {
    out << "tracked_objects: ";
    to_flow_style_yaml(msg.tracked_objects, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MocapState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: tracker_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tracker_name: ";
    rosidl_generator_traits::value_to_yaml(msg.tracker_name, out);
    out << "\n";
  }

  // member: tracked_objects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tracked_objects:\n";
    to_block_style_yaml(msg.tracked_objects, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MocapState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace lightweight_vicon_bridge

namespace rosidl_generator_traits
{

[[deprecated("use lightweight_vicon_bridge::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lightweight_vicon_bridge::msg::MocapState & msg,
  std::ostream & out, size_t indentation = 0)
{
  lightweight_vicon_bridge::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lightweight_vicon_bridge::msg::to_yaml() instead")]]
inline std::string to_yaml(const lightweight_vicon_bridge::msg::MocapState & msg)
{
  return lightweight_vicon_bridge::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lightweight_vicon_bridge::msg::MocapState>()
{
  return "lightweight_vicon_bridge::msg::MocapState";
}

template<>
inline const char * name<lightweight_vicon_bridge::msg::MocapState>()
{
  return "lightweight_vicon_bridge/msg/MocapState";
}

template<>
struct has_fixed_size<lightweight_vicon_bridge::msg::MocapState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lightweight_vicon_bridge::msg::MocapState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lightweight_vicon_bridge::msg::MocapState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__TRAITS_HPP_
