#!/usr/bin/python3
#-*- coding:utf-8 -*-
from asyncore import read
import rospy
from param_tutorial.srv import Calculate, CalculateResponse

PLUS = 1
MINUS = 2
MULTIPLICATION = 3
DIVISION = 4

# 콜백함수
def calculation(req):
    my_operator = rospy.get_param("calculation_method")
    if my_operator == PLUS:
        result = req.a + req.b
    elif my_operator == MINUS:
        result = req.a - req.b
    elif my_operator == MULTIPLICATION:
        result = req.a * req.b
    elif my_operator == DIVISION:
        # if req.b == 0:
        #     result = 0
        # else: 
        #     result  = req.a // req.b
        try:
            result = int(req.a / req.b)
        except ZeroDivisionError:
            result = 0
    else: 
        result = req.a + req.b

    rospy.loginfo(f"a: {req.a}, b: {req.b}, reslut: {result}")
    
    res = CalculateResponse()
    res.result = result

    return res

def calculate_server():
    rospy.init_node("calculate_server") # 노드 이름 초기화

    # 마스터에 있는 파라미터 서버에 있는 변수 calculation_method를 PLUS로 set
    rospy.set_param("calculation_method", PLUS) 
    
    # 서비스 서버 (my_server)선언
    # 서비스 이름(calculate), 서비스 타입(Calculate), 콜백함수(calculation)
    my_server = rospy.Service("calculate", Calculate, calculation)
    rospy.loginfo("Service Server ready")

    rospy.spin()


if __name__ == "__main__":
    calculate_server()