// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from lightweight_vicon_bridge:msg/MocapMarker.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "lightweight_vicon_bridge/msg/detail/mocap_marker__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace lightweight_vicon_bridge
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MocapMarker_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) lightweight_vicon_bridge::msg::MocapMarker(_init);
}

void MocapMarker_fini_function(void * message_memory)
{
  auto typed_message = static_cast<lightweight_vicon_bridge::msg::MocapMarker *>(message_memory);
  typed_message->~MocapMarker();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MocapMarker_message_member_array[3] = {
  {
    "index",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lightweight_vicon_bridge::msg::MocapMarker, index),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lightweight_vicon_bridge::msg::MocapMarker, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lightweight_vicon_bridge::msg::MocapMarker, position),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MocapMarker_message_members = {
  "lightweight_vicon_bridge::msg",  // message namespace
  "MocapMarker",  // message name
  3,  // number of fields
  sizeof(lightweight_vicon_bridge::msg::MocapMarker),
  MocapMarker_message_member_array,  // message members
  MocapMarker_init_function,  // function to initialize message memory (memory has to be allocated)
  MocapMarker_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MocapMarker_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MocapMarker_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace lightweight_vicon_bridge


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<lightweight_vicon_bridge::msg::MocapMarker>()
{
  return &::lightweight_vicon_bridge::msg::rosidl_typesupport_introspection_cpp::MocapMarker_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lightweight_vicon_bridge, msg, MocapMarker)() {
  return &::lightweight_vicon_bridge::msg::rosidl_typesupport_introspection_cpp::MocapMarker_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
