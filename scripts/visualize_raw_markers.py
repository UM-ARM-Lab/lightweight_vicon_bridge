#!/usr/bin/env python

import rospy
from lightweight_vicon_bridge.msg import MocapMarkerArray
from visualization_msgs.msg import Marker


def callback(data):
    m = Marker()

    m.action = Marker.ADD
    m.type = Marker.SPHERE_LIST
    m.header.frame_id = data.header.frame_id
    m.header.stamp = data.header.stamp
    m.ns = data.tracker_name
    m.color.a = 1.0
    m.color.r = 1.0
    m.color.g = 1.0
    m.color.b = 1.0
    m.scale.x = 0.01
    m.scale.y = 0.01
    m.scale.z = 0.01
    m.pose.orientation.w = 1.0
    m.frame_locked = True

    for p in data.markers:
        m.points.append(p.position)

    pub.publish(m)


if __name__ == '__main__':
    rospy.init_node('visualize_raw_markers', anonymous=False)
    pub = rospy.Publisher('mocap_markers_rviz', Marker, queue_size=10)
    sub = rospy.Subscriber("mocap_marker_tracking", MocapMarkerArray, callback)
    rospy.spin()
