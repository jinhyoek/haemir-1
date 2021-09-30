/*
 *  YDLIDAR SYSTEM
 *  YDLIDAR ROS Node Client 
 *
 *  Copyright 2015 - 2018 EAI TEAM
 *  http://www.ydlidar.com
 * 
 */

#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

#define RAD2DEG(x) ((x)*180./M_PI)

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
    int count = scan->scan_time / scan->time_increment;
    //printf("[YDLIDAR INFO]: I heard a laser scan %s[%d]:\n", scan->header.frame_id.c_str(), count);
    printf("[YDLIDAR INFO]: angle_range : [%f, %f]\n", RAD2DEG(scan->angle_min), RAD2DEG(scan->angle_max));
	std::cout << RAD2DEG(scan->angle_increment)<< " , " << count << std::endl;
	std::cout << scan->scan_time << " , " << scan->time_increment << count << std::endl;
  
        for(int i = 0; i < count/2; i++) {
        float degree = RAD2DEG(scan->angle_min + scan->angle_increment * i);
	float z = i;
//	if(degree >  -1 && degree <1)
  //      	printf("[YDLIDAR INFO]: angle-distance : [%f, %f, %i]\n", degree, scan->ranges[i], i);
	std::cout << z /count * 360 << " , " << scan->ranges[i] << std::endl;
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "ydlidar_client");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 1000, scanCallback);
    ros::spin();

    return 0;
}
