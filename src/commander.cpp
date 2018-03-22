/** Authors
 * Anush S Kumar (anushkumar27@gmail.com)
 * Sushrith Arkal (sushrith.arkal@gmail.com)
**/

// Dummy client node to command the planner
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>

int main(int argc, char **argv) {   
	// Initialise ros node and advertise to roscore
	ros::init(argc, argv, "commander");

	// NodeHandle is the main access point to communications with the ROS system.
	ros::NodeHandle nh;

    // Intitial value
    geometry_msgs::PoseStamped pose;
    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 0;

	// PUBLISHER
	// To publish the raw destination pose to the FCU
	ros::Publisher pos_pub = nh.advertise<geometry_msgs::PoseStamped>
			("auto_nav/planner/dest/pose", 10);

	// The setpoint publishing rate MUST be faster than 2Hz
	ros::Rate rate(20.0);

	while(ros::ok()) {
        
        pos_pub.publish(pose);
		ros::spinOnce();
		rate.sleep();
	}

	return 0;
}
