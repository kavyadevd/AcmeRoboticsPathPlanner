/**
 * @file simulator.h
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam
 * (aswath@umd.edu)
 * @brief The header file for arm manipulator path simulation
 * @version 0.1
 * @date 2021-09-30
 * @copyright Copyright (c) 2021
 *
 */

#ifndef SIMULATOR_H_  // NOLINT
#define SIMULATOR_H_

#include <unistd.h>
#include <iostream>
extern "C" {
#include "extApi.h"
}

class Simulator {
 public:
  /**
   * @brief Initialize communication with CoppeliaSim with remoteX API.
   *
   * @return true if program connects with CoppeliaSim successfully.
   * @return false if failed to connect with CoppeliaSim.
   */
  bool Initialize();

  void Stop();

  void getJoint();
  

 private:
  int client_ID_;
  bool connection_success_;
};

#endif  // SIMULATOR_H  // NOLINT
