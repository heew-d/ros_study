// 이미 있는 서비스에 맞게 노드를 만든다.
#include "ros/ros.h"
#include "std_srvs/Empty.h"

int main(int argc, char** argv){
    
    ros::init(argc, argv, "turtle_clear");
    ros::NodeHandle nh;

    // 서비스 클라이언트
    ros::ServiceClient clear_client = nh.serviceClient<std_srvs::Empty>("clear");

    // request보낼 서비스 생성
    std_srvs::Empty srv;

    if(clear_client.call(srv)){ // 통신이 잘 되면 if문
        ROS_INFO("Clear");
    }
    else{ // 통신이 잘 안되면 else
        ROS_ERROR("Failed");
        return 1;
    }

    return 0;
}