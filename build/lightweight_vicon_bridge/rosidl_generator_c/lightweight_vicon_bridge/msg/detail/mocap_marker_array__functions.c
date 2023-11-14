// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lightweight_vicon_bridge:msg/MocapMarkerArray.idl
// generated code does not contain a copyright notice
#include "lightweight_vicon_bridge/msg/detail/mocap_marker_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `tracker_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `markers`
#include "lightweight_vicon_bridge/msg/detail/mocap_marker__functions.h"

bool
lightweight_vicon_bridge__msg__MocapMarkerArray__init(lightweight_vicon_bridge__msg__MocapMarkerArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    lightweight_vicon_bridge__msg__MocapMarkerArray__fini(msg);
    return false;
  }
  // tracker_name
  if (!rosidl_runtime_c__String__init(&msg->tracker_name)) {
    lightweight_vicon_bridge__msg__MocapMarkerArray__fini(msg);
    return false;
  }
  // markers
  if (!lightweight_vicon_bridge__msg__MocapMarker__Sequence__init(&msg->markers, 0)) {
    lightweight_vicon_bridge__msg__MocapMarkerArray__fini(msg);
    return false;
  }
  return true;
}

void
lightweight_vicon_bridge__msg__MocapMarkerArray__fini(lightweight_vicon_bridge__msg__MocapMarkerArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // tracker_name
  rosidl_runtime_c__String__fini(&msg->tracker_name);
  // markers
  lightweight_vicon_bridge__msg__MocapMarker__Sequence__fini(&msg->markers);
}

bool
lightweight_vicon_bridge__msg__MocapMarkerArray__are_equal(const lightweight_vicon_bridge__msg__MocapMarkerArray * lhs, const lightweight_vicon_bridge__msg__MocapMarkerArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // tracker_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->tracker_name), &(rhs->tracker_name)))
  {
    return false;
  }
  // markers
  if (!lightweight_vicon_bridge__msg__MocapMarker__Sequence__are_equal(
      &(lhs->markers), &(rhs->markers)))
  {
    return false;
  }
  return true;
}

bool
lightweight_vicon_bridge__msg__MocapMarkerArray__copy(
  const lightweight_vicon_bridge__msg__MocapMarkerArray * input,
  lightweight_vicon_bridge__msg__MocapMarkerArray * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // tracker_name
  if (!rosidl_runtime_c__String__copy(
      &(input->tracker_name), &(output->tracker_name)))
  {
    return false;
  }
  // markers
  if (!lightweight_vicon_bridge__msg__MocapMarker__Sequence__copy(
      &(input->markers), &(output->markers)))
  {
    return false;
  }
  return true;
}

lightweight_vicon_bridge__msg__MocapMarkerArray *
lightweight_vicon_bridge__msg__MocapMarkerArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lightweight_vicon_bridge__msg__MocapMarkerArray * msg = (lightweight_vicon_bridge__msg__MocapMarkerArray *)allocator.allocate(sizeof(lightweight_vicon_bridge__msg__MocapMarkerArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lightweight_vicon_bridge__msg__MocapMarkerArray));
  bool success = lightweight_vicon_bridge__msg__MocapMarkerArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lightweight_vicon_bridge__msg__MocapMarkerArray__destroy(lightweight_vicon_bridge__msg__MocapMarkerArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lightweight_vicon_bridge__msg__MocapMarkerArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence__init(lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lightweight_vicon_bridge__msg__MocapMarkerArray * data = NULL;

  if (size) {
    data = (lightweight_vicon_bridge__msg__MocapMarkerArray *)allocator.zero_allocate(size, sizeof(lightweight_vicon_bridge__msg__MocapMarkerArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lightweight_vicon_bridge__msg__MocapMarkerArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lightweight_vicon_bridge__msg__MocapMarkerArray__fini(&data[i - 1]);
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
lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence__fini(lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence * array)
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
      lightweight_vicon_bridge__msg__MocapMarkerArray__fini(&array->data[i]);
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

lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence *
lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence * array = (lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence *)allocator.allocate(sizeof(lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence__destroy(lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence__are_equal(const lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence * lhs, const lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lightweight_vicon_bridge__msg__MocapMarkerArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence__copy(
  const lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence * input,
  lightweight_vicon_bridge__msg__MocapMarkerArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lightweight_vicon_bridge__msg__MocapMarkerArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lightweight_vicon_bridge__msg__MocapMarkerArray * data =
      (lightweight_vicon_bridge__msg__MocapMarkerArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lightweight_vicon_bridge__msg__MocapMarkerArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lightweight_vicon_bridge__msg__MocapMarkerArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lightweight_vicon_bridge__msg__MocapMarkerArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
