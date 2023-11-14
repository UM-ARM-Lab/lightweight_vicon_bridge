// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from lightweight_vicon_bridge:msg/MocapObject.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "lightweight_vicon_bridge/msg/detail/mocap_object__struct.hpp"
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

void MocapObject_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) lightweight_vicon_bridge::msg::MocapObject(_init);
}

void MocapObject_fini_function(void * message_memory)
{
  auto typed_message = static_cast<lightweight_vicon_bridge::msg::MocapObject *>(message_memory);
  typed_message->~MocapObject();
}

size_t size_function__MocapObject__segments(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<lightweight_vicon_bridge::msg::MocapSegment> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MocapObject__segments(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<lightweight_vicon_bridge::msg::MocapSegment> *>(untyped_member);
  return &member[index];
}

void * get_function__MocapObject__segments(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<lightweight_vicon_bridge::msg::MocapSegment> *>(untyped_member);
  return &member[index];
}

void fetch_function__MocapObject__segments(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const lightweight_vicon_bridge::msg::MocapSegment *>(
    get_const_function__MocapObject__segments(untyped_member, index));
  auto & value = *reinterpret_cast<lightweight_vicon_bridge::msg::MocapSegment *>(untyped_value);
  value = item;
}

void assign_function__MocapObject__segments(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<lightweight_vicon_bridge::msg::MocapSegment *>(
    get_function__MocapObject__segments(untyped_member, index));
  const auto & value = *reinterpret_cast<const lightweight_vicon_bridge::msg::MocapSegment *>(untyped_value);
  item = value;
}

void resize_function__MocapObject__segments(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<lightweight_vicon_bridge::msg::MocapSegment> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MocapObject_message_member_array[2] = {
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lightweight_vicon_bridge::msg::MocapObject, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "segments",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<lightweight_vicon_bridge::msg::MocapSegment>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lightweight_vicon_bridge::msg::MocapObject, segments),  // bytes offset in struct
    nullptr,  // default value
    size_function__MocapObject__segments,  // size() function pointer
    get_const_function__MocapObject__segments,  // get_const(index) function pointer
    get_function__MocapObject__segments,  // get(index) function pointer
    fetch_function__MocapObject__segments,  // fetch(index, &value) function pointer
    assign_function__MocapObject__segments,  // assign(index, value) function pointer
    resize_function__MocapObject__segments  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MocapObject_message_members = {
  "lightweight_vicon_bridge::msg",  // message namespace
  "MocapObject",  // message name
  2,  // number of fields
  sizeof(lightweight_vicon_bridge::msg::MocapObject),
  MocapObject_message_member_array,  // message members
  MocapObject_init_function,  // function to initialize message memory (memory has to be allocated)
  MocapObject_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MocapObject_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MocapObject_message_members,
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
get_message_type_support_handle<lightweight_vicon_bridge::msg::MocapObject>()
{
  return &::lightweight_vicon_bridge::msg::rosidl_typesupport_introspection_cpp::MocapObject_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lightweight_vicon_bridge, msg, MocapObject)() {
  return &::lightweight_vicon_bridge::msg::rosidl_typesupport_introspection_cpp::MocapObject_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
