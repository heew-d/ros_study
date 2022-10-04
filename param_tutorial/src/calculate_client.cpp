#include "ros/ros.h"
#include "param_tutorial/Calculate.h"
#include <cstdlib> // 문자열-> 정수형으로 바꿔주는 함수 쓰기 위해 include

int main(int argc, char** argv){
    
    ros::init(argc, argv, "calculate_client"); // 노드 이름 초기화

    if(argc != 3){
        ROS_INFO("rosrun param_tutorial calculate_client a b");
        ROS_INFO("a, b : int32 number");
        return 1;
    }

    ros::NodeHandle nh;

    // 서비스 클라이언트 (calculate_client)를 선언한다.
    // 서비스 이름은 (calculate)이고 패키지 (param_tutorial)의 (Calculate) 서비스 파일을 사용한다.
    ros::ServiceClient calculate_client = nh.serviceClient<param_tutorial::Calculate>("calculate");

    param_tutorial::Calculate srv; // 서비스 가져올 변수 선언

    srv.request.a = atoi(argv[1]);
    srv.request.b = atoi(argv[2]);

    if(calculate_client.call(srv)){
        ROS_INFO("a : %d, b : %d, result : %d", srv.request.a, srv.request.b, srv.response.result);
    }
    else{
        ROS_ERROR("Failed to call service");
        return 1;
    }

    return 0;
}