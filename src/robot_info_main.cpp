#include <ros/ros.h>
#include "robot_info/robot_info.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/init.h"

int main(int argc, char** argv) 

{

    ros::init(argc, argv, "robot_info_node");
    RobotInfo robot;
    robot.publish_data();
    ros::spin();
    
    return 0;
}



