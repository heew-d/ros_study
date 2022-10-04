#include "ros/ros.h"
#include "yh_dual/YhDual.h"

int main(int argc, char** argv){
    
    ros::init(argc, argv, "yh_dual_pub"); // 노드 이름 초기화
    ros::NodeHandle nh;

    // 퍼블리셔 선언
    // 패키지 (yh_dual)의 메시지파일(YhDual)을 이용한 퍼블리셔(pub)를 만든다.
    // 토픽은 (yh_dual_topic)이며, 퍼블리셔큐(queue) 사이즈는 ()이다.
    ros::Publisher pub = nh.advertise<yh_dual::YhDual>("yh_dual_topic", 100);

    ros::Rate loop_rate(8); //0.125초마다
    
    yh_dual::YhDual msg;
    int cnt = 0;

    while(ros::ok()){
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