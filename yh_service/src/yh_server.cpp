#include "ros/ros.h"
#include "yh_service/YhSrv.h" //서비스 헤더 파일
                            //빌드시 생성

// 서비스 요청이 있을 경우 실행되는 콜백 함수
// 서비스 요청은 req, 서비스 응답은 res로 설정
bool multiply(yh_service::YhSrv::Request& req, yh_service::YhSrv::Response& res){
    res.result = req.a * req.b;
    ROS_INFO("a=%d, b=%d, result=%d", req.a, req.b, res.result);
    return true;
}

int main(int argc, char** argv){
    
    ros::init(argc, argv, "yh_server"); //노드 이름 초기화
    ros::NodeHandle nh;

    //서비스 서버(yh_server)을 선언한다.
    // 서비스 이름은 (multiply)이고, 요청이 왔을 때 콜백함수 (multiply)를 실행한다.
    // (yh_service) 패키지의 (YhSrv) 서비스 파일을 이용한다.
    ros::ServiceServer yh_server = nh.advertiseService("multiply", multiply);

    ros::spin(); //대기

    return 0;
}