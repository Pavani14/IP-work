#include <ros/ros.h>
#include <ip_work/pathPlanning.h>

using namespace std;

int main(int argc, char **argv){
	
  ros::init(argc, argv, "pathPlanning_node");
  ros::NodeHandle node;

  pathPlanning map(node);
  map.set_map();

  ros::spin();
 
  return 0;
}
