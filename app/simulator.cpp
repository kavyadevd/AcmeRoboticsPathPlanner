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

bool Simulator::Initialize() {
  // Close any previously unfinished jobs in CoppeliaSim
  simxFinish(-1);
  // Main connection to CoppeliaSim
  client_ID_ = simxStart((simxChar*)"127.0.0.1", 19997, true, true, 5000, 5);
  sleep(1);
  connection_success_ = client_ID_ != -1;
  
  if(connection_success_){
    simxSynchronous(client_ID_, 0);
    simxStartSimulation(client_ID_, 1);
  }

  return connection_success_;
}

int Simulator::GetClientID(){
  return client_ID_;
}

void Simulator::Stop() { 
  simxStopSimulation(client_ID_, simx_opmode_oneshot);
  simxFinish(client_ID_); 
}

simxInt Simulator::GetObjectHandle(char* name){
  simxInt handle;
  simxGetObjectHandle(client_ID_, name, &handle, simx_opmode_oneshot_wait);
  return handle;
}

simxInt Simulator::GetParent(simxInt handle){
  simxInt parentObjectHandle;
  simxGetObjectParent(client_ID_,handle, 
  &parentObjectHandle,simx_opmode_blocking);
  return parentObjectHandle;
}

simxInt Simulator::GetChild(simxInt parentObjectHandle, simxInt childIndex=0){
  simxInt childObjectHandle;
  simxGetObjectChild(client_ID_, parentObjectHandle
  ,childIndex, &childObjectHandle, simx_opmode_blocking);
  return childObjectHandle;
}

Simulator::~Simulator(){
  Simulator::Stop();
}
