#include "ros/ros.h" //ROS 헤더파일
#include "std_msgs/String.h" //std_msgs 패키지의 String 메시지 헤더파일


//callback : 이벤트가 발생했을때 호출되는 함수
//subscriber가 메시지를 subscribe 했을 때 호출되는 함수
void msgCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("msg : %s", msg->data.c_str()); //*msg.data = msg->data
    //c_str() : c 스타일의 문자열로 바꿔서 출력해야 한다.
}

int main(int argc, char** argv){
    
    ros::init(argc, argv, "my_subscriber"); //노드 이름 초기화(마스터에게 들어갈 정보)
    ros::NodeHandle nh; //노드 핸들 선언 (통신을 핸들링)

    //서브스크라이버 선언
    //패키지(std_msgs)의 메시지(String)를 이용한 서브스크라이버(sub)를 선언한다.
    //토픽은 (my_topic)이며, 서브스크라이버큐(queue) 사이즈를 (100)으로 설정한다.
    //콜백 함수는 (msgCallback)이다.
    ros::Subscriber sub = nh.subscribe("my_topic", 100, msgCallback);
    //subscriber가 메시지를 받았을 때 msgCallback 함수를 호출


    // 콜백 함수 호출을 위한 함수, 메시지가 수신되기를 대기
    // 수신되었을 경우 콜백 함수를 호출한다.
    ros::spin(); //(다른 동작을 멈춤. 계속해서 대기)
    
    return 0;
}