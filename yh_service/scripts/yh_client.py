#!/usr/bin/python3
#-*- coding:utf-8 -*-

import rospy
from yh_service.srv import YhSrv, YhSrvRequest
import sys # 프로그램 실행할때 넣어주는 숫자(a,b)를 사용하기 위해 import

# service에 요청하고 값이 오면 반환
def multiply_client():
    rospy.init_node("yh_client")
    
    #실행 시 들어오는 값이 3개가 아니면 : {노드이름, a,b}
    if len(sys.argv) != 3:
        rospy.loginfo("rosrun yh_service yh_client.py a b")
        rospy.loginfo("a, b : int32 number")
        sys.exit(1)

    # 서비스 클라이언트 선언
    # ServiceProxy : 클라이언트를 만드는 함수 
    yh_client = rospy.ServiceProxy("multiply", YhSrv)

    req = YhSrvRequest()
    req.a = int(sys.argv[1])
    req.b = int(sys.argv[2])

    try:
        res = yh_client(req)
        rospy.loginfo(f"a: {req.a}, b: {req.b} result: {res.result}")
    except rospy.ServiceException as e:
        rospy.logerr(f"Fail: {e}")

   


if __name__ =="__main__":
    multiply_client()