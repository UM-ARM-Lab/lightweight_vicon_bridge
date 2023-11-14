// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from lightweight_vicon_bridge:msg/MocapState.idl
// generated code does not contain a copyright notice
#include "lightweight_vicon_bridge/msg/detail/mocap_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "lightweight_vicon_bridge/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "lightweight_vicon_bridge/msg/detail/mocap_state__struct.h"
#include "lightweight_vicon_bridge/msg/detail/mocap_state__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "lightweight_vicon_bridge/msg/detail/mocap_object__functions.h"  // tracked_objects
#include "rosidl_runtime_c/string.h"  // tracker_name
#include "rosidl_runtime_c/string_functions.h"  // tracker_name
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
size_t get_serialized_size_lightweight_vicon_bridge__msg__MocapObject(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_lightweight_vicon_bridge__msg__MocapObject(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lightweight_vicon_bridge, msg, MocapObject)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_lightweight_vicon_bridge
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_lightweight_vicon_bridge
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_lightweight_vicon_bridge
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _MocapState__ros_msg_type = lightweight_vicon_bridge__msg__MocapState;

static bool _MocapState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MocapState__ros_msg_type * ros_message = static_cast<const _MocapState__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: tracker_name
  {
    const rosidl_runtime_c__String * str = &ros_message->tracker_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: tracked_objects
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, lightweight_vicon_bridge, msg, MocapObject
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->tracked_objects, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _MocapState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MocapState__ros_msg_type * ros_message = static_cast<_MocapState__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: tracker_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->tracker_name.data) {
      rosidl_runtime_c__String__init(&ros_message->tracker_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->tracker_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'tracker_name'\n");
      return false;
    }
  }

  // Field name: tracked_objects
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, lightweight_vicon_bridge, msg, MocapObject
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->tracked_objects))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lightweight_vicon_bridge
size_t get_serialized_size_lightweight_vicon_bridge__msg__MocapState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MocapState__ros_msg_type * ros_message = static_cast<const _MocapState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name tracker_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->tracker_name.size + 1);
  // field.name tracked_objects

  current_alignment += get_serialized_size_lightweight_vicon_bridge__msg__MocapObject(
    &(ros_message->tracked_objects), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _MocapState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_lightweight_vicon_bridge__msg__MocapState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lightweight_vicon_bridge
size_t max_serialized_size_lightweight_vicon_bridge__msg__MocapState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: tracker_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: tracked_objects
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_lightweight_vicon_bridge__msg__MocapObject(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _MocapState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_lightweight_vicon_bridge__msg__MocapState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MocapState = {
  "lightweight_vicon_bridge::msg",
  "MocapState",
  _MocapState__cdr_serialize,
  _MocapState__cdr_deserialize,
  _MocapState__get_serialized_size,
  _MocapState__max_serialized_size
};

static rosidl_message_type_support_t _MocapState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MocapState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lightweight_vicon_bridge, msg, MocapState)() {
  return &_MocapState__type_support;
}

#if defined(__cplusplus)
}
#endif
