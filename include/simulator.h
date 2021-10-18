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

  int GetClientID();

  simxInt GetObjectHandle(char* name);

  simxInt GetParent(simxInt handle);

  simxInt GetChild(simxInt parentObjectHandle, simxInt childIndex);

  ~Simulator();  

 private:
  int client_ID_;
  bool connection_success_;
};

#endif  // SIMULATOR_H  // NOLINT
