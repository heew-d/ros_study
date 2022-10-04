## 과제6

- yh_check 패키지를 만들고 publisher 노드 2개, subscriber 노드 1개를 만든다.
- publisher 노드 1의 이름은 yh_check_distance이고, check_distance라는 topic으로 YhCheck 메시지에 publish 한 시간과 bool 정보를 담아 publish한다.
- publisher 노드 2의 이름은 yh_check_camera이고, check_camera라는 topic으로 YhCheck 메시지에 publish한 시간과 bool 정보를 담아 publish한다.
- subscriber 노드의 이름은 yh_check_sub이고, publisher 노드 2개에서 온 정보가 모두 true일 때에만 OK라고 출력한다.
- yh_check_distance는 0.5초마다, yh_check_camera는 0.4초마다 메시지를 publish하고, publish할 때마다 bool 정보를 토글한다.