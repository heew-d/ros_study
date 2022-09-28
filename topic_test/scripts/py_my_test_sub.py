#!/usr/bin/python
#-*- coding:utf-8 -*-

import rospy
from std_msgs.msg import Int64

def msgCallback(msg):
    rospy.loginfo("count : %d", msg.data)

def test_listener():
    rospy.init_node("my_test_subscriber") #노드 이름 초기화

    #서브스크라이버 선언
    #패키지(std_msgs)의 메시지(Int64)를 이용한 서브스크라이버를 선언한다.
    #토픽은 (my_test_count)이며, 서브스크라이버큐(queue) 사이즈를 (100)으로 설정한다.
    rospy.Subscriber("my_test_count", Int64, msgCallback, queue_size=100)

    rospy.spin()


if __name__ == "__main__":
    test_listener()