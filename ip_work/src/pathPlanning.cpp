#include <ip_work/pathPlanning.h>

pathPlanning::pathPlanning(ros::NodeHandle &node){

	map_width_  = 3; 
	map_height_ = 10;
	resolution_ = 0.5;
	
	//set parameters from the node
	node.setParam("map_width", map_width_);
	node.setParam("map_height", map_height_);
	node.setParam("map_resolution", resolution_5);

	//set up the publishers
	map_publisher_ = node.advertise<nav_msgs::OccupancyGrid>("map", 1);
	ros::Duration(0.5).sleep();
}

pathPlanning::~pathPlanning(){}

void pathPlanning::set_map(){
	map.info.map_load_time = ros::Time::now();
	map.info.resolution = resolution_;
	map.info.width = map_width_;
	map.info.height = map_height_;
	map.info.origin.position.x = 0.0;
	map.info.origin.position.y = 0.0;
	map.info.origin.position.z = 0.0; 
	map.info.origin.orientation.x = 0.0;
	map.info.origin.orientation.y = 0.0;
	map.info.origin.orientation.z = 0.0;
	
	number_of_cells_ = (map_width_ * map_height_)/(resolution_ * resolution_);

	// Allocate space to hold the data
	map.data.resize(number_of_cells_);

	for(int i = 0; i<number_of_cells_; i++)
		map.data[i] = 0;

        ROS_INFO("Map Initialized!!");

	map_publisher_.publish(map);
}
