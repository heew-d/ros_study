## 과제3

- yh_service 패키지를 만들고 service server 노드 1개, service client 노드 1개를 만든다.
- service server 노드의 이름은 yh_server이고, 요청을 받아 request 안의 정수 a, b를 곱한 값을 response의 result에 넣어 응답한다.
- service client 노드의 이름은 yh_client이고, request 안에 정수 a, b를 넣어 요청을 보내고 결과값을 출력한다.
- 정수 a, b는 service client 노드 실행 시 command line을 통해 입력받는다.
- service 이름은 multiply, service 파일 이름은 YhSrv로 한다.

### Service Node
- node : yh_server
- service name : multiply
- sevice file : YhSrv

### Client Node
- node : yh_client
- service name : multiply
- sevice file : YhSrv


## srv 만드는 방법
1. 패키지 안에 srv 디렉토리를 만든다.
2. .srv 확장자의 파일을 만든다
3. 안에 내용을 작성한다.
4. CMakelists.txt에서 설정한다.
5. 빌드시 생성된다.

# 같은 이름의 노드를 동시에 여러개 켤 수 없다.