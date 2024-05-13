#!/usr/bin/env python
import sys
import rospy
import moveit_commander
from moveit_msgs.msg import MoveItErrorCodes
from geometry_msgs.msg import PoseStamped

def move_to_pose():
    # ROS 노드 초기화
    rospy.init_node('move_to_pose_node', anonymous=True)
    
    # MoveIt! 초기화
    moveit_commander.roscpp_initialize(sys.argv)
    
    # 로봇 모델 로딩
    robot = moveit_commander.RobotCommander()

    # 로봇 팔 그룹 초기화
    arm_group = moveit_commander.MoveGroupCommander("arm_group")
    
    current_joint_values = arm_group.get_current_joint_values()
    print("Current joint values:", current_joint_values)
    
    # MoveIt! 설정
    arm_group.set_planning_time(10.0)  # 계획 시간을 10초로 설정
    arm_group.set_goal_tolerance(0.01)  # 목표 허용 오차를 0.01로 설정
    arm_group.set_num_planning_attempts(10)  # 계획 시도 횟수를 10회로 설정
    arm_group.allow_replanning(True)  # 계획 재시도를 허용합니다.
    
    # 목표 포즈 생성
    target_pose = PoseStamped()
    target_pose.pose.position.x = 3.12009353091022e-05
    target_pose.pose.position.y = -0.1370012869285968
    target_pose.pose.position.z = 0.5230000125024876
    target_pose.pose.orientation.x = 5.123490990843974e-05
    target_pose.pose.orientation.y = -0.7071080795300609
    target_pose.pose.orientation.z = 0.707105478539869
    target_pose.pose.orientation.w = 5.879792857698589e-05
    
    
    arm_group.set_pose_target(target_pose)
    plan = arm_group.go(wait=True)
    
    
    # # 예상되는 모터 조인트 값을 계산
    # expected_joint_values = arm_group.compute_cartesian_path([target_pose.pose], 0.01, 0.0)
    # print("Expected joint values:", expected_joint_values)

if __name__ == '__main__':
    try:
        move_to_pose()
    except rospy.ROSInterruptException:
        pass
