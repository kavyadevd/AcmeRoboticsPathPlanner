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

#include <unistd.h>

#include <iostream>

#include "simulator.h"  // NOLINT

using std::cout;
using std::endl;

Robot::Robot() {}

bool Robot::Initialize(Simulator* simulator) {
  char name_joint1[] = "UR5_joint1";
  char name_joint2[] = "UR5_joint2";
  char name_joint3[] = "UR5_joint3";
  char name_joint4[] = "UR5_joint4";
  char name_joint5[] = "UR5_joint5";
  char name_joint6[] = "UR5_joint6";

  char name_link1[] = "UR5_link1";
  char name_link2[] = "UR5_link2";
  char name_link3[] = "UR5_link3";
  char name_link4[] = "UR5_link4";
  char name_link5[] = "UR5_link5";
  char name_link6[] = "UR5_link6";

  simxInt j1 = simulator->GetObjectHandle(name_joint1);
  simxInt j2 = simulator->GetObjectHandle(name_joint2);
  simxInt j3 = simulator->GetObjectHandle(name_joint3);
  simxInt j4 = simulator->GetObjectHandle(name_joint4);
  simxInt j5 = simulator->GetObjectHandle(name_joint5);
  simxInt j6 = simulator->GetObjectHandle(name_joint6);

  simxInt l1 = simulator->GetObjectHandle(name_link1);
  simxInt l2 = simulator->GetObjectHandle(name_link2);
  simxInt l3 = simulator->GetObjectHandle(name_link3);
  simxInt l4 = simulator->GetObjectHandle(name_link4);
  simxInt l5 = simulator->GetObjectHandle(name_link5);
  simxInt l6 = simulator->GetObjectHandle(name_link6);

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
}

bool Robot::Solver() { return true; }

bool Robot::TrajectoryPlanner() { return true; }

bool Robot::Controller() { return true; }

bool Robot::Simulate() { return true; }
