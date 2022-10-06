#!/usr/bin/python3
#-*- coding:utf-8 -*-

import rospy
from std_srvs.srv import Empty

class TurtleClear:
    def __init__(self):
        super(TurtleClear, self).__init__()
        self.clear_client = rospy.ServiceProxy("clear", Empty)

    def call(self): # 서비스 통신(서버-클라이언트)
        try:
            self.clear_client()
        except rospy.ServiceException as e:
            rospy.logerr(f"Failed : {e}")

if __name__ == "__main__":
    rospy.init_node("turtle_clear") # 노드 이름 초기화
    turtle_clear = TurtleClear() # 클래스(TurtleClear())에 인스터스를 만들어 변수에 넣어줌
    turtle_clear.call()