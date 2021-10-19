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
   * @brief Construct a new Simulator object. Sets default values to all
   * attributes
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
   * @brief Sends Finish signal to CoppeliaSim .
   */
  void Stop();

  /**
   * @brief Returns client ID of our c++ program assigned by CoppeliaSim.
   * 
   * @return int returns active CoppeliaSim communication unique ID.
   */
  int GetClientID();

  /**
   * @brief Gets robot's joint matrix of specified joint.
   *
   * @param Joint reference of robot arm as int .
   * @param Matrix variable in which the joint matrix is filled by CoppeliaSim.
   */
  void GetJointMatrix(simxInt joint, float* matrix);

  /**
   * @brief Get the integer reference of an object given the object's name.
   *
   * @param The name of the object.
   * @return Integer reference to the object.
   */
  simxInt GetObjectHandle(char* name);

  /**
   * @brief Initialize communication with CoppeliaSim with remoteX API.
   *
   * @param Integer reference of Handle(arm joint) to get it's parent.
   * @return Integer reference of parent object.
   */
  simxInt GetParent(simxInt handle);

  /**
   * @brief Initialize communication with CoppeliaSim with remoteX API.
   *
   * @param Integer reference of the parent object.
   * @param To obtain the nth child from current parent object.
   * @return Integer reference of child object.
   */
  simxInt GetChild(simxInt parentObjectHandle, simxInt childIndex);

  /**
   * @brief Desctructor for Simulator class, calls Simulator::Stop()
   */
  ~Simulator();

 private:
  int client_ID_;  ///< Variable to store active CoppeliaSim communication
                   ///< unique ID.
                   /// client_ID = -1 if no connection
  bool connection_success_;  ///< Boolean flag to indicate active connection.
};

#endif  // SIMULATOR_H  // NOLINT
