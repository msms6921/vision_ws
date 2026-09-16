# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vision_interfaces:msg/DetectedObject.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DetectedObject(type):
    """Metaclass of message 'DetectedObject'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vision_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vision_interfaces.msg.DetectedObject')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__detected_object
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__detected_object
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__detected_object
            cls._TYPE_SUPPORT = module.type_support_msg__msg__detected_object
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__detected_object

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectedObject(metaclass=Metaclass_DetectedObject):
    """Message class 'DetectedObject'."""

    __slots__ = [
        '_header',
        '_class_name',
        '_class_id',
        '_confidence',
        '_bbox_x1',
        '_bbox_y1',
        '_bbox_x2',
        '_bbox_y2',
        '_center_u',
        '_center_v',
        '_position',
        '_distance',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'class_name': 'string',
        'class_id': 'int32',
        'confidence': 'float',
        'bbox_x1': 'float',
        'bbox_y1': 'float',
        'bbox_x2': 'float',
        'bbox_y2': 'float',
        'center_u': 'float',
        'center_v': 'float',
        'position': 'geometry_msgs/Point',
        'distance': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.class_name = kwargs.get('class_name', str())
        self.class_id = kwargs.get('class_id', int())
        self.confidence = kwargs.get('confidence', float())
        self.bbox_x1 = kwargs.get('bbox_x1', float())
        self.bbox_y1 = kwargs.get('bbox_y1', float())
        self.bbox_x2 = kwargs.get('bbox_x2', float())
        self.bbox_y2 = kwargs.get('bbox_y2', float())
        self.center_u = kwargs.get('center_u', float())
        self.center_v = kwargs.get('center_v', float())
        from geometry_msgs.msg import Point
        self.position = kwargs.get('position', Point())
        self.distance = kwargs.get('distance', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.class_name != other.class_name:
            return False
        if self.class_id != other.class_id:
            return False
        if self.confidence != other.confidence:
            return False
        if self.bbox_x1 != other.bbox_x1:
            return False
        if self.bbox_y1 != other.bbox_y1:
            return False
        if self.bbox_x2 != other.bbox_x2:
            return False
        if self.bbox_y2 != other.bbox_y2:
            return False
        if self.center_u != other.center_u:
            return False
        if self.center_v != other.center_v:
            return False
        if self.position != other.position:
            return False
        if self.distance != other.distance:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def class_name(self):
        """Message field 'class_name'."""
        return self._class_name

    @class_name.setter
    def class_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'class_name' field must be of type 'str'"
        self._class_name = value

    @builtins.property
    def class_id(self):
        """Message field 'class_id'."""
        return self._class_id

    @class_id.setter
    def class_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'class_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'class_id' field must be an integer in [-2147483648, 2147483647]"
        self._class_id = value

    @builtins.property
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'confidence' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._confidence = value

    @builtins.property
    def bbox_x1(self):
        """Message field 'bbox_x1'."""
        return self._bbox_x1

    @bbox_x1.setter
    def bbox_x1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bbox_x1' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_x1' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_x1 = value

    @builtins.property
    def bbox_y1(self):
        """Message field 'bbox_y1'."""
        return self._bbox_y1

    @bbox_y1.setter
    def bbox_y1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bbox_y1' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_y1' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_y1 = value

    @builtins.property
    def bbox_x2(self):
        """Message field 'bbox_x2'."""
        return self._bbox_x2

    @bbox_x2.setter
    def bbox_x2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bbox_x2' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_x2' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_x2 = value

    @builtins.property
    def bbox_y2(self):
        """Message field 'bbox_y2'."""
        return self._bbox_y2

    @bbox_y2.setter
    def bbox_y2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bbox_y2' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_y2' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_y2 = value

    @builtins.property
    def center_u(self):
        """Message field 'center_u'."""
        return self._center_u

    @center_u.setter
    def center_u(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'center_u' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'center_u' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._center_u = value

    @builtins.property
    def center_v(self):
        """Message field 'center_v'."""
        return self._center_v

    @center_v.setter
    def center_v(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'center_v' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'center_v' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._center_v = value

    @builtins.property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'position' field must be a sub message of type 'Point'"
        self._position = value

    @builtins.property
    def distance(self):
        """Message field 'distance'."""
        return self._distance

    @distance.setter
    def distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'distance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'distance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._distance = value
