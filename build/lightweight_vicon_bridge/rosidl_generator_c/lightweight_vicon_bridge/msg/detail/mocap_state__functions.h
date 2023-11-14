// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from lightweight_vicon_bridge:msg/MocapState.idl
// generated code does not contain a copyright notice

#ifndef LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__FUNCTIONS_H_
#define LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "lightweight_vicon_bridge/msg/rosidl_generator_c__visibility_control.h"

#include "lightweight_vicon_bridge/msg/detail/mocap_state__struct.h"

/// Initialize msg/MocapState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lightweight_vicon_bridge__msg__MocapState
 * )) before or use
 * lightweight_vicon_bridge__msg__MocapState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lightweight_vicon_bridge
bool
lightweight_vicon_bridge__msg__MocapState__init(lightweight_vicon_bridge__msg__MocapState * msg);

/// Finalize msg/MocapState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lightweight_vicon_bridge
void
lightweight_vicon_bridge__msg__MocapState__fini(lightweight_vicon_bridge__msg__MocapState * msg);

/// Create msg/MocapState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lightweight_vicon_bridge__msg__MocapState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lightweight_vicon_bridge
lightweight_vicon_bridge__msg__MocapState *
lightweight_vicon_bridge__msg__MocapState__create();

/// Destroy msg/MocapState message.
/**
 * It calls
 * lightweight_vicon_bridge__msg__MocapState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lightweight_vicon_bridge
void
lightweight_vicon_bridge__msg__MocapState__destroy(lightweight_vicon_bridge__msg__MocapState * msg);

/// Check for msg/MocapState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lightweight_vicon_bridge
bool
lightweight_vicon_bridge__msg__MocapState__are_equal(const lightweight_vicon_bridge__msg__MocapState * lhs, const lightweight_vicon_bridge__msg__MocapState * rhs);

/// Copy a msg/MocapState message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_lightweight_vicon_bridge
bool
lightweight_vicon_bridge__msg__MocapState__copy(
  const lightweight_vicon_bridge__msg__MocapState * input,
  lightweight_vicon_bridge__msg__MocapState * output);

/// Initialize array of msg/MocapState messages.
/**
 * It allocates the memory for the number of elements and calls
 * lightweight_vicon_bridge__msg__MocapState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lightweight_vicon_bridge
bool
lightweight_vicon_bridge__msg__MocapState__Sequence__init(lightweight_vicon_bridge__msg__MocapState__Sequence * array, size_t size);

/// Finalize array of msg/MocapState messages.
/**
 * It calls
 * lightweight_vicon_bridge__msg__MocapState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lightweight_vicon_bridge
void
lightweight_vicon_bridge__msg__MocapState__Sequence__fini(lightweight_vicon_bridge__msg__MocapState__Sequence * array);

/// Create array of msg/MocapState messages.
/**
 * It allocates the memory for the array and calls
 * lightweight_vicon_bridge__msg__MocapState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lightweight_vicon_bridge
lightweight_vicon_bridge__msg__MocapState__Sequence *
lightweight_vicon_bridge__msg__MocapState__Sequence__create(size_t size);

/// Destroy array of msg/MocapState messages.
/**
 * It calls
 * lightweight_vicon_bridge__msg__MocapState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lightweight_vicon_bridge
void
lightweight_vicon_bridge__msg__MocapState__Sequence__destroy(lightweight_vicon_bridge__msg__MocapState__Sequence * array);

/// Check for msg/MocapState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lightweight_vicon_bridge
bool
lightweight_vicon_bridge__msg__MocapState__Sequence__are_equal(const lightweight_vicon_bridge__msg__MocapState__Sequence * lhs, const lightweight_vicon_bridge__msg__MocapState__Sequence * rhs);

/// Copy an array of msg/MocapState messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_lightweight_vicon_bridge
bool
lightweight_vicon_bridge__msg__MocapState__Sequence__copy(
  const lightweight_vicon_bridge__msg__MocapState__Sequence * input,
  lightweight_vicon_bridge__msg__MocapState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // LIGHTWEIGHT_VICON_BRIDGE__MSG__DETAIL__MOCAP_STATE__FUNCTIONS_H_
