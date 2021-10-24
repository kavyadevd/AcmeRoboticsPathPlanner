/**
 * @file robot.h
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam
 * (aswath@umd.edu)
 * @brief The header file for coordinate system used in the project
 * @version 0.1
 * @date 2021-10-04
 * @copyright Copyright (c) 2021
 *
 */

#ifndef ROBOT_H_  // NOLINT
#define ROBOT_H_
#include <Eigen/Dense>
#include <vector>

#include "simulator.h"  // NOLINT
#include "state.h"      // NOLINT

using namespace Eigen;
class Robot : public State {  // Robot inherits State class public members
 public:
  /**
   * @brief Construct a new robot object. Sets default values to all attributes
   */
  Robot();

  /**
   * @brief Method will set the environment variables
   * @return bool flag indicating successful operation
   */
  bool Initialize(Simulator* simulator);

  /**
   * @brief Method will set the environment variables
   * @return bool flag indicating successful operation
   */
  bool Solver();

  /**
   * @brief Method will set the solve for trajectory
   * @return bool flag indicating successful operation
   */
  bool TrajectoryPlanner();

  /**
   * @brief Method collects waypoints and feeds successive points for simulation
   * @return bool flag indicating successful operation
   */
  bool Controller();

  /**
   * @brief Method to invoke simulator with desired joint actions
   * @return bool flag indicating successful operation
   */
  bool Simulate();

  /**
   * @brief Method to execute forward kinematics given the joint angles.
   * @param t1 Angle in radians of joint 1.
   * @param t2 Angle in radians of joint 2.
   * @param t3 Angle in radians of joint 3.
   * @param t4 Angle in radians of joint 4.
   * @param t5 Angle in radians of joint 5.
   * @param t6 Angle in radians of joint 6.
   */
  void ForwardKinematics(float t1, float t2, float t3, float t4, float t5,
                         float t6);

  /**
   * @brief Method to execute forward kinematics given the joint angles.
   * @return Vector of size 3, containing x,y,z values of end effector.
   */
  VectorXf GetEndEffectorPosition();

 private:
  Simulator* simulator;  ///< Reference object to Simulator class object.
  simxInt origin_handle;
  std::vector<simxInt> joint_handle;
  std::vector<simxInt> link_handle;
  std::vector<float*> joint_matrix;
  std::vector<float*> link_matrix;

};

#endif  // ROBOT_H_  // NOLINT