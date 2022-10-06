#!/usr/bin/python3
#-*- coding:utf-8 -*-
import rospy
from geometry_msgs.msg import Twist

class TurtleKeyboard:
    def __init__(self):
        super(TurtleKeyboard, self).__init__()
        # 서브스크라이버 선언
        self.sub = rospy.Subscriber("cmd_vel", Twist, self.msgCallback)
        # 퍼블리셔 선언
        self.pub = rospy.Publisher("turtle1/cmd_vel", Twist, queue_size=100)

    def msgCallback(self, msg):
        self.pub.publish(msg)

if __name__ == "__main__":
    rospy.init_node("turtle_keyboard")
    turtle_keyboard = TurtleKeyboard()
    rospy.spin() # 서브스크라이버가 메시지 받는걸 대기