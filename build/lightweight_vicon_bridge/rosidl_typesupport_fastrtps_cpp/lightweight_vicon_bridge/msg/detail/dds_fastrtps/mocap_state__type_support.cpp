// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from lightweight_vicon_bridge:msg/MocapState.idl
// generated code does not contain a copyright notice
#include "lightweight_vicon_bridge/msg/detail/mocap_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "lightweight_vicon_bridge/msg/detail/mocap_state__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace lightweight_vicon_bridge
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const lightweight_vicon_bridge::msg::MocapObject &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  lightweight_vicon_bridge::msg::MocapObject &);
size_t get_serialized_size(
  const lightweight_vicon_bridge::msg::MocapObject &,
  size_t current_alignment);
size_t
max_serialized_size_MocapObject(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace lightweight_vicon_bridge


namespace lightweight_vicon_bridge
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lightweight_vicon_bridge
cdr_serialize(
  const lightweight_vicon_bridge::msg::MocapState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: tracker_name
  cdr << ros_message.tracker_name;
  // Member: tracked_objects
  lightweight_vicon_bridge::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.tracked_objects,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lightweight_vicon_bridge
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  lightweight_vicon_bridge::msg::MocapState & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: tracker_name
  cdr >> ros_message.tracker_name;

  // Member: tracked_objects
  lightweight_vicon_bridge::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.tracked_objects);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lightweight_vicon_bridge
get_serialized_size(
  const lightweight_vicon_bridge::msg::MocapState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: tracker_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.tracker_name.size() + 1);
  // Member: tracked_objects

  current_alignment +=
    lightweight_vicon_bridge::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.tracked_objects, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lightweight_vicon_bridge
max_serialized_size_MocapState(
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


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: tracker_name
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

  // Member: tracked_objects
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        lightweight_vicon_bridge::msg::typesupport_fastrtps_cpp::max_serialized_size_MocapObject(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _MocapState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const lightweight_vicon_bridge::msg::MocapState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MocapState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<lightweight_vicon_bridge::msg::MocapState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MocapState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const lightweight_vicon_bridge::msg::MocapState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MocapState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MocapState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MocapState__callbacks = {
  "lightweight_vicon_bridge::msg",
  "MocapState",
  _MocapState__cdr_serialize,
  _MocapState__cdr_deserialize,
  _MocapState__get_serialized_size,
  _MocapState__max_serialized_size
};

static rosidl_message_type_support_t _MocapState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MocapState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace lightweight_vicon_bridge

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_lightweight_vicon_bridge
const rosidl_message_type_support_t *
get_message_type_support_handle<lightweight_vicon_bridge::msg::MocapState>()
{
  return &lightweight_vicon_bridge::msg::typesupport_fastrtps_cpp::_MocapState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lightweight_vicon_bridge, msg, MocapState)() {
  return &lightweight_vicon_bridge::msg::typesupport_fastrtps_cpp::_MocapState__handle;
}

#ifdef __cplusplus
}
#endif
