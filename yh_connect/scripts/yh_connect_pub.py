#!/usr/bin/python3
#-*- coding:utf-8 -*-

import rospy
from std_msgs.msg import Int32

class ConnectPub:
    def __init__(self): # 생성자 함수 선언. 변수 할당, 선언
        # 퍼블리셔 선언
        # 토픽 이름 : yh_connect_int , 메시지 타입 : Int32
        self.pub = rospy.Publisher("yh_connect_int", Int32)
        self.msg = Int32()
        self.loop_rate = rospy.Rate(4)

    def run(self): # while문에서 publish하고 1더하고 sleep
        while not rospy.is_shutdown():
            self.pub.publish(self.msg)
            self.msg.data += 1
            self.loop_rate.sleep()

if __name__ == "__main__":
    rospy.init_node("yh_connect_pub")
    connect_pub = ConnectPub()
    connect_pub.run()
