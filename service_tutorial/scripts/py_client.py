#!/usr/bin/python
#-*- coding:utf-8 -*-

import rospy
from service_tutorial.srv import AddTwoInts
import sys # 프로그램 실행할때 넣어주는 숫자를 사용하기 위해 import

# servier에 요청하고 값이 오면 반환
def add_two_ints_client(a,b): # a,b 를 넣어 call을 받아오는 함수(결과를 받아오는 함수)
    
    rospy.wait_for_service("add_two_ints") # 서버가 켜질때까지 기다린다. (일종의 무한 반복문)

    try: #except가 발생했을때 잡아주기 위해 try문에 넣음
        my_client = rospy.ServiceProxy("add_two_ints", AddTwoInts) 
        # ServiceProxy : 클라이언트 만드는 함수
        # 클라이언트를 만들때 파라미터로 넣어주는 값(서비스 이름, 서비스 타입)
        res = my_client(a,b) 
        # 클라이언트에 a,b 값을 넣어주면 알아서 서버에 call 해줌.
        # a, b가 보내지고 response(응답)가 돌아온다.
        return res.result
    except rospy.ServiceException as e: # 서비스통신 에러가 발생했을 때만 에러 메시지 출력
        rospy.logerr("Service call failed: %s", e) #에러 메시지 출력

if __name__ == "__main__":
    rospy.init_node("py_client") # 노드 이름 초기화
    
    # 값이 3개인지 아닌지 확인 . {노드이름, a, b} => 3개가 들어와야 함!
    if len(sys.argv) != 3: #argv : 문자열 리스트 형태로 들어옴
        rospy.loginfo("rosrun service_tutorial py_client arg1 arg2")
        rospy.loginfo("a, b: int32 number")
        sys.exit(1) #return 1 처럼 프로그램 종료

    a = int(sys.argv[1]) # a라는 변수 생성 -> 정수형으로 변환
    b = int(sys.argv[2]) # b라는 변수 생성 -> 정수형으로 변환

    result = add_two_ints_client(a,b) #result에는 return res.result 이 값이 들어간다

    rospy.loginfo("request: a=%d, b=%d", a, b)
    rospy.loginfo("response: result=%d", result)