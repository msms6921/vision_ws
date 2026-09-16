#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to vision_interfaces__msg__DetectedObject
/// One YOLO detection expressed in the camera optical frame.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DetectedObject {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub class_name: std::string::String,


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
    pub position: geometry_msgs::msg::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance: f32,

}



impl Default for DetectedObject {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DetectedObject::default())
  }
}

impl rosidl_runtime_rs::Message for DetectedObject {
  type RmwMsg = super::msg::rmw::DetectedObject;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        class_name: msg.class_name.as_str().into(),
        class_id: msg.class_id,
        confidence: msg.confidence,
        bbox_x1: msg.bbox_x1,
        bbox_y1: msg.bbox_y1,
        bbox_x2: msg.bbox_x2,
        bbox_y2: msg.bbox_y2,
        center_u: msg.center_u,
        center_v: msg.center_v,
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.position)).into_owned(),
        distance: msg.distance,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        class_name: msg.class_name.as_str().into(),
      class_id: msg.class_id,
      confidence: msg.confidence,
      bbox_x1: msg.bbox_x1,
      bbox_y1: msg.bbox_y1,
      bbox_x2: msg.bbox_x2,
      bbox_y2: msg.bbox_y2,
      center_u: msg.center_u,
      center_v: msg.center_v,
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.position)).into_owned(),
      distance: msg.distance,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      class_name: msg.class_name.to_string(),
      class_id: msg.class_id,
      confidence: msg.confidence,
      bbox_x1: msg.bbox_x1,
      bbox_y1: msg.bbox_y1,
      bbox_x2: msg.bbox_x2,
      bbox_y2: msg.bbox_y2,
      center_u: msg.center_u,
      center_v: msg.center_v,
      position: geometry_msgs::msg::Point::from_rmw_message(msg.position),
      distance: msg.distance,
    }
  }
}


// Corresponds to vision_interfaces__msg__DetectedObjectArray
/// All valid 3D detections produced from one synchronized RGB/depth pair.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DetectedObjectArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub objects: Vec<super::msg::DetectedObject>,

}



impl Default for DetectedObjectArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DetectedObjectArray::default())
  }
}

impl rosidl_runtime_rs::Message for DetectedObjectArray {
  type RmwMsg = super::msg::rmw::DetectedObjectArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        objects: msg.objects
          .into_iter()
          .map(|elem| super::msg::DetectedObject::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        objects: msg.objects
          .iter()
          .map(|elem| super::msg::DetectedObject::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      objects: msg.objects
          .into_iter()
          .map(super::msg::DetectedObject::from_rmw_message)
          .collect(),
    }
  }
}


