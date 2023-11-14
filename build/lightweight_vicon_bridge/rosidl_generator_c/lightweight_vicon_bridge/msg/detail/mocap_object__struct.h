// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lightweight_vicon_bridge:msg/MocapObject.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_OBJECT__STRUCT_H_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_OBJECT__STRUCT_H_

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
// Member 'segments'
#include "lightweight_vicon_bridge/msg/detail/mocap_segment__struct.h"

/// Struct defined in msg/MocapObject in the package lightweight_vicon_bridge.
typedef struct lightweight_vicon_bridge__msg__MocapObject
{
  rosidl_runtime_c__String name;
  lightweight_vicon_bridge__msg__MocapSegment__Sequence segments;
} lightweight_vicon_bridge__msg__MocapObject;

// Struct for a sequence of lightweight_vicon_bridge__msg__MocapObject.
typedef struct lightweight_vicon_bridge__msg__MocapObject__Sequence
{
  lightweight_vicon_bridge__msg__MocapObject * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lightweight_vicon_bridge__msg__MocapObject__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_OBJECT__STRUCT_H_
