#include "ros/ros.h"
#include "yh_service/YhSrv.h" //서비스 헤더 파일
                            // 빌드시 생성
#include <cstdlib> //atoi 함수 사용을 위한 라이브러리 : 문자열을 정수로 만들어주는 함수

int main(int argc, char** argv){

    ros::init(argc, argv, "yh_client"); //노드 이름 초기화

    //{"yh_client", "a", "b"}
    if(argc != 3){ //argc : 몇개가 들어왔는지, argv : 뭐가 들어왔는지
        ROS_INFO("command: rosrun yh_service yh_client arg1 arg2");
        ROS_INFO("arg1, arg2 : int32 number");
        return 1;
    }

    ros::NodeHandle nh;

    // 서비스 클라이언트 (yh_client)를 선언한다.
    // 서비스 이름은 (multiply)이고 패키지 (yh_service)의 (YhSrv) 서비스 파일을 사용한다.
    ros::ServiceClient yh_client = nh.serviceClient<yh_service::YhSrv>("multiply");

    yh_service::YhSrv srv; // 서비스 가져올 변수 선언

    // 노드 실행시 입력된 변수를 서비스 요청 값의 a,b에 저장한다.
    srv.request.a = atoi(argv[1]);
    srv.request.b = atoi(argv[2]);

    if(yh_client.call(srv)){ //정상적으로 통신이 되었을때 출력
        ROS_INFO("a:%d, b:%d", srv.request.a, srv.request.b);
        ROS_INFO("result: %d", srv.response.result);
    }
    else{
        ROS_ERROR("Failed to call service");
        return 1;
    }

    return 0;
}