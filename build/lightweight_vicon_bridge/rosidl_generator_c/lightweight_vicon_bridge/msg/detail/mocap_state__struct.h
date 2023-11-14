// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lightweight_vicon_bridge:msg/MocapState.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__STRUCT_H_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'tracker_name'
#include "rosidl_runtime_c/string.h"
// Member 'tracked_objects'
#include "lightweight_vicon_bridge/msg/detail/mocap_object__struct.h"

/// Struct defined in msg/MocapState in the package lightweight_vicon_bridge.
typedef struct lightweight_vicon_bridge__msg__MocapState
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String tracker_name;
  lightweight_vicon_bridge__msg__MocapObject tracked_objects;
} lightweight_vicon_bridge__msg__MocapState;

// Struct for a sequence of lightweight_vicon_bridge__msg__MocapState.
typedef struct lightweight_vicon_bridge__msg__MocapState__Sequence
{
  lightweight_vicon_bridge__msg__MocapState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lightweight_vicon_bridge__msg__MocapState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__STRUCT_H_
