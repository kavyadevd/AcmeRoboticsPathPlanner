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
    * @brief Construct a new Simulator object. Sets default values to all attributes
    */
    Simulator();

  /**
   * @brief Initialize communication with CoppeliaSim with remoteX API.
   *
   * @return true if program connects with CoppeliaSim successfully.
   * @return false if failed to connect with CoppeliaSim.
   */
  bool Initialize();

  /**
   * @brief Close open CoppeliaSim communication channels.
   */
  void Stop();

  /**
   * @brief Get CoppeliaSim connection ID.
   * @return int returns active CoppeliaSim communication unique ID.
   */
  int GetClientID();

  /**
   * @brief Set Joint matrix values.
   */
  void GetJointMatrix(simxInt joint, float* matrix);

  /**
   * @brief Fetch object handle.
   * @return int returns object handle.
   */
  simxInt GetObjectHandle(char* name);

  /**
   * @brief Fetch parent ID.
   * @return simxInt(int) returns object parent ID.
   */
  simxInt GetParent(simxInt handle);

  /**
   * @brief Fetch child ID.
   * @return simxInt(int) returns object child ID.
   */
  simxInt GetChild(simxInt parentObjectHandle, simxInt childIndex);

  /**
   * @brief Simulator destructor.
   */
  ~Simulator();

 private:
  int client_ID_;  ///< Variable to store active CoppeliaSim communication unique ID.
                   /// client_ID = -1 if no connection
  bool connection_success_;  ///< Boolean flag to indicate active connection.
};

#endif  // SIMULATOR_H  // NOLINT
