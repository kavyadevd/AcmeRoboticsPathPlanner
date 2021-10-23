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
  simxSetJointTargetPosition(simulator->GetClientID(), j1, 0.0,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), j1, 18.13,
                             simx_opmode_blocking);
  sleep(1);
  simxSetJointTargetPosition(simulator->GetClientID(), j2, 0.6,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), j3, 0.6,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), j4, 0.6,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), j5, 1.2,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), j6, 1.2,
                             simx_opmode_blocking);

  cout << "\n------Joint matrix--------" << endl;
  simulator->GetJointMatrix(j1, joint_matrix[1]);
  simulator->GetJointMatrix(j2, joint_matrix[2]);
  simulator->GetJointMatrix(j3, joint_matrix[3]);
  simulator->GetJointMatrix(j4, joint_matrix[4]);
  simulator->GetJointMatrix(j5, joint_matrix[5]);
  simulator->GetJointMatrix(j6, joint_matrix[6]);

  cout << "\n------Link matrix--------" << endl;
  simulator->GetJointMatrix(l1, joint_matrix[1]);
  simulator->GetJointMatrix(l2, joint_matrix[2]);
  simulator->GetJointMatrix(l3, joint_matrix[3]);
  simulator->GetJointMatrix(l4, joint_matrix[4]);
  simulator->GetJointMatrix(l5, joint_matrix[5]);
  simulator->GetJointMatrix(l6, joint_matrix[6]);

  simxFloat* pos;
  *pos = 1;
  sleep(1);
  simulator->GetJointMatrix(j1, joint_matrix[0]);
  simulator->SetJointPosition(j1, pos);
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
