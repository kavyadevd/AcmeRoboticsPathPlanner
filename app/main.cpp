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
#include <iostream>
#include "simulator.h"
#include "robot.h"

using std::cout;
using std::endl;

int main() {
  Simulator simulator;
  Robot robot;
  if (simulator.Initialize()) {
    cout << " Connection status to VREP: SUCCESS" << endl;
  }

  robot.Initialize();

  char name[10] = "UR5";
  simxInt parent = simulator.GetObjectHandle(name);
  cout << "Parent: " << parent << endl;
  simxInt child = parent;
  for (simxInt index = 0; index < 2; index++) {
    child = simulator.GetChild(parent, index);
    cout << "Child: " << child << endl;
  }

  return true;
}
