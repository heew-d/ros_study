#!/usr/bin/python3
#-*- coding:utf-8 -*-

import rospy
from std_msgs.msg import Int32, Float32

class ConnectSubPub:
    def __init__(self):
        # 서브스크라이버 선언
        # 패키지(std_msgs)의 메시지(Int32)를 이용한 서브스크라이버 (sub) 선언
        # 토픽: (yh_connect_int)
        self.sub = rospy.Subscriber("yh_connect_int", Int32, self.msgCallback)
        
        # 퍼블리셔 선언
        self.pub = rospy.Publisher("yh_connect_float", Float32)

        self.float_msg = Float32()
    
    def msgCallback(self, msg):
        if msg.data % 5 == 0:
            self.float_msg.data = msg.data / 3
            self.pub.publish(self.float_msg)

if __name__ == "__main__":
    rospy.init_node("yh_connect_sub_pub")
    connect_sub_pub = ConnectSubPub()
    rospy.spin()