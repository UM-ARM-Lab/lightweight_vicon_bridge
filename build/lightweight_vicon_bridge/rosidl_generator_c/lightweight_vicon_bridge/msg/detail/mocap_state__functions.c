// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lightweight_vicon_bridge:msg/MocapState.idl
// generated code does not contain a copyright notice
#include "lightweight_vicon_bridge/msg/detail/mocap_state__functions.h"

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
// Member `tracked_objects`
#include "lightweight_vicon_bridge/msg/detail/mocap_object__functions.h"

bool
lightweight_vicon_bridge__msg__MocapState__init(lightweight_vicon_bridge__msg__MocapState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    lightweight_vicon_bridge__msg__MocapState__fini(msg);
    return false;
  }
  // tracker_name
  if (!rosidl_runtime_c__String__init(&msg->tracker_name)) {
    lightweight_vicon_bridge__msg__MocapState__fini(msg);
    return false;
  }
  // tracked_objects
  if (!lightweight_vicon_bridge__msg__MocapObject__init(&msg->tracked_objects)) {
    lightweight_vicon_bridge__msg__MocapState__fini(msg);
    return false;
  }
  return true;
}

void
lightweight_vicon_bridge__msg__MocapState__fini(lightweight_vicon_bridge__msg__MocapState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // tracker_name
  rosidl_runtime_c__String__fini(&msg->tracker_name);
  // tracked_objects
  lightweight_vicon_bridge__msg__MocapObject__fini(&msg->tracked_objects);
}

bool
lightweight_vicon_bridge__msg__MocapState__are_equal(const lightweight_vicon_bridge__msg__MocapState * lhs, const lightweight_vicon_bridge__msg__MocapState * rhs)
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
  // tracked_objects
  if (!lightweight_vicon_bridge__msg__MocapObject__are_equal(
      &(lhs->tracked_objects), &(rhs->tracked_objects)))
  {
    return false;
  }
  return true;
}

bool
lightweight_vicon_bridge__msg__MocapState__copy(
  const lightweight_vicon_bridge__msg__MocapState * input,
  lightweight_vicon_bridge__msg__MocapState * output)
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
  // tracked_objects
  if (!lightweight_vicon_bridge__msg__MocapObject__copy(
      &(input->tracked_objects), &(output->tracked_objects)))
  {
    return false;
  }
  return true;
}

lightweight_vicon_bridge__msg__MocapState *
lightweight_vicon_bridge__msg__MocapState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lightweight_vicon_bridge__msg__MocapState * msg = (lightweight_vicon_bridge__msg__MocapState *)allocator.allocate(sizeof(lightweight_vicon_bridge__msg__MocapState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lightweight_vicon_bridge__msg__MocapState));
  bool success = lightweight_vicon_bridge__msg__MocapState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lightweight_vicon_bridge__msg__MocapState__destroy(lightweight_vicon_bridge__msg__MocapState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lightweight_vicon_bridge__msg__MocapState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lightweight_vicon_bridge__msg__MocapState__Sequence__init(lightweight_vicon_bridge__msg__MocapState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lightweight_vicon_bridge__msg__MocapState * data = NULL;

  if (size) {
    data = (lightweight_vicon_bridge__msg__MocapState *)allocator.zero_allocate(size, sizeof(lightweight_vicon_bridge__msg__MocapState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lightweight_vicon_bridge__msg__MocapState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lightweight_vicon_bridge__msg__MocapState__fini(&data[i - 1]);
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
lightweight_vicon_bridge__msg__MocapState__Sequence__fini(lightweight_vicon_bridge__msg__MocapState__Sequence * array)
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
      lightweight_vicon_bridge__msg__MocapState__fini(&array->data[i]);
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

lightweight_vicon_bridge__msg__MocapState__Sequence *
lightweight_vicon_bridge__msg__MocapState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lightweight_vicon_bridge__msg__MocapState__Sequence * array = (lightweight_vicon_bridge__msg__MocapState__Sequence *)allocator.allocate(sizeof(lightweight_vicon_bridge__msg__MocapState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lightweight_vicon_bridge__msg__MocapState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lightweight_vicon_bridge__msg__MocapState__Sequence__destroy(lightweight_vicon_bridge__msg__MocapState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lightweight_vicon_bridge__msg__MocapState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lightweight_vicon_bridge__msg__MocapState__Sequence__are_equal(const lightweight_vicon_bridge__msg__MocapState__Sequence * lhs, const lightweight_vicon_bridge__msg__MocapState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lightweight_vicon_bridge__msg__MocapState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lightweight_vicon_bridge__msg__MocapState__Sequence__copy(
  const lightweight_vicon_bridge__msg__MocapState__Sequence * input,
  lightweight_vicon_bridge__msg__MocapState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lightweight_vicon_bridge__msg__MocapState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lightweight_vicon_bridge__msg__MocapState * data =
      (lightweight_vicon_bridge__msg__MocapState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lightweight_vicon_bridge__msg__MocapState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lightweight_vicon_bridge__msg__MocapState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lightweight_vicon_bridge__msg__MocapState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
