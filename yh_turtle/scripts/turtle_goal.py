#!/usr/bin/python3
# -*- coding:utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose # 실시간으로 보여주는 현재 위치 정보 담고 있다
import math

# 목표 지점을 알려주면 목표 지점까지 움직인다
# 현재 위치, 목표 위치 필요
class TurtleGoal:
    def __init__(self):
        self.sub = rospy.Subscriber("turtle1/pose", Pose, self.update_pose)
        
        # 움직이는 명령을 보내주는 퍼블리셔 선언
        self.pub = rospy.Publisher("turtle1/cmd_vel", Twist, queue_size=100)

        self.pose = Pose() #실시간으로 turtle이 보내주는 정보 저장
        self.goal_pose = Pose() # 목표값 저장
        self.loop_rate = rospy.Rate(10)

    def update_pose(self, msg):
        self.pose = msg
        self.pose.x = round(self.pose.x, 4) # round 소수점 4자리까지 반올림
        self.pose.y = round(self.pose.y, 4)

    # 두 점 사이의 거리 구하는 함수
    # 지금 내 위치와 목표 지점 사이의 거리
    def euclidean_distance(self):
        # self.pose ------> self.goal_pose
        diff_x = self.goal_pose.x - self.pose.x
        diff_y = self.goal_pose.y - self.pose.y
        return math.sqrt((diff_x * diff_x) + (diff_y * diff_y))

    # constant=1.5 디폴트 값.
    # 호출할 때 constant 자리에 아무것도 안넣었을때 1.5 쓴다.
    def linear_vel(self, constant=1.5):
        return constant * self.euclidean_distance()

    # atan2 : tan의 역함수
    # 우리가 목표로하는 세타 각도
    def steering_angle(self):
        return math.atan2((self.goal_pose.y - self.pose.y), (self.goal_pose.x-self.pose.x))

    # pose.theat : 현재 내가 보고있는 각도 정보
    def angular_vel(self, constant=6):
        return constant * (self.steering_angle() - self.pose.theta)

    # 움직이라는 명령 보내는 함수
    def run(self):
        self.goal_pose.x = float(input("x 좌표 : "))
        self.goal_pose.y = float(input("y 좌표 : "))
        
        # 오차
        tolerance = float(input("오차 : ")) # 이 값보다 작으면 도착한 것으로 간주

        msg = Twist()

        # 도착할때까지 반복문
        while self.euclidean_distance() >= tolerance:
            msg.linear.x = self.linear_vel()
            msg.angular.z = self.angular_vel()

            self.pub.publish(msg)
            self.loop_rate.sleep()

        msg.linear.x = 0
        msg.angular.z = 0
        self.pub.publish(msg)
        rospy.loginfo("Goal!")

if __name__=="__main__":
    rospy.init_node("turtle_goal")
    turtle_goal = TurtleGoal()
    turtle_goal.run()