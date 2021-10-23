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

  std::vector<simxInt> joint_handle[6];

  simxInt j1 = simulator->GetObjectHandle(joint[0]);
  simxInt j2 = simulator->GetObjectHandle(joint[1]);
  simxInt j3 = simulator->GetObjectHandle(joint[2]);
  simxInt j4 = simulator->GetObjectHandle(joint[3]);
  simxInt j5 = simulator->GetObjectHandle(joint[4]);
  simxInt j6 = simulator->GetObjectHandle(joint[5]);

  simxInt l1 = simulator->GetObjectHandle(link[0]);
  simxInt l2 = simulator->GetObjectHandle(link[1]);
  simxInt l3 = simulator->GetObjectHandle(link[2]);
  simxInt l4 = simulator->GetObjectHandle(link[3]);
  simxInt l5 = simulator->GetObjectHandle(link[4]);
  simxInt l6 = simulator->GetObjectHandle(link[5]);

  // Get joint Matrix
  float T00[12];
  float T01[12];
  float T02[12];
  float T03[12];
  float T04[12];
  float T05[12];
  float T06[12];

  cout << "\n------Joint matrix--------";
  simulator->GetJointMatrix(j1, T01);
  simulator->GetJointMatrix(j2, T02);
  simulator->GetJointMatrix(j3, T03);
  simulator->GetJointMatrix(j4, T04);
  simulator->GetJointMatrix(j5, T05);
  simulator->GetJointMatrix(j6, T06);

  cout << "\n------Link matrix--------";
  simulator->GetJointMatrix(l1, T01);
  simulator->GetJointMatrix(l2, T02);
  simulator->GetJointMatrix(l3, T03);
  simulator->GetJointMatrix(l4, T04);
  simulator->GetJointMatrix(l5, T05);
  simulator->GetJointMatrix(l6, T06);

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
  simulator->GetJointMatrix(j1, T01);
  simulator->GetJointMatrix(j2, T02);
  simulator->GetJointMatrix(j3, T03);
  simulator->GetJointMatrix(j4, T04);
  simulator->GetJointMatrix(j5, T05);
  simulator->GetJointMatrix(j6, T06);

  cout << "\n------Link matrix--------" << endl;
  simulator->GetJointMatrix(l1, T01);
  simulator->GetJointMatrix(l2, T02);
  simulator->GetJointMatrix(l3, T03);
  simulator->GetJointMatrix(l4, T04);
  simulator->GetJointMatrix(l5, T05);
  simulator->GetJointMatrix(l6, T06);

  simxFloat* pos;
  *pos = 1;
  sleep(1);
  simulator->GetJointMatrix(j1, T01);
  simulator->SetJointPosition(j1, pos);
  cout << pos[0];
  return true;
} catch (const char *msg) /* catch exception if any */
	{
		std::cout << "Exception occurred" << std::endl;
	}
}

bool Robot::Solver() { return true; }

bool Robot::TrajectoryPlanner() { return true; }

bool Robot::Controller() { return true; }

bool Robot::Simulate() { return true; }
