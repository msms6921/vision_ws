// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vision_interfaces:msg/DetectedObject.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT__STRUCT_HPP_
#define VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vision_interfaces__msg__DetectedObject __attribute__((deprecated))
#else
# define DEPRECATED__vision_interfaces__msg__DetectedObject __declspec(deprecated)
#endif

namespace vision_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectedObject_
{
  using Type = DetectedObject_<ContainerAllocator>;

  explicit DetectedObject_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->class_name = "";
      this->class_id = 0l;
      this->confidence = 0.0f;
      this->bbox_x1 = 0.0f;
      this->bbox_y1 = 0.0f;
      this->bbox_x2 = 0.0f;
      this->bbox_y2 = 0.0f;
      this->center_u = 0.0f;
      this->center_v = 0.0f;
      this->distance = 0.0f;
    }
  }

  explicit DetectedObject_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    class_name(_alloc),
    position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->class_name = "";
      this->class_id = 0l;
      this->confidence = 0.0f;
      this->bbox_x1 = 0.0f;
      this->bbox_y1 = 0.0f;
      this->bbox_x2 = 0.0f;
      this->bbox_y2 = 0.0f;
      this->center_u = 0.0f;
      this->center_v = 0.0f;
      this->distance = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _class_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _class_name_type class_name;
  using _class_id_type =
    int32_t;
  _class_id_type class_id;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _bbox_x1_type =
    float;
  _bbox_x1_type bbox_x1;
  using _bbox_y1_type =
    float;
  _bbox_y1_type bbox_y1;
  using _bbox_x2_type =
    float;
  _bbox_x2_type bbox_x2;
  using _bbox_y2_type =
    float;
  _bbox_y2_type bbox_y2;
  using _center_u_type =
    float;
  _center_u_type center_u;
  using _center_v_type =
    float;
  _center_v_type center_v;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _distance_type =
    float;
  _distance_type distance;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__class_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->class_name = _arg;
    return *this;
  }
  Type & set__class_id(
    const int32_t & _arg)
  {
    this->class_id = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__bbox_x1(
    const float & _arg)
  {
    this->bbox_x1 = _arg;
    return *this;
  }
  Type & set__bbox_y1(
    const float & _arg)
  {
    this->bbox_y1 = _arg;
    return *this;
  }
  Type & set__bbox_x2(
    const float & _arg)
  {
    this->bbox_x2 = _arg;
    return *this;
  }
  Type & set__bbox_y2(
    const float & _arg)
  {
    this->bbox_y2 = _arg;
    return *this;
  }
  Type & set__center_u(
    const float & _arg)
  {
    this->center_u = _arg;
    return *this;
  }
  Type & set__center_v(
    const float & _arg)
  {
    this->center_v = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__distance(
    const float & _arg)
  {
    this->distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vision_interfaces::msg::DetectedObject_<ContainerAllocator> *;
  using ConstRawPtr =
    const vision_interfaces::msg::DetectedObject_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vision_interfaces::msg::DetectedObject_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vision_interfaces::msg::DetectedObject_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vision_interfaces::msg::DetectedObject_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vision_interfaces::msg::DetectedObject_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vision_interfaces::msg::DetectedObject_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vision_interfaces::msg::DetectedObject_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vision_interfaces::msg::DetectedObject_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vision_interfaces::msg::DetectedObject_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vision_interfaces__msg__DetectedObject
    std::shared_ptr<vision_interfaces::msg::DetectedObject_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vision_interfaces__msg__DetectedObject
    std::shared_ptr<vision_interfaces::msg::DetectedObject_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectedObject_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->class_name != other.class_name) {
      return false;
    }
    if (this->class_id != other.class_id) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->bbox_x1 != other.bbox_x1) {
      return false;
    }
    if (this->bbox_y1 != other.bbox_y1) {
      return false;
    }
    if (this->bbox_x2 != other.bbox_x2) {
      return false;
    }
    if (this->bbox_y2 != other.bbox_y2) {
      return false;
    }
    if (this->center_u != other.center_u) {
      return false;
    }
    if (this->center_v != other.center_v) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectedObject_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectedObject_

// alias to use template instance with default allocator
using DetectedObject =
  vision_interfaces::msg::DetectedObject_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vision_interfaces

#endif  // VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT__STRUCT_HPP_
