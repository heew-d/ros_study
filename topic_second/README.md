- topic_second 패키지 생성
- second_pub.cpp, second_sub.cpp 노드 생성
- 빌드
- 실행

- publisher 노드 1개(second_pub.cpp), subscriber 노드 1개(second_sub.cpp)
- publisher 노드의 이름은 second_pub이고 std_msgs 패키지의 Int32 메시지를 publish한다.
- subscriber 노드의 이름은 second_sub이고 std_msgs 패키지의 Int32 메시지를 subscribe한다.
- 토픽 이름 : my_count


- topic_second 패키지에 python scripts 추가
- py_second_pub.py, py_second_sub.py 노드 생성
- 빌드
- 실행

- publisher 노드 1개(py_second_pub.py), subscriber 노드 1개(py_second_sub.py)
- publisher 노드의 이름은 py_second_pub이고 std_msgs 패키지의 Int32 메시지를 publish한다.
- subscriber 노드의 이름은 py_second_sub이고 std_msgs 패키지의 Int32 메시지를 subscribe한다.
- 토픽 이름 : my_count