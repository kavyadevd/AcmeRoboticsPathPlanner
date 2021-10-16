/**
 * @file robot.h
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam (aswath@umd.edu)
 * @brief The header file for coordinate system used in the project
 * @version 0.1
 * @date 2021-10-04
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ROBOT_H_  // NOLINT
#define ROBOT_H_

#include <state.h>

class Robot : public State{  // Robot inherits State class public members
 public:
    /**
    * @brief Construct a new robot object. Sets default values to all attributes
    */
        Robot();

    /**
    * @brief Method will set the environment variables
    * @return bool flag indicating successful operation
    */
    bool Initialize();

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
};








#endif  // ROBOT_H_  // NOLINT