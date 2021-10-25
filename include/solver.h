/**
 * @file solver.h
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam (aswath@umd.edu)
 * @brief The header file for arm manipulator path planning IK solver
 * @version 0.1
 * @date 2021-09-30
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SOLVER_H_  // NOLINT
#define SOLVER_H_
#include "simulator.h"  // NOLINT
#include "solver.h"  // NOLINT
#include <vector>  // NOLINT

using std::vector;

class Solver{
 public:
 /**
 * @brief Construct a new solver object. Sets default values to all attributes
 */
  Solver(Simulator* simulator, vector<simxInt> joint_handle);

 /**
  * @brief Methods to Solve IK
  * @param dx x-coordinate of small displacement towards goal position
  * @param dy y-coordinate of small displacement towards goal position
  * @param dz z-coordinate of small displacement towards goal position
  * @return MatrixXd Matrix of computed joint angles
  */  
  MatrixXd PerformIK(double dx, double dy, double dz);

   /**
   * @brief Updates the error_tolerance attribute to _error
   * @param _error : Integral constant value to be set
   * @return bool true if value set successful
   */
  bool SetErrorTolerance(double _error);

   /**
   * @brief Fetched the error_tolerance attribute 
   * @return error_tolerance value of object
   */
  double GetErrorTolerance();

   /**
   * @brief Checks if error is tolerant 
   * @param _error : double error value in system
   * @return true if error is tolerant, otherwise returns false
   */
  bool IsErrorTolerable(double _error);


 private:
  double error_tolerance;  ///< Variable to set error tolerance
  Simulator* simulator;  ///< Variable reference to active simulator object
  std::vector<simxInt> joint_handle;  ///< Variable for storing all robot joint handles
};

#endif  // SOLVER_H_  // NOLINT
