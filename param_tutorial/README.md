### Parameter Server
- ROS Master에서 실행되고, 변수들을 담고 있는 서버
- ros::setParam(), ros::getParam(), rospy.set_param(), rospy.get_param() 등의 함수로 사용
- command line에서 rosparam으로 사용 가능
- rosparam list
    - 파라미터 서버의 모든 파라미터를 출력
```bash
rosparam list
```

- rosparam get <파라미터 이름>
    - 파라미더 값을 출력함
```bash
rosparam get <파라미터 이름>
```

- rosparam set <파라미터 이름> [파라미터 값]
    - 파라미터의 값을 지정함
```bash
rosparam set <파라미터 이름> [파라미터 값]
```