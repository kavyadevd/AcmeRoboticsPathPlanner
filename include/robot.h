/**
 * @file robot.h
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam (aswath@umd.edu)
 * @brief The header file for coordinate system used in the project
 * @version 0.1
 * @date 2021-10-04
 * @copyright Copyright (c) 2021
 * 
 */

#include "state.h"  //NOLINT

#ifndef ROBOT_H_  // NOLINT
#define ROBOT_H_

class Robot : public State{  // Robot inherits State class public members
 public:
/**
* @brief Construct a new robot object. Sets default values to all attributes
*/
    Robot();
};


#endif  // ROBOT_H_  // NOLINT