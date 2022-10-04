#include "ros/ros.h"
#include "yh_difference/YhDifference.h"

bool difference(yh_difference::YhDifference::Request& req, yh_difference::YhDifference::Response& res){
    if (req.a>req.b){
        res.result = req.a - req.b;
    }
    else{
        res.result = req.b - req.a;
    }

    ROS_INFO("a : %d, b : %d, result : %d", req.a, req.b, res.result);
    
    return true;
}

int main(int argc, char** argv){
    
    ros::init(argc, argv, "yh_difference_server"); // 노드 이름 초기화
    ros::NodeHandle nh;

    // 서비스 서버 (yh_server) 선언
    // 서비스 이름은 (), 
    ros::ServiceServer yh_server = nh.advertiseService("yh_difference_service", difference);

    ros::spin();
    
    return 0;
}