// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_interfaces:msg/DetectedObjectArray.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT_ARRAY__STRUCT_H_
#define VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'objects'
#include "vision_interfaces/msg/detail/detected_object__struct.h"

/// Struct defined in msg/DetectedObjectArray in the package vision_interfaces.
/**
  * All valid 3D detections produced from one synchronized RGB/depth pair.
 */
typedef struct vision_interfaces__msg__DetectedObjectArray
{
  std_msgs__msg__Header header;
  vision_interfaces__msg__DetectedObject__Sequence objects;
} vision_interfaces__msg__DetectedObjectArray;

// Struct for a sequence of vision_interfaces__msg__DetectedObjectArray.
typedef struct vision_interfaces__msg__DetectedObjectArray__Sequence
{
  vision_interfaces__msg__DetectedObjectArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_interfaces__msg__DetectedObjectArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT_ARRAY__STRUCT_H_
