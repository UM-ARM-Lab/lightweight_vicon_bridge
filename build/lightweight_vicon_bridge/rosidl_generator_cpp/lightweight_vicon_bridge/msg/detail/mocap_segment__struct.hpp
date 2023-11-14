// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lightweight_vicon_bridge:msg/MocapSegment.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_SEGMENT__STRUCT_HPP_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_SEGMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'transform'
#include "geometry_msgs/msg/detail/transform__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lightweight_vicon_bridge__msg__MocapSegment __attribute__((deprecated))
#else
# define DEPRECATED__lightweight_vicon_bridge__msg__MocapSegment __declspec(deprecated)
#endif

namespace lightweight_vicon_bridge
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MocapSegment_
{
  using Type = MocapSegment_<ContainerAllocator>;

  explicit MocapSegment_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : transform(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->occluded = false;
    }
  }

  explicit MocapSegment_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    transform(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->occluded = false;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _transform_type =
    geometry_msgs::msg::Transform_<ContainerAllocator>;
  _transform_type transform;
  using _occluded_type =
    bool;
  _occluded_type occluded;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__transform(
    const geometry_msgs::msg::Transform_<ContainerAllocator> & _arg)
  {
    this->transform = _arg;
    return *this;
  }
  Type & set__occluded(
    const bool & _arg)
  {
    this->occluded = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lightweight_vicon_bridge::msg::MocapSegment_<ContainerAllocator> *;
  using ConstRawPtr =
    const lightweight_vicon_bridge::msg::MocapSegment_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lightweight_vicon_bridge::msg::MocapSegment_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lightweight_vicon_bridge::msg::MocapSegment_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lightweight_vicon_bridge::msg::MocapSegment_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lightweight_vicon_bridge::msg::MocapSegment_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lightweight_vicon_bridge::msg::MocapSegment_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lightweight_vicon_bridge::msg::MocapSegment_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lightweight_vicon_bridge::msg::MocapSegment_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lightweight_vicon_bridge::msg::MocapSegment_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lightweight_vicon_bridge__msg__MocapSegment
    std::shared_ptr<lightweight_vicon_bridge::msg::MocapSegment_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lightweight_vicon_bridge__msg__MocapSegment
    std::shared_ptr<lightweight_vicon_bridge::msg::MocapSegment_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MocapSegment_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->transform != other.transform) {
      return false;
    }
    if (this->occluded != other.occluded) {
      return false;
    }
    return true;
  }
  bool operator!=(const MocapSegment_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MocapSegment_

// alias to use template instance with default allocator
using MocapSegment =
  lightweight_vicon_bridge::msg::MocapSegment_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lightweight_vicon_bridge

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_SEGMENT__STRUCT_HPP_
