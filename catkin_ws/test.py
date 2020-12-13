#!/usr/bin/env python
import sys

from unsupervised_msgs.srv import NavigatorCmd, NavigatorCmdResponse
import rospy


def callback(req):
    res = NavigatorCmdResponse()
    print(req.trigger)
    return res
 
def launch_node():
    rospy.init_node('test_navigator_cmd')
    s = rospy.Service('hello', NavigatorCmd, callback)
    rospy.spin()

if __name__ == "__main__":
  launch_node()
