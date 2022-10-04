#include "ros/ros.h"
#include "yh_check/YhCheck.h"

int main(int argc, char** argv){
    
    ros::init(argc, argv, "yh_check_canera");
    ros::NodeHandle nh;

    // 퍼블리셔 선언
    ros::Publisher pub = nh.advertise<yh_check::YhCheck>("check_camera",100);

    ros::Rate loop_rate(2.5); // 0.4초마다

    yh_check::YhCheck msg;

    while(ros::ok()){
        msg.stamp = ros::Time::now();
        msg.data = true;

        ROS_INFO("camera msg : %d", msg.stamp.sec);
        ROS_INFO("camera msg : %d", msg.stamp.nsec);
        ROS_INFO("camera msg : %d", msg.data);

        pub.publish(msg);
        loop_rate.sleep();
    }
    
    return 0;
}