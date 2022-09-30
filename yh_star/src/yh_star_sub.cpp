#include "ros/ros.h"
#include "yh_star/YhStarMsg.h"

void msgCallback(const yh_star::YhStarMsg::ConstPtr& msg){
    ROS_INFO("receive msg : %d", msg->stamp.sec);
    ROS_INFO("receive msg : %d", msg->stamp.nsec);
    ROS_INFO("receive msg : %d", msg->data);

    int n = msg->data;
    
    for(int i=0;i<n/2;i++){
        for(int j=0;j<i+1;j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i=n/2;i<n;i++){
        for(int j=n;j>i;j--){
            printf("*");
        }
        printf("\n");
    }
}

int main(int argc, char** argv){
    ros::init(argc, argv, "yh_star_sub"); //노드 초기화
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("yh_star_topic", 10, msgCallback);

    ros::spin();


    

    return 0;
}