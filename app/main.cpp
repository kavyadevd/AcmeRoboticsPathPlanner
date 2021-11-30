/**
 * @file main.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu) - Driver, Aswath Muthuselvam
 * (aswath@umd.edu) - Navigator
 * @brief A program for arm manipulator path planning
 * @version 0.1
 * @date 2021-10-05
 * @copyright All rights reserved
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>

#include "robot.h"      // NOLINT
#include "simulator.h"  // NOLINT
#include "solver.h"     // NOLINT
#include "arm.hpp"

using std::cout;
using std::endl;

int main() {
  Arm* arm_ = new Arm(1);
  int arm_client = arm_->GetClientID();
  // Simulator simulator;
  // if (!simulator.Initialize()) {
  //   return -1;
  // }
  // Robot robot(&simulator);
  // robot.Initialize();
  // std::cout
  //     << "\n\nEnter goal x, y, z co-ordinates\n(in meters, values within -1m "
  //        "and 1m in all axes):\n ";
  // double goal_x, goal_y, goal_z;
  // std::cin >> goal_x >> goal_y >> goal_z;
  // robot.Solve(goal_x, goal_y, goal_z);
  return 0;
}
