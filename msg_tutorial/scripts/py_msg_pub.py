#!/usr/bin/python
#-*- coding:utf-8 -*-

import rospy
# from std_msgs.msg import Int32
from msg_tutorial.msg import Mymsg

def msg_talker():
    rospy.init_node("py_msg_pub") #노드 이름 초기화

    #퍼블리셔 선언
    pub = rospy.Publisher("burger", Mymsg, queue_size=10)

    loop_rate = rospy.Rate(5) #0.2초마다

    msg = Mymsg()
    cnt = 0

    while not rospy.is_shutdown():
        # Mymsg:
        #   time stamp
        #   int32 data
        msg.stamp = rospy.Time.now() #현재 시간을 msg의 stamp에 담는다.
        msg.data = cnt #cnt 변수의 값을 msg의 data에 담는다.

        rospy.loginfo("send msg : %d", msg.stamp.secs) #stamp.secs를 출력한다.
        rospy.loginfo("send msg : %d", msg.stamp.nsecs) #stamp.nsecs를 출력한다.
        rospy.loginfo("send msg : %d", msg.data) #data를 출력한다.

        pub.publish(msg) #pub이 msg를 퍼블리시한다.
        cnt += 1
        loop_rate.sleep()

if __name__ == "__main__":
    try:
        msg_talker()
    except rospy.ROSInterruptException:
        pass