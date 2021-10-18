/**
 * @file main.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu) - Driver, Aswath Muthuselvam
 * (aswath@umd.edu) - Navigator
 * @brief A program for arm manipulator path planning
 * @version 0.1
 * @date 2021-10-05
 * @copyright All rights reserved
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>

#include "robot.h"
#include "simulator.h"

using std::cout;
using std::endl;

int main() {
  Simulator simulator;
  Robot robot;
  if (simulator.Initialize()) {
    cout << " Connection status to VREP: SUCCESS" << endl;
  }

  robot.Initialize();

  char* name = "UR5_joint1";
  simxInt parent = simulator.GetObjectHandle(name);
  simxInt j1 = simulator.GetObjectHandle("UR5_joint1");
  simxInt j2 = simulator.GetObjectHandle("UR5_joint2");
  simxInt j3 = simulator.GetObjectHandle("UR5_joint3");
  simxInt j4 = simulator.GetObjectHandle("UR5_joint4");
  simxInt j5 = simulator.GetObjectHandle("UR5_joint5");
  simxInt j6 = simulator.GetObjectHandle("UR5_joint6");

  cout << "Starting Froward Kinematics Demo" << endl;
  simxSetJointTargetPosition(simulator.GetClientID(), j1, 0.6,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator.GetClientID(), j2, 0.6,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator.GetClientID(), j3, 0.6,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator.GetClientID(), j4, 0.6,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator.GetClientID(), j5, 1.2,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator.GetClientID(), j6, 1.2,
                             simx_opmode_blocking);

  // Get joint Matrix
  float* matrix;
  simulator.GetJointMatrix(j1, matrix);

  cout << "Joint matrix of joint 1: " << endl
       << matrix[0] << " " << matrix[1] << " " << matrix[2] << endl
       << matrix[3] << " " << matrix[4] << " " << matrix[5] << endl
       << matrix[6] << " " << matrix[7] << " " << matrix[8] << endl
       << matrix[9] << " " << matrix[10] << " " << matrix[11] << endl;

  return true;
}
