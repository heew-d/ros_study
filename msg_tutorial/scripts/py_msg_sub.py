#!/usr/bin/python
#-*- coding:utf-8 -*-

import rospy
from msg_tutorial.msg import Mymsg

def msgCallback(msg):
    rospy.loginfo("recive msg : %d", msg.stamp.secs) #msg의 stamp의 secs를 출력한다.
    rospy.loginfo("recive msg : %d", msg.stamp.nsecs) #msg의 stamp의 nsecs를 출력한다.
    rospy.loginfo("recive msg : %d", msg.data) #msg의 data를 출력한다.

def msg_listener():
    rospy.init_node("py_msg_sub") # 노드 이름 초기화

    # 서브스크라이버 선언
    # 패키지(msg_tutorial)의 메시지(Mymsg)를 이용한 서브크스라이버를 선언한다.
    # 토픽은 (burger)이며, 서브스크라이버큐(queue) 사이즈를 (30)으로 설정한다.
    rospy.Subscriber("burger", Mymsg, msgCallback, queue_size=30)

    rospy.spin()

if __name__ =="__main__":
    msg_listener()    
    
