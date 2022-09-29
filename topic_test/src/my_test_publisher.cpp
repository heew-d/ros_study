#include "ros/ros.h"
#include "std_msgs/Int64.h"

int main(int argc, char** argv){
    
    ros::init(argc, argv, "my_test_publisher"); //노드 이름 초기화
    ros::NodeHandle nh; // ROS 시스템과 통신을 위한 노드 핸들 선언

    //퍼블리셔 선언
    //패키지(std_msgs)의 메시지파일(Int64)을 이용한 퍼블리셔(pub)를 만든다.
    //토픽은 (my_test_count)이며, 퍼블리셔큐(queue) 사이즈는 (100)이다.
    //nh.advertise : 퍼블리셔를 만드는 함수
    ros::Publisher pub = nh.advertise<std_msgs::Int64>("my_test_count", 100);

    ros::Rate loop_rate(4); //0.25초 주기

    std_msgs::Int64 msg; //Int64 타입
    msg.data = 0; //msg의 data에 0을 넣는다.

    while (ros::ok()){
        pub.publish(msg); //pub이 msg를 퍼블리시한다.
        loop_rate.sleep(); //위에서 정한 주기에 따라 sleep 한다.
        msg.data++; //메시지에 담는 숫자는 매번 1씩 증가시키고
        if(msg.data == 101){ //100에 도달하면 다시 0부터 보낸다.
            msg.data=0;
        }
    }
    
    return 0;
}
