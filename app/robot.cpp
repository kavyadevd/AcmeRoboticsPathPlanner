/**
 * @file robot.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam
 * (aswath@umd.edu)
 * @brief File for robot class method definitions
 * @version 0.1
 * @date 2021-10-05
 * @copyright All rights reserved
 *
 */

#include "robot.h"  // NOLINT
#include <unistd.h>  // For sleep function
#include <vector>
#include <iostream>
#include "simulator.h"  // NOLINT

using std::cout;
using std::endl;

Robot::Robot() {}

bool Robot::Initialize(Simulator* simulator) {
  try {
  ///< Variable to store robot joint names
  std::vector<char*> joint = {"UR5_joint1", "UR5_joint2", "UR5_joint3", "UR5_joint4", "UR5_joint5", "UR5_joint6"};

  ///< Variable to store robot link names
  std::vector<char*> link = {"UR5_link1", "UR5_link2", "UR5_link3", "UR5_link4", "UR5_link5", "UR5_link6"};

  std::vector<simxInt> joint_handle;
  std::vector<simxInt> link_handle;
  std::vector<float[12]> joint_matrix;

  for (int it = 0; it < 6; it++) {
    joint_handle[it] = simulator->GetObjectHandle(joint[it]);
    link_handle[it] = simulator->GetObjectHandle(link[it]);

    cout << "\n------Joint matrix " << it << " --------\n";
    simulator->GetJointMatrix(joint_handle[it], joint_matrix[it+1]);

    cout << "\n------Link matrix " << it << " --------\n";
    simulator->GetJointMatrix(link_handle[it], joint_matrix[it+1]);
  }

  cout << "Starting Froward Kinematics Demo" << endl;
  simxSetJointTargetPosition(simulator->GetClientID(), joint_handle[0], 0.0,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), joint_handle[0], 18.13,
                             simx_opmode_blocking);
  sleep(1);
  simxSetJointTargetPosition(simulator->GetClientID(), joint_handle[1], 0.6,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), joint_handle[2], 0.6,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), joint_handle[3], 0.6,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), joint_handle[4], 1.2,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), joint_handle[5], 1.2,
                             simx_opmode_blocking);

  cout << "\n------Joint matrix--------" << endl;
    for (int it = 0; it < 6; it++) {
    cout << "\n------Joint matrix " << it << " --------\n";
    simulator->GetJointMatrix(joint_handle[it], joint_matrix[it+1]);

    cout << "\n------Link matrix " << it << " --------\n";
    simulator->GetJointMatrix(link_handle[it], joint_matrix[it+1]);
  }

  simxFloat* pos;
  *pos = 1;
  sleep(1);
  simulator->GetJointMatrix(joint_handle[0], joint_matrix[0]);
  simulator->SetJointPosition(joint_handle[0], pos);
  cout << pos[0];
  return true;
} catch (const char *msg) { /* catch exception if any */
  std::cout << "Exception occurred" << std::endl;
}
}

bool Robot::Solver() { return true; }

bool Robot::TrajectoryPlanner() { return true; }

bool Robot::Controller() { return true; }

bool Robot::Simulate() { return true; }
