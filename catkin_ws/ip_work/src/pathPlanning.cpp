#include <ip_work/pathPlanning.h>

pathPlanning::pathPlanning(ros::NodeHandle node){

	//set parameters from the node
	node.param("map_width", map_width_, 3);
	node.param("map_height", map_height_, 10);
	node.param("map_resolution", resolution_, 0.5);

	//set up the publishers
	map_publisher_ = node.advertise<nav_msgs::OccupancyGrid>("map", 1);
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

	for(int i = 0; i<number_of_cells_; i++)
		map.data[i] = 0;

        ROS_INFO("Map Initialized!!");

	map_publisher_.publish(map); 	
}
