// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lightweight_vicon_bridge:msg/MocapObject.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lightweight_vicon_bridge/msg/detail/mocap_object__rosidl_typesupport_introspection_c.h"
#include "lightweight_vicon_bridge/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lightweight_vicon_bridge/msg/detail/mocap_object__functions.h"
#include "lightweight_vicon_bridge/msg/detail/mocap_object__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `segments`
#include "lightweight_vicon_bridge/msg/mocap_segment.h"
// Member `segments`
#include "lightweight_vicon_bridge/msg/detail/mocap_segment__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__MocapObject_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lightweight_vicon_bridge__msg__MocapObject__init(message_memory);
}

void lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__MocapObject_fini_function(void * message_memory)
{
  lightweight_vicon_bridge__msg__MocapObject__fini(message_memory);
}

size_t lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__size_function__MocapObject__segments(
  const void * untyped_member)
{
  const lightweight_vicon_bridge__msg__MocapSegment__Sequence * member =
    (const lightweight_vicon_bridge__msg__MocapSegment__Sequence *)(untyped_member);
  return member->size;
}

const void * lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__get_const_function__MocapObject__segments(
  const void * untyped_member, size_t index)
{
  const lightweight_vicon_bridge__msg__MocapSegment__Sequence * member =
    (const lightweight_vicon_bridge__msg__MocapSegment__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__get_function__MocapObject__segments(
  void * untyped_member, size_t index)
{
  lightweight_vicon_bridge__msg__MocapSegment__Sequence * member =
    (lightweight_vicon_bridge__msg__MocapSegment__Sequence *)(untyped_member);
  return &member->data[index];
}

void lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__fetch_function__MocapObject__segments(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const lightweight_vicon_bridge__msg__MocapSegment * item =
    ((const lightweight_vicon_bridge__msg__MocapSegment *)
    lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__get_const_function__MocapObject__segments(untyped_member, index));
  lightweight_vicon_bridge__msg__MocapSegment * value =
    (lightweight_vicon_bridge__msg__MocapSegment *)(untyped_value);
  *value = *item;
}

void lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__assign_function__MocapObject__segments(
  void * untyped_member, size_t index, const void * untyped_value)
{
  lightweight_vicon_bridge__msg__MocapSegment * item =
    ((lightweight_vicon_bridge__msg__MocapSegment *)
    lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__get_function__MocapObject__segments(untyped_member, index));
  const lightweight_vicon_bridge__msg__MocapSegment * value =
    (const lightweight_vicon_bridge__msg__MocapSegment *)(untyped_value);
  *item = *value;
}

bool lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__resize_function__MocapObject__segments(
  void * untyped_member, size_t size)
{
  lightweight_vicon_bridge__msg__MocapSegment__Sequence * member =
    (lightweight_vicon_bridge__msg__MocapSegment__Sequence *)(untyped_member);
  lightweight_vicon_bridge__msg__MocapSegment__Sequence__fini(member);
  return lightweight_vicon_bridge__msg__MocapSegment__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__MocapObject_message_member_array[2] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lightweight_vicon_bridge__msg__MocapObject, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "segments",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lightweight_vicon_bridge__msg__MocapObject, segments),  // bytes offset in struct
    NULL,  // default value
    lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__size_function__MocapObject__segments,  // size() function pointer
    lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__get_const_function__MocapObject__segments,  // get_const(index) function pointer
    lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__get_function__MocapObject__segments,  // get(index) function pointer
    lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__fetch_function__MocapObject__segments,  // fetch(index, &value) function pointer
    lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__assign_function__MocapObject__segments,  // assign(index, value) function pointer
    lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__resize_function__MocapObject__segments  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__MocapObject_message_members = {
  "lightweight_vicon_bridge__msg",  // message namespace
  "MocapObject",  // message name
  2,  // number of fields
  sizeof(lightweight_vicon_bridge__msg__MocapObject),
  lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__MocapObject_message_member_array,  // message members
  lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__MocapObject_init_function,  // function to initialize message memory (memory has to be allocated)
  lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__MocapObject_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__MocapObject_message_type_support_handle = {
  0,
  &lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__MocapObject_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lightweight_vicon_bridge
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lightweight_vicon_bridge, msg, MocapObject)() {
  lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__MocapObject_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lightweight_vicon_bridge, msg, MocapSegment)();
  if (!lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__MocapObject_message_type_support_handle.typesupport_identifier) {
    lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__MocapObject_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lightweight_vicon_bridge__msg__MocapObject__rosidl_typesupport_introspection_c__MocapObject_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
