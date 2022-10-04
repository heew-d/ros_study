#include "ros/ros.h"
#include "yh_dual/YhDual.h"

void msgCallback(const yh_dual::YhDual::ConstPtr& msg){
    ROS_INFO("%d.%d", msg->stamp.sec, msg->stamp.nsec);
}

int main(int argc, char** argv){

    ros::init(argc, argv, "yh_dual_time"); // 노드 초기화
    ros::NodeHandle nh;

    // 서브스크라이버 선언
    // 패키지(yh_dual)의 메시지(YhDual)를 이용한 서브스크라이버(sub)를 선언한다
    // 토픽은 (yh_dual_topic)이며, 서브스크라이버큐(queue) 사이즈를 (100)으로 설정한다
    ros::Subscriber sub = nh.subscribe("yh_dual_topic", 100, msgCallback);

    ros::spin();

    return 0;
    
}