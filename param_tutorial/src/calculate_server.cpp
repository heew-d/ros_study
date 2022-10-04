#include "ros/ros.h"
#include "param_tutorial/Calculate.h" // 서비스 헤더 파일. 빌드시 생성

#define PLUS 1
#define MINUS 2
#define MULTIPLICATION 3
#define DIVISION 4

int my_operator = PLUS;

// 콜백함수 
bool calculation(param_tutorial::Calculate::Request& req, param_tutorial::Calculate::Response& res){
    switch(my_operator)
    {
        case PLUS:
            res.result = req.a + req.b;
            break;
        case MINUS:
            res.result = req.a - req.b;
            break;
        case MULTIPLICATION:
            res.result = req.a * req.b;
            break;
        case DIVISION:
            res.result = req.a / req.b;
            break;
        default: 
            res.result = req.a + req.b;
            break;
    }

    ROS_INFO("a: %d, b: %d, result: %d", req.a, req.b, res.result);
    
    return true;
}

int main(int argc, char** argv){

    ros::init(argc, argv, "calculate_server"); // 노드 이름 초기화
    ros::NodeHandle nh;

    // 파라미터 서버에 calculation_method라는 변수의 이름으로 PLUS 값을 넣는다
    nh.setParam("calculation_method", PLUS); // 파라미터 초기 설정

    // 서비스 서버 (calculate_server) 선언
    // 서비스 이름은 (calculate)이고, 요청이 왔을 때 콜백함수 (calculation)를 실행한다.
    ros::ServiceServer calculate_server = nh.advertiseService("calculate", calculation);

    ros::Rate loop_rate(10); // 0.1초마다

    while(ros::ok()){ // ros 켜져있는 동한 무한 반복
        // 파라미터 서버에 있는 calculation_method라는 이름의 변수를 my_operator에 가져와서 할당(저장)
        nh.getParam("calculation_method", my_operator);
        // 대기하다가 콜백함수 한번만 호출. spin 한번만하고 꺼짐
        ros::spinOnce();
        loop_rate.sleep(); // 주기에 맞게 sleep
    }

    return 0;
}