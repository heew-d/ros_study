## 과제4

- yh_dual 패키지를 만들고 Publisher 노드 1개, Subscriber 노드 2개를 만든다.
- Publisher 노드의 이름은 yh_dual_pub이고 yh_dual_topic이라는 토픽으로 YhDual 메시지에 publish한 시간과 정수를 담아 publish 한다.
- Subscriber 노드 1의 이름은 yh_dual_time 이고 yh_dual_topic 토픽의 YhDual 메시지를 subscribe하여 시간 정보를 출력한다.
- Subscriber 노드 2의 이름은 yh_dual_int 이고 yh_dual_topic 토픽의 YhDual 메시지를 subscribe하여 정수 정보를 출력한다.
- yh_dual_pub은 메시지를 0.125초마다 publish하고, publish할때마다 정수를 1씩 증가시킨다.