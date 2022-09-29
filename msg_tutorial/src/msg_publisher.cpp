#include "ros/ros.h"
#include "msg_tutorial/Mymsg.h" // Mymsg 헤더 파일
                                // 빌드시 자동 생성(우리가 만든 파일의 확장자는 .msg -> cmake에서 메시지 정의하는 설정을 바꿔야함)
//.msg는 ROS에서 정의하는 메시지 확장자. C에서 쓰려면 .h라는 헤더 파일로 써야해서
//빌드시에 h로 확장자 변경

int main(int argc, char** argv){
    
    ros::init(argc, argv, "msg_publisher"); //노드 이름 초기화
    ros::NodeHandle nh; //ROS 시스템과 통신을 위한 노드 핸들 선언

    //퍼블리셔 선언
    //패키지(msg_tutorial)의 메시지파일(Mymsg)을 이용한 퍼블리셔(pub)를 만든다.
    //토픽은 (burger)이며, 퍼블리셔큐(queue) 사이즈는 (20)이다.
    //nh.advertise : 퍼블리셔를 만드는 함수
    ros::Publisher pub = nh.advertise<msg_tutorial::Mymsg>("burger", 20); 

    ros::Rate loop_rate(2);

    msg_tutorial::Mymsg msg;
    int cnt = 0;
    
    while(ros::ok()){
        /*
        msg{
            time stamp //time 자료형에 sec, nsec 멤버 변수가 있다.
            int32 data
        }
        */
       msg.stamp = ros::Time::now(); //현재 시간을 msg의 stamp에 담는다.
       msg.data = cnt; //cnt 변수의 값을 msg의 data에 담는다.
       //sec.nsec
       ROS_INFO("send msg : %d", msg.stamp.sec); //stamp.sec를 출력한다.
       ROS_INFO("send msg : %d", msg.stamp.nsec); //stap.nsec를 출력한다. (나노sec)
       ROS_INFO("send msg : %d", msg.data); //data를 출력한다.
        //퍼블리셔쪽에서 메시지를 보내기 전에 출력

       pub.publish(msg); //pub이 msg를 퍼블리시한다.
       cnt++;
       loop_rate.sleep();
    }

    return 0;
}
