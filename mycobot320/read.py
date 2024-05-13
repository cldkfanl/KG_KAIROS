#!/usr/bin/env python
import sys
import rospy
import moveit_commander

def get_end_effector_pose():
    rospy.init_node('get_end_effector_pose_node', anonymous=True)
    
    moveit_commander.roscpp_initialize(sys.argv)
    
    robot = moveit_commander.RobotCommander()

    arm_group = moveit_commander.MoveGroupCommander("arm_group")

    end_effector_pose = arm_group.get_current_pose().pose
    
    rospy.loginfo("End Effector Pose (Position):")
    rospy.loginfo("X: {}".format(end_effector_pose.position.x))
    rospy.loginfo("Y: {}".format(end_effector_pose.position.y))
    rospy.loginfo("Z: {}".format(end_effector_pose.position.z))
    
    rospy.loginfo("End Effector Orientation:")
    rospy.loginfo("X: {}".format(end_effector_pose.orientation.x))
    rospy.loginfo("Y: {}".format(end_effector_pose.orientation.y))
    rospy.loginfo("Z: {}".format(end_effector_pose.orientation.z))
    rospy.loginfo("W: {}".format(end_effector_pose.orientation.w))

if __name__ == '__main__':
    try:
        get_end_effector_pose()
    except rospy.ROSInterruptException:
        pass
