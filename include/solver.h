/**
 * @file solver.h
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam (aswath@umd.edu)
 * @brief The header file for arm manipulator path planning IK solver
 * @version 0.1
 * @date 2021-09-30
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ACMEROBOTICSPATHPLANNER_INCLUDE_SOLVER_H_  // NOLINT
#define ACMEROBOTICSPATHPLANNER_INCLUDE_SOLVER_H_

class Solver{
 public:
 /**
 * @brief Construct a new PID object. Sets values of kp, ki, kd to 0
 */
  Solver();
 /**
  * @brief Methods to solve IK
  * @return int flag indicating successful operation
  */ 
  int solve();
 private:
};

#endif  // ACMEROBOTICSPATHPLANNER_INCLUDE_SOLVER_H_  // NOLINT
