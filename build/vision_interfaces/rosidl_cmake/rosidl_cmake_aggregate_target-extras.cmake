# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target vision_interfaces::vision_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${vision_interfaces_TARGETS}.
if(vision_interfaces_TARGETS AND NOT TARGET vision_interfaces::vision_interfaces)
  add_library(vision_interfaces::vision_interfaces INTERFACE IMPORTED)
  set_target_properties(vision_interfaces::vision_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${vision_interfaces_TARGETS}")
endif()
