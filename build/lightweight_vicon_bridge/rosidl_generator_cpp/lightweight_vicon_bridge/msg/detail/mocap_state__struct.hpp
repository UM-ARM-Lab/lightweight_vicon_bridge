// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lightweight_vicon_bridge:msg/MocapState.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__STRUCT_HPP_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'tracked_objects'
#include "lightweight_vicon_bridge/msg/detail/mocap_object__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lightweight_vicon_bridge__msg__MocapState __attribute__((deprecated))
#else
# define DEPRECATED__lightweight_vicon_bridge__msg__MocapState __declspec(deprecated)
#endif

namespace lightweight_vicon_bridge
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MocapState_
{
  using Type = MocapState_<ContainerAllocator>;

  explicit MocapState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    tracked_objects(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tracker_name = "";
    }
  }

  explicit MocapState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    tracker_name(_alloc),
    tracked_objects(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tracker_name = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _tracker_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tracker_name_type tracker_name;
  using _tracked_objects_type =
    lightweight_vicon_bridge::msg::MocapObject_<ContainerAllocator>;
  _tracked_objects_type tracked_objects;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__tracker_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tracker_name = _arg;
    return *this;
  }
  Type & set__tracked_objects(
    const lightweight_vicon_bridge::msg::MocapObject_<ContainerAllocator> & _arg)
  {
    this->tracked_objects = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lightweight_vicon_bridge::msg::MocapState_<ContainerAllocator> *;
  using ConstRawPtr =
    const lightweight_vicon_bridge::msg::MocapState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lightweight_vicon_bridge::msg::MocapState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lightweight_vicon_bridge::msg::MocapState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lightweight_vicon_bridge::msg::MocapState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lightweight_vicon_bridge::msg::MocapState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lightweight_vicon_bridge::msg::MocapState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lightweight_vicon_bridge::msg::MocapState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lightweight_vicon_bridge::msg::MocapState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lightweight_vicon_bridge::msg::MocapState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lightweight_vicon_bridge__msg__MocapState
    std::shared_ptr<lightweight_vicon_bridge::msg::MocapState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lightweight_vicon_bridge__msg__MocapState
    std::shared_ptr<lightweight_vicon_bridge::msg::MocapState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MocapState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->tracker_name != other.tracker_name) {
      return false;
    }
    if (this->tracked_objects != other.tracked_objects) {
      return false;
    }
    return true;
  }
  bool operator!=(const MocapState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MocapState_

// alias to use template instance with default allocator
using MocapState =
  lightweight_vicon_bridge::msg::MocapState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lightweight_vicon_bridge

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__STRUCT_HPP_
