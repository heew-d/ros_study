#!/usr/bin/python
#-*- coding:utf-8 -*-

import rospy
from std_msgs.msg import Int64

def my_test_counter():
    rospy.init_node("my_test_publisher") #노드 이름 초기화

    #퍼블리셔 선언
    #패키지(std_msgs)의 메시지파일(Int64)을 이용한 퍼블리셔()를 만든다.
    #토픽은 (my_test_count)이며, 퍼블리셔큐(queue) 사이즈는 (100)이다.
    pub = rospy.Publisher("my_test_count", Int64, queue_size=100)

    loop_rate = rospy.Rate(4) #0.25초 주기

    msg = Int64()
    msg.data = 0 #msg의 data에 0을 넣는다.

    while not rospy.is_shutdown():
        for msg.data in range(101): #0부터 100까지
            pub.publish(msg) #pub이 msg를 퍼블리시한다.
            loop_rate.sleep()
            msg.data += 1

if __name__ == "__main__":
    try:
        my_test_counter()
    except rospy.ROSInterruptException:
        pass