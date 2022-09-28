#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from std_msgs.msg import String

def msgCallback(msg): #파이썬은 타입을 지정해주지 않고 변수 명만 써줘도 됨
    rospy.loginfo("msg : %s", msg.data) #msg : 클래스, data : 멤버변수

def listener():
    rospy.init_node("py_subscriber") #노드 이름 초기화

    #서브스크라이버 선언
    rospy.Subscriber("my_topic", String, msgCallback, queue_size=100) 
    #콜백함수에 자료형이 없어서 Subscriber에 자료형(String) 선언

    rospy.spin()

if __name__ == "__main__":
    listener()
