#include "ros/ros.h"
#include "std_msgs/Float32.h"

void msgCallback(const std_msgs::Float32::ConstPtr& msg){
    ROS_INFO("%f", msg->data);
}

int main(int argc, char** argv){
    
    ros::init(argc, argv, "yh_connect_sub");
    ros::NodeHandle nh;

    // 서브스크라이버 선언
    ros::Subscriber sub = nh.subscribe<std_msgs::Float32>("yh_connect_float", 10, msgCallback);

    ros::spin();

    return 0;
}