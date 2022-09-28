#include "ros/ros.h" //ROS 헤더파일
#include "std_msgs/Int32.h" //1byte 8bit //32bit 4byte

int main(int argc, char** argv){
    
    ros::init(argc, argv, "second_pub"); //노드 이름 초기화
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::Int32>("my_count", 100);

    ros::Rate loop_rate(2); //0.5초마다 퍼블리시

    std_msgs::Int32 msg;
    msg.data = 0;

    while(ros::ok()){
        pub.publish(msg);
        loop_rate.sleep();
        msg.data++;
    }
    
    return 0;
}