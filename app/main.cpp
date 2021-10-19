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

#include "robot.h"
#include "simulator.h"

using std::cout;
using std::endl;

int main() {
  Simulator simulator;
  Robot robot;
  if (!simulator.Initialize()) {
    return -1;
  }
  robot.Initialize(&simulator);
  return 0;
}
