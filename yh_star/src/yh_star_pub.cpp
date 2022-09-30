#include "ros/ros.h"
#include "yh_star/YhStarMsg.h"

int main(int argc, char** argv){
    
    ros::init(argc, argv, "yh_star_pub"); // 노드 이름 초기화
    ros::NodeHandle nh; // 통신을 위해 핸들러 생성

    //퍼블리셔 선언
    ros::Publisher pub = nh.advertise<yh_star::YhStarMsg>("yh_star_topic",5);

    ros::Rate loop_rate(2); // 주기 설정. 0.5초

    yh_star::YhStarMsg msg;
    int cnt = 1;

    while (ros::ok())
    {
        msg.stamp = ros::Time::now();
        msg.data = cnt;

        ROS_INFO("send msg : %d", msg.stamp.sec);
        ROS_INFO("send msg : %d", msg.stamp.nsec);
        ROS_INFO("send msg : %d", msg.data);

        pub.publish(msg);
        cnt++;
        loop_rate.sleep();
    }

    return 0;
}