#!/usr/bin/python
#-*- coding: utf-8 -*-
import rospy
from std_msgs.msg import String

def talker():

    rospy.init_node("py_publisher") #노드 이름 초기화

    #퍼블리셔 선언
    #패키지(std_msgs)의 메시지파일(String)을 이용한 퍼블리셔(pub)를 만든다.
    #토픽은 (my_topic)이며, 퍼블리셔큐(queue) 사이즈는 (100)이다.
    pub = rospy.Publisher("my_topic", String, queue_size=100)
    
    loop_rate = rospy.Rate(10) #10Hz (0.1초에 한번)

    msg = String()
    msg.data = "Hi" #msg의 data에 Hi를 넣는다.

    while not rospy.is_shutdown():
        pub.publish(msg) #pub이 msg를 퍼블리시한다.
        loop_rate.sleep()

if __name__ == "__main__": #지금 이 파일을 실행 시켰을때 name이 main
    try:
        talker()
    except rospy.ROSInterruptException:
        pass