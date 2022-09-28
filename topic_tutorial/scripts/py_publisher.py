#!/usr/bin/python
#-*- coding: utf-8 -*-
import rospy
from std_msgs.msg import String

def talker():
    pub = rospy.Publisher("my_topic", String, queue_size=100)
    rospy.init_node("py_publisher") #노드 이름 초기화
    
    loop_rate = rospy.Rate(10) #10Hz (0.1초에 한번)

    msg = String()
    msg.data = "Hi"

    while not rospy.is_shutdown():
        pub.publish(msg)
        loop_rate.sleep()

if __name__ == "__main__": #지금 이 파일을 실행 시켰을때 name이 main
    try:
        talker()
    except rospy.ROSInterruptException:
        pass