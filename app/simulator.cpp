/**
 * @file simulator.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu) - Driver, Aswath Muthuselvam
 * (aswath@umd.edu) - Navigator
 * @brief A program for result simulation implementation
 * @version 0.1
 * @date 2021-10-11
 * @copyright All rights reserved
 *
 */

#include "simulator.h"  // NOLINT

#include <unistd.h>

#include <iostream>

using std::cout;
using std::endl;

Simulator::Simulator() {
  client_ID_ = -1;
  connection_success_ = false;
}

bool Simulator::Initialize() {
  // Close any previously unfinished jobs in CoppeliaSim
  simxFinish(-1);
  // Main connection to CoppeliaSim
  client_ID_ =
      simxStart((simxChar*)"127.0.0.1", 19997, true, true, 5000, 5);  // NOLINT
  sleep(1);
  connection_success_ = client_ID_ != -1;

  if (connection_success_) {
    cout << "Connection to CoppeliaSim is successfull" << endl;
    simxSynchronous(client_ID_, 0);
    simxStopSimulation(client_ID_, simx_opmode_oneshot);
    sleep(1);
    simxStartSimulation(client_ID_, 1);
    sleep(3);
  } else {
    cout << "Unable to communicate with CoppeliaSim" << endl;
  }

  return connection_success_;
}

int Simulator::GetClientID() { return client_ID_; }

void Simulator::GetJointMatrix(simxInt joint, float* matrix) {
  simxGetJointMatrix(client_ID_, joint, matrix, simx_opmode_blocking);
  cout << "Joint matrix of Handle ID" << joint << ": " << endl
       << matrix[0] << "\t" << matrix[1] << "\t" << matrix[8] << "\t"
       << matrix[3] << endl
       << matrix[4] << "\t" << matrix[5] << "\t" << matrix[9] << "\t"
       << matrix[7] << endl
       << matrix[8] << "\t" << matrix[9] << "\t" << matrix[10] << "\t"
       << matrix[11] << endl
       << 0 << "\t" << 0 << "\t" << 0 << "\t" << 1 << endl
       << endl;
}

void Simulator::Stop() { simxFinish(client_ID_); }

simxInt Simulator::GetObjectHandle(char* name) {
  simxInt handle;
  simxGetObjectHandle(client_ID_, name, &handle, simx_opmode_oneshot_wait);
  return handle;
}

simxInt Simulator::GetParent(simxInt handle) {
  simxInt parentObjectHandle;
  simxGetObjectParent(client_ID_, handle, &parentObjectHandle,
                      simx_opmode_blocking);
  return parentObjectHandle;
}

simxInt Simulator::GetChild(simxInt parentObjectHandle,
                            simxInt childIndex = 0) {
  simxInt childObjectHandle;
  simxGetObjectChild(client_ID_, parentObjectHandle, childIndex,
                     &childObjectHandle, simx_opmode_blocking);
  return childObjectHandle;
}

simxInt Simulator::SetJointPosition(simxInt jointHandle, simxFloat* position) {
  simxInt status = simxSetJointPosition(client_ID_, jointHandle, *position,
                                        simx_opmode_blocking);
  return status;
}

simxInt Simulator::SetJointTargetAngle(simxInt jointHandle, simxFloat angle) {
  simxInt status = simxSetJointTargetPosition(client_ID_, jointHandle, angle,
                                              simx_opmode_blocking);
  return status;
}

float Simulator::GetJointAngle(simxInt jointHandle) {
  float angle;
  simxGetJointPosition(client_ID_, jointHandle, &angle, simx_opmode_blocking);
  return angle;
}

simxInt Simulator::GetObjectPosition(simxInt objectHandle,
                                     simxInt relativeObjectHandle,
                                     simxFloat* position) {
  simxInt status =
      simxGetObjectPosition(client_ID_, objectHandle, relativeObjectHandle,
                            position, simx_opmode_blocking);
  cout << "x: " << position[0] << " y: " << position[1] << " z: " << position[2]
       << endl;
  return status;
}

simxInt Simulator::GetObjectOrientation(simxInt objectHandle,
                                        simxInt relativeToObjectHandle,
                                        simxFloat* eulerAngles) {
  simxInt status =
      simxGetObjectOrientation(client_ID_, objectHandle, relativeToObjectHandle,
                               eulerAngles, simx_opmode_blocking);
  cout << "alpha: " << eulerAngles[0] << " beta: " << eulerAngles[1]
       << " gamma: " << eulerAngles[2] << endl;
  return status;
}

Simulator::~Simulator() { Simulator::Stop(); }
