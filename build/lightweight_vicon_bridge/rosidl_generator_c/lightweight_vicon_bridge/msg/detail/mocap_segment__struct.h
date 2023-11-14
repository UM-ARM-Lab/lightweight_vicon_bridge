// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lightweight_vicon_bridge:msg/MocapSegment.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_SEGMENT__STRUCT_H_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_SEGMENT__STRUCT_H_

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
// Member 'transform'
#include "geometry_msgs/msg/detail/transform__struct.h"

/// Struct defined in msg/MocapSegment in the package lightweight_vicon_bridge.
typedef struct lightweight_vicon_bridge__msg__MocapSegment
{
  rosidl_runtime_c__String name;
  geometry_msgs__msg__Transform transform;
  bool occluded;
} lightweight_vicon_bridge__msg__MocapSegment;

// Struct for a sequence of lightweight_vicon_bridge__msg__MocapSegment.
typedef struct lightweight_vicon_bridge__msg__MocapSegment__Sequence
{
  lightweight_vicon_bridge__msg__MocapSegment * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lightweight_vicon_bridge__msg__MocapSegment__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_SEGMENT__STRUCT_H_
