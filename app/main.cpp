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
#include "robot.h"        // NOLINT
#include "simulator.h"  // NOLINT
#include "solver.h"  // NOLINT

using std::cout;
using std::endl;

int main() {
  try {
  Solver solve_ik;
  Simulator simulator;
  Robot robot;
  if (!simulator.Initialize()) {
        std::cout << "Exception occurred Initialize failed" << std::endl;
    return -1;
  }
  sleep(3);
  int client_ID = simulator.GetClientID();
  std::cout << client_ID << std::endl;
  solve_ik.PerformIK(client_ID);
  return 0;
  } catch (const char* msg) { /* catch exception if any */
        std::cout << "Exception occurred" << std::endl;
        return 0;
  }
}
