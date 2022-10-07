#!/usr/bin/python3
# -*- coding:utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
import math
from turtlesim.srv import TeleportAbsolute, TeleportAbsoluteRequest
from yh_turtle_circle import YhTurtleCircle

class YhTurtleTriangle(YhTurtleCircle):
    def run(self):
        self.call(5.544445, 5.544445+self.radius ,math.pi * 4 / 3)

        while not rospy.is_shutdown():
            # 이동
            self.msg.linear.x = self.radius
            self.msg.angular.z = 0 # 회전을 안해야함
            self.pub.publish(self.msg)
            self.loop_rate.sleep()

            # 회전
            self.msg.linear.x = 0
            self.msg.angular.z = math.pi * 2 / 3
            self.pub.publish(self.msg)
            self.loop_rate.sleep()

if __name__ == "__main__":
    rospy.init_node("yh_turtle_triangle")
    yh_turtle_triangle = YhTurtleTriangle(float(input("삼각형 한 변의 길이를 입력해주세요. : ")))
    yh_turtle_triangle.run()