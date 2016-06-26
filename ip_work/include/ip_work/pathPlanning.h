#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/MapMetaData.h>
#include <std_msgs/Header.h>
#include <iostream>
#include <stdio.h>

class pathPlanning
 {
 public:
 	pathPlanning(ros::NodeHandle &node);
 	~pathPlanning();

 	void set_map();

 private:
 	//Parameters which can be set via the parameter server
 	int map_height_, map_width_;
 	double resolution_;
 	int number_of_cells_;

	nav_msgs::OccupancyGrid map;

 	//ROS Topics
 	ros::Publisher map_publisher_;
 }; 
