## 과제2

- yh_star 패키지를 만들고 publisher 노드 1개, subscriber 노드 1개를 만든다.
- publisher 노드의 이름은 yh_star_pub이고, yh_star_topic이라는 이름의 토픽으로 0.5초에 한번 메시지를 publish한다.
- subscriber 노드의 이름은 yh_star_sub이고, ys_star_pub이 publish하는 메시지를 subscribe한다.
- yh_star_pub은 시간과 정수를 YhStarMsg 메시지에 담아 publish한다.
- yh_star_sub은 subscribe한 메시지 안의 정수에 따라 printf()함수로 별을 출력한다.(python이면 print())


## ex)
```bash
1 -> *
2 -> *
     *
3 -> *
     **
     *
4 -> *
     **
     **
     *
5 -> *
     **
     ***
     **
     *
```


### Publisher Node
- name : yh_star_pub
- topic : yh_star_topic
- msg : YhStarMsg
- 노드 설명 : YhStarMsg 메시지에 현재 시간, cnt 변수 값을 넣어 출력한다. 별도 출력한다.

### Subscriber Node
- name : yh_star_sub
- topic : yh_star_topic
- msg : YhStarMsg


## msg 만드는 방법
1. 패키지 안에 msg 디렉토리를 만든다.
2. .msg 확장자의 파일을 만든다
3. 안에 내용을 작성한다.
4. CMakelists.txt에서 설정한다.
5. 빌드시 생성된다.