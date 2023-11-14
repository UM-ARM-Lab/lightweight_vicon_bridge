// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lightweight_vicon_bridge:msg/MocapMarker.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER__STRUCT_H_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/MocapMarker in the package lightweight_vicon_bridge.
typedef struct lightweight_vicon_bridge__msg__MocapMarker
{
  uint32_t index;
  rosidl_runtime_c__String name;
  geometry_msgs__msg__Point position;
} lightweight_vicon_bridge__msg__MocapMarker;

// Struct for a sequence of lightweight_vicon_bridge__msg__MocapMarker.
typedef struct lightweight_vicon_bridge__msg__MocapMarker__Sequence
{
  lightweight_vicon_bridge__msg__MocapMarker * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lightweight_vicon_bridge__msg__MocapMarker__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER__STRUCT_H_
