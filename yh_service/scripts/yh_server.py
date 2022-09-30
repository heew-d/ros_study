#!/usr/bin/python3
#-*- coding:utf-8 -*-

import rospy
from yh_service.srv import YhSrv, YhSrvResponse

# 서버에 요청이 왔을때 호출되는 콜백함수
def multiply(req):
    res = YhSrvResponse() # YhSrv의 response 부분만 가져옴
    res.result = req.a * req.b
    rospy.loginfo(f"a:{req.a}, b:{req.b}, result:{res.result}")
    return res

def multiply_server():
    rospy.init_node("yh_server") # 노드 초기화

    # 서비스 서버(yh_server)을 선언한다.
    # 서비스 이름은 (multiply)이고, 요청이 왔을 때 콜백함수 (multiply)를 실행한다.
    # (yh_service) 패키지의 (YhSrv) 서비스 파일을 이용한다
    yh_server = rospy.Service("multiply", YhSrv, multiply)

    # 서비스 서버가 켜져있으면 출력
    rospy.loginfo("Server Ready")

    rospy.spin() # 서버는 대기해야한다. => 요청이 와야하니까

if __name__ =="__main__":
    multiply_server() 