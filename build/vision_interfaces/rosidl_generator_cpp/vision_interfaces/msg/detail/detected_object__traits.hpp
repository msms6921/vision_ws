// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vision_interfaces:msg/DetectedObject.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT__TRAITS_HPP_
#define VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vision_interfaces/msg/detail/detected_object__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace vision_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectedObject & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: class_name
  {
    out << "class_name: ";
    rosidl_generator_traits::value_to_yaml(msg.class_name, out);
    out << ", ";
  }

  // member: class_id
  {
    out << "class_id: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: bbox_x1
  {
    out << "bbox_x1: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_x1, out);
    out << ", ";
  }

  // member: bbox_y1
  {
    out << "bbox_y1: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_y1, out);
    out << ", ";
  }

  // member: bbox_x2
  {
    out << "bbox_x2: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_x2, out);
    out << ", ";
  }

  // member: bbox_y2
  {
    out << "bbox_y2: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_y2, out);
    out << ", ";
  }

  // member: center_u
  {
    out << "center_u: ";
    rosidl_generator_traits::value_to_yaml(msg.center_u, out);
    out << ", ";
  }

  // member: center_v
  {
    out << "center_v: ";
    rosidl_generator_traits::value_to_yaml(msg.center_v, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectedObject & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: class_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "class_name: ";
    rosidl_generator_traits::value_to_yaml(msg.class_name, out);
    out << "\n";
  }

  // member: class_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "class_id: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: bbox_x1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_x1: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_x1, out);
    out << "\n";
  }

  // member: bbox_y1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_y1: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_y1, out);
    out << "\n";
  }

  // member: bbox_x2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_x2: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_x2, out);
    out << "\n";
  }

  // member: bbox_y2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_y2: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_y2, out);
    out << "\n";
  }

  // member: center_u
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_u: ";
    rosidl_generator_traits::value_to_yaml(msg.center_u, out);
    out << "\n";
  }

  // member: center_v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_v: ";
    rosidl_generator_traits::value_to_yaml(msg.center_v, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectedObject & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace vision_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use vision_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vision_interfaces::msg::DetectedObject & msg,
  std::ostream & out, size_t indentation = 0)
{
  vision_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vision_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const vision_interfaces::msg::DetectedObject & msg)
{
  return vision_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vision_interfaces::msg::DetectedObject>()
{
  return "vision_interfaces::msg::DetectedObject";
}

template<>
inline const char * name<vision_interfaces::msg::DetectedObject>()
{
  return "vision_interfaces/msg/DetectedObject";
}

template<>
struct has_fixed_size<vision_interfaces::msg::DetectedObject>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vision_interfaces::msg::DetectedObject>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vision_interfaces::msg::DetectedObject>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VISION_INTERFACES__MSG__DETAIL__DETECTED_OBJECT__TRAITS_HPP_
