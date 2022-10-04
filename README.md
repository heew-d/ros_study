# ros_study
my first ros study

### 2022년 9월 27일 시작
- [topoic_tutorial](./topic_tutorial) 패키지 생성
- my_publisher, my_subscriber 노드 생성
- 빌드
- 실행

### 2022년 9월 28일
- [topic_tutorial](./topic_tutorial) 패키지에 python scripts 추가
- py_publisher.py, py_subscriber.py 노드 생성
- 빌드
- 실행

- [topic_second](./topic_second) 패키지 생성
- second_pub.cpp, second_sub.cpp 노드 생성
- 빌드
- 실행

- [topic_second](./topic_second) 패키지에 python scripts 추가
- py_second_pub.py, py_second_sub.py 노드 생성
- 빌드
- 실행

- [과제 1](./topic_test)

### 2022년 9월 29일
- [msg_tutorial](./msg_tutorial)
    - msg_tutorial 패키지 생성
    - msg 디렉토리에 Mymsg.msg 생성
    - msg_publisher, msg_subscriber, py_msg_pub.py, py_msg_sub.py 노드 생성
    - 빌드 
    - 실행

- [service_tutorial](./service_tutorial)
    - service_tutorial 패키지 생성
    - srv 디렉토리에 AddTwoInts.srv 생성
    - my_server, my_client, py_server.py, py_client.py 노드 생성
    - 빌드 
    - 실행


### 2022년 9월 30일
- [과제2 yh_star](./yh_star)
- for문 활용해서 별 찍기
    - yh_star 패키지 생성
    - yh_star_pub, yh_star_sub, yh_star_pub.py, yh_star_sub.py 노드 생성
    - 빌드 
    - 실행  

- [과제3 yh_service](./yh_service)
    - yh_service 패키지 생성
    - yh_server, yh_client, yh_server.py, yh_client.py 노드 실행 
    - 빌드
    - 실행


## 2022년 10월 4일
### [param_tutorial](./param_tutorial)
-  param_tutorial 패키지 생성
- caculate_server, calculate_client, caculate_server.py, calculate_client.py 노드 생성
- 빌드
- 실행
- [파라미터 서버 활용](#parameter-server)

### [과제4 yh_dual](./yh_dual)
### [과제5 yh_difference](./yh_difference)
### [과제6 yh_check](./yh_check)

---

## ROS 명령어
### roscore
- ROS Master를 실행한다.
- 노드를 켜기 전에 가장 먼저 실행
```bash
    roscore
```

### rosrun
- 노드를 실행한다.
- rosrun 패키지이름 노드이름
```bash
    rosrun <패키지이름> <노드이름>
```

### catkin_create_pkg
- 현재 위치한 작업 공간에 패키지를 생성한다.
- catkin_create_pkg 패키지이름 의존성
```bash
    catkin_create_pkg <패키지이름> <의존성1> <의존성2> ...
```

```bash
    catkin_create_pkg topic_tutorial roscpp rospy std_msgs
```

### Python3 설치 방법
- python3 설치
```bash
sudo apt install python3-pip python3-all-dev python3-rospkg
sudo apt install ros-melodic-desktop-full --fix-missing
```


