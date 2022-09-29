# msg_tutorial
직접 작성한 Mymsg 메시지로 통신하는 패키지

### Publisher Node
- name : msg_publisher
- topic : burger
- msg : Mymsg
- 노드 설명 : Mymsg 메시지에 현재 시간, cnt 변수 값을 넣어 출력한다.

### Subscriber Node
- name : msg_subscriber
- topic : burger
- msg : Mymsg


## msg 만드는 방법
1. 패키지 안에 msg 디렉토리를 만든다.
2. .msg 확장자의 파일을 만든다
3. 안에 내용을 작성한다.
4. CMakelists.txt에서 설정한다.
5. 빌드시 생성된다.