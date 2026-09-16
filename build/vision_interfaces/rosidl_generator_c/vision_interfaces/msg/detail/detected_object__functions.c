// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vision_interfaces:msg/DetectedObject.idl
// generated code does not contain a copyright notice
#include "vision_interfaces/msg/detail/detected_object__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `class_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
vision_interfaces__msg__DetectedObject__init(vision_interfaces__msg__DetectedObject * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vision_interfaces__msg__DetectedObject__fini(msg);
    return false;
  }
  // class_name
  if (!rosidl_runtime_c__String__init(&msg->class_name)) {
    vision_interfaces__msg__DetectedObject__fini(msg);
    return false;
  }
  // class_id
  // confidence
  // bbox_x1
  // bbox_y1
  // bbox_x2
  // bbox_y2
  // center_u
  // center_v
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    vision_interfaces__msg__DetectedObject__fini(msg);
    return false;
  }
  // distance
  return true;
}

void
vision_interfaces__msg__DetectedObject__fini(vision_interfaces__msg__DetectedObject * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // class_name
  rosidl_runtime_c__String__fini(&msg->class_name);
  // class_id
  // confidence
  // bbox_x1
  // bbox_y1
  // bbox_x2
  // bbox_y2
  // center_u
  // center_v
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // distance
}

bool
vision_interfaces__msg__DetectedObject__are_equal(const vision_interfaces__msg__DetectedObject * lhs, const vision_interfaces__msg__DetectedObject * rhs)
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
  // class_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->class_name), &(rhs->class_name)))
  {
    return false;
  }
  // class_id
  if (lhs->class_id != rhs->class_id) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // bbox_x1
  if (lhs->bbox_x1 != rhs->bbox_x1) {
    return false;
  }
  // bbox_y1
  if (lhs->bbox_y1 != rhs->bbox_y1) {
    return false;
  }
  // bbox_x2
  if (lhs->bbox_x2 != rhs->bbox_x2) {
    return false;
  }
  // bbox_y2
  if (lhs->bbox_y2 != rhs->bbox_y2) {
    return false;
  }
  // center_u
  if (lhs->center_u != rhs->center_u) {
    return false;
  }
  // center_v
  if (lhs->center_v != rhs->center_v) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  return true;
}

bool
vision_interfaces__msg__DetectedObject__copy(
  const vision_interfaces__msg__DetectedObject * input,
  vision_interfaces__msg__DetectedObject * output)
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
  // class_name
  if (!rosidl_runtime_c__String__copy(
      &(input->class_name), &(output->class_name)))
  {
    return false;
  }
  // class_id
  output->class_id = input->class_id;
  // confidence
  output->confidence = input->confidence;
  // bbox_x1
  output->bbox_x1 = input->bbox_x1;
  // bbox_y1
  output->bbox_y1 = input->bbox_y1;
  // bbox_x2
  output->bbox_x2 = input->bbox_x2;
  // bbox_y2
  output->bbox_y2 = input->bbox_y2;
  // center_u
  output->center_u = input->center_u;
  // center_v
  output->center_v = input->center_v;
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // distance
  output->distance = input->distance;
  return true;
}

vision_interfaces__msg__DetectedObject *
vision_interfaces__msg__DetectedObject__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interfaces__msg__DetectedObject * msg = (vision_interfaces__msg__DetectedObject *)allocator.allocate(sizeof(vision_interfaces__msg__DetectedObject), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vision_interfaces__msg__DetectedObject));
  bool success = vision_interfaces__msg__DetectedObject__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vision_interfaces__msg__DetectedObject__destroy(vision_interfaces__msg__DetectedObject * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vision_interfaces__msg__DetectedObject__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vision_interfaces__msg__DetectedObject__Sequence__init(vision_interfaces__msg__DetectedObject__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interfaces__msg__DetectedObject * data = NULL;

  if (size) {
    data = (vision_interfaces__msg__DetectedObject *)allocator.zero_allocate(size, sizeof(vision_interfaces__msg__DetectedObject), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vision_interfaces__msg__DetectedObject__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vision_interfaces__msg__DetectedObject__fini(&data[i - 1]);
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
vision_interfaces__msg__DetectedObject__Sequence__fini(vision_interfaces__msg__DetectedObject__Sequence * array)
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
      vision_interfaces__msg__DetectedObject__fini(&array->data[i]);
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

vision_interfaces__msg__DetectedObject__Sequence *
vision_interfaces__msg__DetectedObject__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interfaces__msg__DetectedObject__Sequence * array = (vision_interfaces__msg__DetectedObject__Sequence *)allocator.allocate(sizeof(vision_interfaces__msg__DetectedObject__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vision_interfaces__msg__DetectedObject__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vision_interfaces__msg__DetectedObject__Sequence__destroy(vision_interfaces__msg__DetectedObject__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vision_interfaces__msg__DetectedObject__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vision_interfaces__msg__DetectedObject__Sequence__are_equal(const vision_interfaces__msg__DetectedObject__Sequence * lhs, const vision_interfaces__msg__DetectedObject__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vision_interfaces__msg__DetectedObject__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vision_interfaces__msg__DetectedObject__Sequence__copy(
  const vision_interfaces__msg__DetectedObject__Sequence * input,
  vision_interfaces__msg__DetectedObject__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vision_interfaces__msg__DetectedObject);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vision_interfaces__msg__DetectedObject * data =
      (vision_interfaces__msg__DetectedObject *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vision_interfaces__msg__DetectedObject__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vision_interfaces__msg__DetectedObject__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vision_interfaces__msg__DetectedObject__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
