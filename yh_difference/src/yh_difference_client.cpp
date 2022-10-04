#include "ros/ros.h"
#include "yh_difference/YhDifference.h"

#include <cstdlib>

int main(int argc, char** argv){
    
    ros::init(argc, argv, "yh_difference_client"); //노드 이름 초기화

    if(argc != 3){
        ROS_INFO("command: rosrun yh_dirrerence yh_difference_client a b");
        ROS_INFO("a, b : int32 number");
        return 1;
    }

    ros::NodeHandle nh;

    // 서비스 클라이언트 선언
    ros::ServiceClient yh_client = nh.serviceClient<yh_difference::YhDifference>("yh_difference_service");

    yh_difference::YhDifference srv;

    srv.request.a = atoi(argv[1]);    
    srv.request.b = atoi(argv[2]);

    if(yh_client.call(srv)){
        ROS_INFO("a : %d, b: %d, result: %d", srv.request.a, srv.request.b, srv.response.result);
    }
    else{
        ROS_ERROR("Faild to call service");
        return 1;
    }

    return 0;
}