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

bool Simulator::Initialize() {
  // Close any previously unfinished jobs in CoppeliaSim
  simxFinish(-1);
  // Main connection to CoppeliaSim
  client_ID_ = simxStart((simxChar*)"127.0.0.1", 19997, true, true, 5000, 5);
  sleep(1);
  connection_success_ = client_ID_ != -1;
  return connection_success_;
}

void Simulator::Stop() { simxFinish(client_ID_); }
