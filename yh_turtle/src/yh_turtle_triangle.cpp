#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <cstdlib>

int main(int argc, char** argv){
    ros::init(argc, argv, "yh_turtle_circle");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 100);
    ros::Rate loop_rate(1);

    geometry_msgs::Twist msg;

    msg.linear.x = atoi(argv[1]);
    msg.linear.y = atoi(argv[1]);

    while(ros::ok()){
        pub.publish(msg);
        msg.linear.x = atoi(argv[1]);
        msg.linear.y = 0;
        msg.linear.z = 0;
        msg.angular.x = 0;
        msg.angular.y = 0;
        msg.angular.z = 1;
        loop_rate.sleep();
    }
    return 0;
}