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
  // Simulator();

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
  virtual int GetClientID() = 0;

  /**
   * @brief Gets robot's joint matrix of specified joint.
   *
   * @param joint Joint reference of robot arm as int .
   * @param matrix Matrix variable in which the joint matrix is filled by
   * CoppeliaSim.
   */
  void GetJointMatrix(simxInt joint, float* matrix);

  /**
   * @brief Get the integer reference of an object given the object's name.
   *
   * @param name The name of the object.
   * @return Integer reference to the object.
   */
  simxInt GetObjectHandle(char* name);

  /**
   * @brief Get Parent object from CoppeliaSim with remoteX API.
   *
   * @param handle Integer reference of Handle(arm joint) to get it's parent.
   * @return Integer reference of parent object.
   */
  simxInt GetParent(simxInt handle);

  /**
   * @brief Get child object from CoppeliaSim with remoteX API.
   *
   * @param parentObjectHandle Integer reference of the parent object.
   * @param childIndex To obtain the nth child from current parent object.
   * @return Integer reference of child object.
   */
  simxInt GetChild(simxInt parentObjectHandle, simxInt childIndex);

  /**
   * @brief Set the joint angle of robotic arm with CoppeliaSim with remoteX
   * API.
   *
   * @param jointHandle Integer reference of the parent object.
   * @param position Position of the arm to rotate(angular degrees or prismatic
   * length).
   * @return Returns operation status.
   */
  simxInt SetJointPosition(simxInt jointHandle, simxFloat* position);

  /**
   * @brief Sends command to CoppeliaSim's arm controller to move the arm to set
   * position.
   *
   * @param jointHandle Integer reference of the joint.
   * @param angle Angle of the arm to rotate(angular degrees or prismatic
   * length).
   * @return Returns operation status.
   */
  simxInt SetJointTargetAngle(simxInt jointHandle, simxFloat angle);

  /**
   * @brief Gets the joint angle of given joint Handle.
   *
   * @param jointHandle Integer reference of the joint.
   * @return Returns the joint angle.
   */
  float GetJointAngle(simxInt jointHandle);

  /**
   * @brief Gets the position of object position.
   *
   * @param objectHandle Integer reference of the joint.
   * @param relativeObjectHandle Integer reference of the joint with respect
   * to which position needs to be calculated.
   * @param position Float array where the 3 output values(x,y,z) will be
   * stored.
   * @return Returns operation status.
   */
  simxInt GetObjectPosition(simxInt objectHandle, simxInt relativeObjectHandle,
                            simxFloat* position);

  /**
   * @brief Gets the orientation of object.
   *
   * @param objectHandle Integer reference of the joint.
   * @param relativeObjectHandle Integer reference of the joint with respect
   * to which orientation needs to be calculated.
   * @param eulerAngles Float array where the 3 output values(alpha, beta,
   * gamma) will be stored.
   * @return Returns operation status.
   */
  simxInt GetObjectOrientation(simxInt objectHandle,
                               simxInt relativeToObjectHandle,
                               simxFloat* eulerAngles);

  /**
   * @brief Desctructor for Simulator class, calls Simulator::Stop()
   */
  virtual ~Simulator();

 private:
  int client_ID_;  ///< Variable to store active CoppeliaSim communication
                   ///< unique ID.
                   /// client_ID = -1 if no connection
  bool connection_success_;  ///< Boolean flag to indicate active connection.
};

#endif  // SIMULATOR_H  // NOLINT
