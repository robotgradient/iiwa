#include <arm_manager/arm_manager.h>
#include "sensor_msgs/JointState.h"
#include "geometry_msgs/Pose.h"


class StateMachineIiwaHelper
{
	public:
	
		StateMachineIiwaHelper(ArmManager* arm_manager);
		~StateMachineIiwaHelper();


		//Grasping method
		int GraspObject(geometry_msgs::Pose pose);
		int GraspObject(std::vector<double> pose);

		int LeaveObject(int num_extracted_parts);

		void getDeliveryPlace(int frame, std::vector<double>& xyz, std::vector<double>& rpy);

		int moveSafePose();

		bool releaseProduct();

		std::vector<double> FromPose2Vector(geometry_msgs::Pose pose);
		geometry_msgs::Pose container_pose;


		std::vector<double> leave_pose;
		std::vector<double> safety_pose;

	private:
		
		//Arm and gripper manager
		ArmManager* arm_manager_;

		ros::NodeHandle nh_;

		//FollowJointTrajectoryController topic subscriber and callback
		ros::Subscriber joint_state_sub_;



		bool sync_;
		

};
