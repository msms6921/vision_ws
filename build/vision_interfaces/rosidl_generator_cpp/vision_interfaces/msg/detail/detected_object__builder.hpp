// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vision_interfaces:msg/DetectedObject.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT__BUILDER_HPP_
#define VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vision_interfaces/msg/detail/detected_object__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vision_interfaces
{

namespace msg
{

namespace builder
{

class Init_DetectedObject_distance
{
public:
  explicit Init_DetectedObject_distance(::vision_interfaces::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  ::vision_interfaces::msg::DetectedObject distance(::vision_interfaces::msg::DetectedObject::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vision_interfaces::msg::DetectedObject msg_;
};

class Init_DetectedObject_position
{
public:
  explicit Init_DetectedObject_position(::vision_interfaces::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_distance position(::vision_interfaces::msg::DetectedObject::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_DetectedObject_distance(msg_);
  }

private:
  ::vision_interfaces::msg::DetectedObject msg_;
};

class Init_DetectedObject_center_v
{
public:
  explicit Init_DetectedObject_center_v(::vision_interfaces::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_position center_v(::vision_interfaces::msg::DetectedObject::_center_v_type arg)
  {
    msg_.center_v = std::move(arg);
    return Init_DetectedObject_position(msg_);
  }

private:
  ::vision_interfaces::msg::DetectedObject msg_;
};

class Init_DetectedObject_center_u
{
public:
  explicit Init_DetectedObject_center_u(::vision_interfaces::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_center_v center_u(::vision_interfaces::msg::DetectedObject::_center_u_type arg)
  {
    msg_.center_u = std::move(arg);
    return Init_DetectedObject_center_v(msg_);
  }

private:
  ::vision_interfaces::msg::DetectedObject msg_;
};

class Init_DetectedObject_bbox_y2
{
public:
  explicit Init_DetectedObject_bbox_y2(::vision_interfaces::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_center_u bbox_y2(::vision_interfaces::msg::DetectedObject::_bbox_y2_type arg)
  {
    msg_.bbox_y2 = std::move(arg);
    return Init_DetectedObject_center_u(msg_);
  }

private:
  ::vision_interfaces::msg::DetectedObject msg_;
};

class Init_DetectedObject_bbox_x2
{
public:
  explicit Init_DetectedObject_bbox_x2(::vision_interfaces::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_bbox_y2 bbox_x2(::vision_interfaces::msg::DetectedObject::_bbox_x2_type arg)
  {
    msg_.bbox_x2 = std::move(arg);
    return Init_DetectedObject_bbox_y2(msg_);
  }

private:
  ::vision_interfaces::msg::DetectedObject msg_;
};

class Init_DetectedObject_bbox_y1
{
public:
  explicit Init_DetectedObject_bbox_y1(::vision_interfaces::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_bbox_x2 bbox_y1(::vision_interfaces::msg::DetectedObject::_bbox_y1_type arg)
  {
    msg_.bbox_y1 = std::move(arg);
    return Init_DetectedObject_bbox_x2(msg_);
  }

private:
  ::vision_interfaces::msg::DetectedObject msg_;
};

class Init_DetectedObject_bbox_x1
{
public:
  explicit Init_DetectedObject_bbox_x1(::vision_interfaces::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_bbox_y1 bbox_x1(::vision_interfaces::msg::DetectedObject::_bbox_x1_type arg)
  {
    msg_.bbox_x1 = std::move(arg);
    return Init_DetectedObject_bbox_y1(msg_);
  }

private:
  ::vision_interfaces::msg::DetectedObject msg_;
};

class Init_DetectedObject_confidence
{
public:
  explicit Init_DetectedObject_confidence(::vision_interfaces::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_bbox_x1 confidence(::vision_interfaces::msg::DetectedObject::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_DetectedObject_bbox_x1(msg_);
  }

private:
  ::vision_interfaces::msg::DetectedObject msg_;
};

class Init_DetectedObject_class_id
{
public:
  explicit Init_DetectedObject_class_id(::vision_interfaces::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_confidence class_id(::vision_interfaces::msg::DetectedObject::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return Init_DetectedObject_confidence(msg_);
  }

private:
  ::vision_interfaces::msg::DetectedObject msg_;
};

class Init_DetectedObject_class_name
{
public:
  explicit Init_DetectedObject_class_name(::vision_interfaces::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_class_id class_name(::vision_interfaces::msg::DetectedObject::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return Init_DetectedObject_class_id(msg_);
  }

private:
  ::vision_interfaces::msg::DetectedObject msg_;
};

class Init_DetectedObject_header
{
public:
  Init_DetectedObject_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectedObject_class_name header(::vision_interfaces::msg::DetectedObject::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DetectedObject_class_name(msg_);
  }

private:
  ::vision_interfaces::msg::DetectedObject msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vision_interfaces::msg::DetectedObject>()
{
  return vision_interfaces::msg::builder::Init_DetectedObject_header();
}

}  // namespace vision_interfaces

#endif  // VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT__BUILDER_HPP_
