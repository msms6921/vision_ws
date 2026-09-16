#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "vision_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vision_interfaces__msg__DetectedObject() -> *const std::ffi::c_void;
}

#[link(name = "vision_interfaces__rosidl_generator_c")]
extern "C" {
    fn vision_interfaces__msg__DetectedObject__init(msg: *mut DetectedObject) -> bool;
    fn vision_interfaces__msg__DetectedObject__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DetectedObject>, size: usize) -> bool;
    fn vision_interfaces__msg__DetectedObject__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DetectedObject>);
    fn vision_interfaces__msg__DetectedObject__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DetectedObject>, out_seq: *mut rosidl_runtime_rs::Sequence<DetectedObject>) -> bool;
}

// Corresponds to vision_interfaces__msg__DetectedObject
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// One YOLO detection expressed in the camera optical frame.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DetectedObject {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub class_name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub class_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_x1: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_y1: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_x2: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_y2: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center_u: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center_v: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub position: geometry_msgs::msg::rmw::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance: f32,

}



impl Default for DetectedObject {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vision_interfaces__msg__DetectedObject__init(&mut msg as *mut _) {
        panic!("Call to vision_interfaces__msg__DetectedObject__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DetectedObject {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vision_interfaces__msg__DetectedObject__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vision_interfaces__msg__DetectedObject__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vision_interfaces__msg__DetectedObject__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DetectedObject {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DetectedObject where Self: Sized {
  const TYPE_NAME: &'static str = "vision_interfaces/msg/DetectedObject";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vision_interfaces__msg__DetectedObject() }
  }
}


#[link(name = "vision_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vision_interfaces__msg__DetectedObjectArray() -> *const std::ffi::c_void;
}

#[link(name = "vision_interfaces__rosidl_generator_c")]
extern "C" {
    fn vision_interfaces__msg__DetectedObjectArray__init(msg: *mut DetectedObjectArray) -> bool;
    fn vision_interfaces__msg__DetectedObjectArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DetectedObjectArray>, size: usize) -> bool;
    fn vision_interfaces__msg__DetectedObjectArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DetectedObjectArray>);
    fn vision_interfaces__msg__DetectedObjectArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DetectedObjectArray>, out_seq: *mut rosidl_runtime_rs::Sequence<DetectedObjectArray>) -> bool;
}

// Corresponds to vision_interfaces__msg__DetectedObjectArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// All valid 3D detections produced from one synchronized RGB/depth pair.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DetectedObjectArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub objects: rosidl_runtime_rs::Sequence<super::super::msg::rmw::DetectedObject>,

}



impl Default for DetectedObjectArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vision_interfaces__msg__DetectedObjectArray__init(&mut msg as *mut _) {
        panic!("Call to vision_interfaces__msg__DetectedObjectArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DetectedObjectArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vision_interfaces__msg__DetectedObjectArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vision_interfaces__msg__DetectedObjectArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vision_interfaces__msg__DetectedObjectArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DetectedObjectArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DetectedObjectArray where Self: Sized {
  const TYPE_NAME: &'static str = "vision_interfaces/msg/DetectedObjectArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vision_interfaces__msg__DetectedObjectArray() }
  }
}


