#include "ros/ros.h"
#include "std_msgs/Int64.h"

//callback : 이벤트가 발생했을때 호출되는 함수
//subscriber가 메시지는 subscribe 했을때 호출되는 함수
void msgCallback(const std_msgs::Int64::ConstPtr& msg){
    ROS_INFO("count : %d", msg->data);
}

int main(int argc, char** argv){

    ros::init(argc, argv, "my_test_subscriber"); //노드 이름 초기화
    ros::NodeHandle nh; //노드 핸들 선언

    //서브스크라이버 선언
    //패키지(std_msgs)의 메시지(Int64)를 이용한 서브스크라이버(sub)를 선언한다.
    //토픽은 (my_test_count)이며, 서브스크라이버큐(queue) 사이즈를 (100)으로 설정한다.
    ros::Subscriber sub = nh.subscribe("my_test_count", 100, msgCallback);

    // 콜백 함수 호출을 위한 함수, 메시지가 수신되기를 대기
    // 수신되었을 경우, 콜백 함수를 호출한다.
    ros::spin();

    return 0;
}