#include "ros/ros.h"
#include "yh_check/YhCheck.h"

static yh_check::YhCheck msg1;

int main(int argc, char** argv){
    
    ros::init(argc, argv, "yh_check_canera");
    ros::NodeHandle nh;

    // 퍼블리셔 선언
    ros::Publisher pub = nh.advertise<yh_check::YhCheck>("check_camera",100);

    ros::Rate loop_rate(2.5); // 0.4초마다

    while(ros::ok()){
        msg1.stamp = ros::Time::now();
        msg1.data = true;

        ROS_INFO("camera msg : %d", msg1.stamp.sec);
        ROS_INFO("camera msg : %d", msg1.stamp.nsec);
        ROS_INFO("camera msg : %d", msg1.data);

        pub.publish(msg1);
        loop_rate.sleep();
    }
    
    return 0;
}