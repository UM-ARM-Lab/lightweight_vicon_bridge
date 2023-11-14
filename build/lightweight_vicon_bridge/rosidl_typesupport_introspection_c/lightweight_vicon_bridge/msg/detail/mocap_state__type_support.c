// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lightweight_vicon_bridge:msg/MocapState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lightweight_vicon_bridge/msg/detail/mocap_state__rosidl_typesupport_introspection_c.h"
#include "lightweight_vicon_bridge/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lightweight_vicon_bridge/msg/detail/mocap_state__functions.h"
#include "lightweight_vicon_bridge/msg/detail/mocap_state__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `tracker_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `tracked_objects`
#include "lightweight_vicon_bridge/msg/mocap_object.h"
// Member `tracked_objects`
#include "lightweight_vicon_bridge/msg/detail/mocap_object__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lightweight_vicon_bridge__msg__MocapState__rosidl_typesupport_introspection_c__MocapState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lightweight_vicon_bridge__msg__MocapState__init(message_memory);
}

void lightweight_vicon_bridge__msg__MocapState__rosidl_typesupport_introspection_c__MocapState_fini_function(void * message_memory)
{
  lightweight_vicon_bridge__msg__MocapState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember lightweight_vicon_bridge__msg__MocapState__rosidl_typesupport_introspection_c__MocapState_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lightweight_vicon_bridge__msg__MocapState, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tracker_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lightweight_vicon_bridge__msg__MocapState, tracker_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tracked_objects",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lightweight_vicon_bridge__msg__MocapState, tracked_objects),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lightweight_vicon_bridge__msg__MocapState__rosidl_typesupport_introspection_c__MocapState_message_members = {
  "lightweight_vicon_bridge__msg",  // message namespace
  "MocapState",  // message name
  3,  // number of fields
  sizeof(lightweight_vicon_bridge__msg__MocapState),
  lightweight_vicon_bridge__msg__MocapState__rosidl_typesupport_introspection_c__MocapState_message_member_array,  // message members
  lightweight_vicon_bridge__msg__MocapState__rosidl_typesupport_introspection_c__MocapState_init_function,  // function to initialize message memory (memory has to be allocated)
  lightweight_vicon_bridge__msg__MocapState__rosidl_typesupport_introspection_c__MocapState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lightweight_vicon_bridge__msg__MocapState__rosidl_typesupport_introspection_c__MocapState_message_type_support_handle = {
  0,
  &lightweight_vicon_bridge__msg__MocapState__rosidl_typesupport_introspection_c__MocapState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lightweight_vicon_bridge
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lightweight_vicon_bridge, msg, MocapState)() {
  lightweight_vicon_bridge__msg__MocapState__rosidl_typesupport_introspection_c__MocapState_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  lightweight_vicon_bridge__msg__MocapState__rosidl_typesupport_introspection_c__MocapState_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lightweight_vicon_bridge, msg, MocapObject)();
  if (!lightweight_vicon_bridge__msg__MocapState__rosidl_typesupport_introspection_c__MocapState_message_type_support_handle.typesupport_identifier) {
    lightweight_vicon_bridge__msg__MocapState__rosidl_typesupport_introspection_c__MocapState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lightweight_vicon_bridge__msg__MocapState__rosidl_typesupport_introspection_c__MocapState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif