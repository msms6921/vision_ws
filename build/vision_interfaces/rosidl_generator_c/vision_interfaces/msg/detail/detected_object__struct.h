// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_interfaces:msg/DetectedObject.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT__STRUCT_H_
#define VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT__STRUCT_H_

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
// Member 'class_name'
#include "rosidl_runtime_c/string.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/DetectedObject in the package vision_interfaces.
/**
  * One YOLO detection expressed in the camera optical frame.
 */
typedef struct vision_interfaces__msg__DetectedObject
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String class_name;
  int32_t class_id;
  float confidence;
  float bbox_x1;
  float bbox_y1;
  float bbox_x2;
  float bbox_y2;
  float center_u;
  float center_v;
  geometry_msgs__msg__Point position;
  float distance;
} vision_interfaces__msg__DetectedObject;

// Struct for a sequence of vision_interfaces__msg__DetectedObject.
typedef struct vision_interfaces__msg__DetectedObject__Sequence
{
  vision_interfaces__msg__DetectedObject * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_interfaces__msg__DetectedObject__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT__STRUCT_H_
