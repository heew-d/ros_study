#!/usr/bin/python3
#-*- coding:utf-8 -*-

import rospy
from std_msgs.msg import Float32

class ConnectSub:
    """
    ConnectPub Class
    @param 없음
    """
    def __init__(self):
        self.sub = rospy.Subscriber("yh_connect_float", Float32, self.msgCallback)
    
    def msgCallback(self, msg):
        rospy.loginfo(msg.data)

if __name__ =="__main__":
    rospy.init_node("yh_connect_sub") # 노드 이름 초기화
    connect_sub = ConnectSub()
    rospy.spin()
