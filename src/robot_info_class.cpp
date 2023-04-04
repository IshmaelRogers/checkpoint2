#include "robot_info/robot_info.h"
#include <iostream>
#include <ros/ros.h>
#include <string.h>



RobotInfo::RobotInfo()
    : loop_rate(1)

{ std::cout << "RobotInfo constructor called" << std::endl;
  
  nh = ros::NodeHandle("~");
  robotInfo_Publisher = nh.advertise<robotinfo_msgs::RobotInfo10Fields>(info_topic, 100000);

  

  
}

void RobotInfo::publish_data() {

//std::cout << "Entering publish_data()" << std::endl;
 

  while (ros::ok()) {
  //std::cout << "Inside the while loop" << std::endl;
  
  info_msg.data_field_01 = robot_description;
  info_msg.data_field_02 = serial_number;
  info_msg.data_field_03 = ip_address;
  info_msg.data_field_04 = firmware_version;
  robotInfo_Publisher.publish(info_msg);
  
  /*
  std::cout << "Robot Description: " << info_msg.data_field_01 << std::endl;
  std::cout << "Serial Number: " << info_msg.data_field_02 << std::endl;
  std::cout << "IP Address: " << info_msg.data_field_03 << std::endl;
  std::cout << "Firmware: " << info_msg.data_field_04 <<std::endl;
  */
    /*
    ROS_INFO_STREAM("Robot Description: " << info_msg.data_field_01);
    ROS_INFO_STREAM("Serial Number: " << info_msg.data_field_02);
    ROS_INFO_STREAM("IP Address: " << info_msg.data_field_03);
    ROS_INFO_STREAM("Firmware: " << info_msg.data_field_04);
  */
  ros::spinOnce();
  loop_rate.sleep();
 
  }

 
  
}
