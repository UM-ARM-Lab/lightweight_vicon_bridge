// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lightweight_vicon_bridge:msg/MocapSegment.idl
// generated code does not contain a copyright notice
#include "lightweight_vicon_bridge/msg/detail/mocap_segment__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `transform`
#include "geometry_msgs/msg/detail/transform__functions.h"

bool
lightweight_vicon_bridge__msg__MocapSegment__init(lightweight_vicon_bridge__msg__MocapSegment * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    lightweight_vicon_bridge__msg__MocapSegment__fini(msg);
    return false;
  }
  // transform
  if (!geometry_msgs__msg__Transform__init(&msg->transform)) {
    lightweight_vicon_bridge__msg__MocapSegment__fini(msg);
    return false;
  }
  // occluded
  return true;
}

void
lightweight_vicon_bridge__msg__MocapSegment__fini(lightweight_vicon_bridge__msg__MocapSegment * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // transform
  geometry_msgs__msg__Transform__fini(&msg->transform);
  // occluded
}

bool
lightweight_vicon_bridge__msg__MocapSegment__are_equal(const lightweight_vicon_bridge__msg__MocapSegment * lhs, const lightweight_vicon_bridge__msg__MocapSegment * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // transform
  if (!geometry_msgs__msg__Transform__are_equal(
      &(lhs->transform), &(rhs->transform)))
  {
    return false;
  }
  // occluded
  if (lhs->occluded != rhs->occluded) {
    return false;
  }
  return true;
}

bool
lightweight_vicon_bridge__msg__MocapSegment__copy(
  const lightweight_vicon_bridge__msg__MocapSegment * input,
  lightweight_vicon_bridge__msg__MocapSegment * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // transform
  if (!geometry_msgs__msg__Transform__copy(
      &(input->transform), &(output->transform)))
  {
    return false;
  }
  // occluded
  output->occluded = input->occluded;
  return true;
}

lightweight_vicon_bridge__msg__MocapSegment *
lightweight_vicon_bridge__msg__MocapSegment__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lightweight_vicon_bridge__msg__MocapSegment * msg = (lightweight_vicon_bridge__msg__MocapSegment *)allocator.allocate(sizeof(lightweight_vicon_bridge__msg__MocapSegment), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lightweight_vicon_bridge__msg__MocapSegment));
  bool success = lightweight_vicon_bridge__msg__MocapSegment__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lightweight_vicon_bridge__msg__MocapSegment__destroy(lightweight_vicon_bridge__msg__MocapSegment * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lightweight_vicon_bridge__msg__MocapSegment__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lightweight_vicon_bridge__msg__MocapSegment__Sequence__init(lightweight_vicon_bridge__msg__MocapSegment__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lightweight_vicon_bridge__msg__MocapSegment * data = NULL;

  if (size) {
    data = (lightweight_vicon_bridge__msg__MocapSegment *)allocator.zero_allocate(size, sizeof(lightweight_vicon_bridge__msg__MocapSegment), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lightweight_vicon_bridge__msg__MocapSegment__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lightweight_vicon_bridge__msg__MocapSegment__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
lightweight_vicon_bridge__msg__MocapSegment__Sequence__fini(lightweight_vicon_bridge__msg__MocapSegment__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      lightweight_vicon_bridge__msg__MocapSegment__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

lightweight_vicon_bridge__msg__MocapSegment__Sequence *
lightweight_vicon_bridge__msg__MocapSegment__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lightweight_vicon_bridge__msg__MocapSegment__Sequence * array = (lightweight_vicon_bridge__msg__MocapSegment__Sequence *)allocator.allocate(sizeof(lightweight_vicon_bridge__msg__MocapSegment__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lightweight_vicon_bridge__msg__MocapSegment__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lightweight_vicon_bridge__msg__MocapSegment__Sequence__destroy(lightweight_vicon_bridge__msg__MocapSegment__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lightweight_vicon_bridge__msg__MocapSegment__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lightweight_vicon_bridge__msg__MocapSegment__Sequence__are_equal(const lightweight_vicon_bridge__msg__MocapSegment__Sequence * lhs, const lightweight_vicon_bridge__msg__MocapSegment__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lightweight_vicon_bridge__msg__MocapSegment__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lightweight_vicon_bridge__msg__MocapSegment__Sequence__copy(
  const lightweight_vicon_bridge__msg__MocapSegment__Sequence * input,
  lightweight_vicon_bridge__msg__MocapSegment__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lightweight_vicon_bridge__msg__MocapSegment);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lightweight_vicon_bridge__msg__MocapSegment * data =
      (lightweight_vicon_bridge__msg__MocapSegment *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lightweight_vicon_bridge__msg__MocapSegment__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lightweight_vicon_bridge__msg__MocapSegment__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lightweight_vicon_bridge__msg__MocapSegment__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
