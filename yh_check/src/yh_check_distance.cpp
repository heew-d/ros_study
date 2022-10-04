#include "ros/ros.h"
#include "yh_check/YhCheck.h"

static yh_check::YhCheck msg2;

int main(int argc, char** argv){
    
    ros::init(argc, argv, "yh_check_distance"); // 노드 이름 초기화
    ros::NodeHandle nh;

    //퍼블리셔 선언
    ros::Publisher pub = nh.advertise<yh_check::YhCheck>("check_distance",100);
    
    ros::Rate loop_rate(2); // 0.5초마다



    while(ros::ok()){
        msg2.stamp = ros::Time::now();
        msg2.data = false;

        ROS_INFO("distance msg : %d", msg2.stamp.sec);
        ROS_INFO("distance msg : %d", msg2.stamp.nsec);
        ROS_INFO("distance msg : %d",msg2.data);

        pub.publish(msg2);
        loop_rate.sleep();
    }

    return 0;
}