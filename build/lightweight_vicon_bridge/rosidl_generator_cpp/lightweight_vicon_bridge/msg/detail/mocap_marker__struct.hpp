// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lightweight_vicon_bridge:msg/MocapMarker.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER__STRUCT_HPP_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lightweight_vicon_bridge__msg__MocapMarker __attribute__((deprecated))
#else
# define DEPRECATED__lightweight_vicon_bridge__msg__MocapMarker __declspec(deprecated)
#endif

namespace lightweight_vicon_bridge
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MocapMarker_
{
  using Type = MocapMarker_<ContainerAllocator>;

  explicit MocapMarker_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0ul;
      this->name = "";
    }
  }

  explicit MocapMarker_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0ul;
      this->name = "";
    }
  }

  // field types and members
  using _index_type =
    uint32_t;
  _index_type index;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;

  // setters for named parameter idiom
  Type & set__index(
    const uint32_t & _arg)
  {
    this->index = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lightweight_vicon_bridge::msg::MocapMarker_<ContainerAllocator> *;
  using ConstRawPtr =
    const lightweight_vicon_bridge::msg::MocapMarker_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lightweight_vicon_bridge::msg::MocapMarker_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lightweight_vicon_bridge::msg::MocapMarker_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lightweight_vicon_bridge::msg::MocapMarker_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lightweight_vicon_bridge::msg::MocapMarker_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lightweight_vicon_bridge::msg::MocapMarker_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lightweight_vicon_bridge::msg::MocapMarker_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lightweight_vicon_bridge::msg::MocapMarker_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lightweight_vicon_bridge::msg::MocapMarker_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lightweight_vicon_bridge__msg__MocapMarker
    std::shared_ptr<lightweight_vicon_bridge::msg::MocapMarker_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lightweight_vicon_bridge__msg__MocapMarker
    std::shared_ptr<lightweight_vicon_bridge::msg::MocapMarker_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MocapMarker_ & other) const
  {
    if (this->index != other.index) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    return true;
  }
  bool operator!=(const MocapMarker_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MocapMarker_

// alias to use template instance with default allocator
using MocapMarker =
  lightweight_vicon_bridge::msg::MocapMarker_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lightweight_vicon_bridge

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_MARKER__STRUCT_HPP_
