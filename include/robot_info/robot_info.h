#pragma once 
#ifndef ROBOT_INFO_H
#define ROBOT_INFO_H

#include <ros/ros.h>
#include <string>
#include "robotinfo_msgs/RobotInfo10Fields.h"

class RobotInfo
{
    public:
        RobotInfo();
        virtual void publish_data();
    private:
        ros::Publisher robotInfo_Publisher;
        ros::NodeHandle nh;
        robotinfo_msgs::RobotInfo10Fields info_msg;
        ros::Rate loop_rate;
    protected:
        std::string robot_description = "i2Robotics";
        std::string serial_number = "000364217";
        std::string ip_address = "1980339";
        std::string firmware_version = "1.0.0";
        std::string info_topic = "/robot_info";
        
              
};

#endif // ROBOT_INFO_H