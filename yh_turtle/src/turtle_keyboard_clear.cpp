// 특정 키를 누르면  clear 하는 노드
// 1. cmd_vel에서 명령오면 받기
// 2. 받은거 turtlesim에 보내기
// 3. 배경 지우기(clear)

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_srvs/Empty.h"

// 퍼블리셔, 클라이언트 전역 변수로 선언
// 콜백에서 실행되어야하기 때문 -> 클라이언트가 call 해야하니까
ros::Publisher pub;
ros::ServiceClient clear_client;
std_srvs::Empty srv;

void msgCallback(const geometry_msgs::Twist::ConstPtr& msg){
    pub.publish(*msg);
    if (msg->linear.z > 0.0){ //msg->linear.z : 기본적으로 0이 들어가있음. t를 눌렀을때
        if(clear_client.call(srv)){ // 클라이언트가 서비스 통신한것. 통신이 잘 되면 if문 수행
            ROS_INFO("CLEAR");
        }
        else{
            ROS_ERROR("FAILED");
        }
    }
}

int main(int argc, char** argv){
    
    ros::init(argc, argv, "turtle_keyboard_clear"); // 노드 이름 초기화
    ros::NodeHandle nh;

    pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 100);
    clear_client = nh.serviceClient<std_srvs::Empty>("clear");
    ros::Subscriber sub = nh.subscribe("cmd_vel", 100, msgCallback);

    ros::spin();
    
    return 0;
}