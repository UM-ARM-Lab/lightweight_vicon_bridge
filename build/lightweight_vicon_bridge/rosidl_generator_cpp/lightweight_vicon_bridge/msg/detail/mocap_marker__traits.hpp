// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lightweight_vicon_bridge:msg/MocapMarker.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER__TRAITS_HPP_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lightweight_vicon_bridge/msg/detail/mocap_marker__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace lightweight_vicon_bridge
{

namespace msg
{

inline void to_flow_style_yaml(
  const MocapMarker & msg,
  std::ostream & out)
{
  out << "{";
  // member: index
  {
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MocapMarker & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MocapMarker & msg, bool use_flow_style = false)
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
  const lightweight_vicon_bridge::msg::MocapMarker & msg,
  std::ostream & out, size_t indentation = 0)
{
  lightweight_vicon_bridge::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lightweight_vicon_bridge::msg::to_yaml() instead")]]
inline std::string to_yaml(const lightweight_vicon_bridge::msg::MocapMarker & msg)
{
  return lightweight_vicon_bridge::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lightweight_vicon_bridge::msg::MocapMarker>()
{
  return "lightweight_vicon_bridge::msg::MocapMarker";
}

template<>
inline const char * name<lightweight_vicon_bridge::msg::MocapMarker>()
{
  return "lightweight_vicon_bridge/msg/MocapMarker";
}

template<>
struct has_fixed_size<lightweight_vicon_bridge::msg::MocapMarker>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lightweight_vicon_bridge::msg::MocapMarker>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lightweight_vicon_bridge::msg::MocapMarker>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER__TRAITS_HPP_
