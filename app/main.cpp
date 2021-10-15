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

#include <simulator.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Simulator simulator;
  if (simulator.Initialize()) {
    cout << " Connection status to VREP: SUCCESS" << endl;
    simulator.Stop();
  }

  return true;
}
