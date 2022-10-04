#include "ros/ros.h"
#include "yh_check/YhCheck.h"

void msgCallback(const yh_check::YhCheck::ConstPtr& msg){
    if(msg->data == true){
        ROS_INFO("OK");
    }
}

int main(int argc, char** argv){
    
    ros::init(argc, argv, "yh_check_sub"); // 노드 이름 초기화
    ros::NodeHandle nh;

    // 서브스크라이버 선언
    ros::Subscriber sub1 = nh.subscribe("check_distance", 100, msgCallback);
    ros::Subscriber sub2 = nh.subscribe("check_camera", 100, msgCallback);

    ros::spin();
    
    return 0;
}