#!/usr/bin/python
#-*- coding:utf-8 -*-

import rospy
from service_tutorial.srv import AddTwoInts, AddTwoIntsResponse

# 서버에 요청 왔을때 호출되는 콜백함수
def add(req):
    result = req.a + req.b
    rospy.loginfo("a=%d, b=%d", req.a, req.b)
    rospy.loginfo("response: result=%d", result)
    return AddTwoIntsResponse(result)

def add_two_ints_server():
    rospy.init_node("py_server") # 노드 초기화

    # 서비스 서버(my_server)을 선언한다.
    # 서비스 이름은 (add_two_ints)이고, 요청이 왔을 때 콜백함수 (add)를 실행한다.
    # (service_tutorial) 패키지의 (AddTwoInts) 서비스 파일을 이용한다.
    my_server = rospy.Service("add_two_ints", AddTwoInts, add)

    # 서비스 서버가 켜졌는지 우리가 확인하려고 넣은 줄
    rospy.loginfo("Service Server Ready.")

    rospy.spin() #서버는 대기해야한다. => 요청이 와야하니까

if __name__ == "__main__":
    add_two_ints_server()

