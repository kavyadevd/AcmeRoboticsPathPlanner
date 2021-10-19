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
  simxInt j1 = simulator->GetObjectHandle(name_joint1);
  simxInt j2 = simulator->GetObjectHandle(name_joint2);
  simxInt j3 = simulator->GetObjectHandle(name_joint3);
  simxInt j4 = simulator->GetObjectHandle(name_joint4);
  simxInt j5 = simulator->GetObjectHandle(name_joint5);
  simxInt j6 = simulator->GetObjectHandle(name_joint6);

  cout << "Starting Froward Kinematics Demo" << endl;
  simxSetJointTargetPosition(simulator->GetClientID(), j1, 0.6,
                             simx_opmode_blocking);
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

  // Get joint Matrix
  float matrix[12];
  simulator->GetJointMatrix(j1, matrix);

  cout << "Joint matrix of joint 1: " << endl
       << matrix[0] << " " << matrix[1] << " " << matrix[2] << endl
       << matrix[3] << " " << matrix[4] << " " << matrix[5] << endl
       << matrix[6] << " " << matrix[7] << " " << matrix[8] << endl
       << matrix[9] << " " << matrix[10] << " " << matrix[11] << endl;
  return true;
}

bool Robot::Solver() { return true; }

bool Robot::TrajectoryPlanner() { return true; }

bool Robot::Controller() { return true; }

bool Robot::Simulate() { return true; }
