/**
 * @file test.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam
 *(aswath@umd.edu)
 * @brief File for running gtests
 * @version 0.1
 * @date 2021-10-05
 * @copyright All rights reserved
 *
 **/

#include <gtest/gtest.h>

#include "robot.h"      // NOLINT
#include "simulator.h"  // NOLINT
#include "solver.h"     // NOLINT
#include "state.h"      // NOLINT

Simulator simulator;

/**
 * @brief Tests simulator class
 */
TEST(TestSimulatorStub, test_simulator) {
  EXPECT_EQ(simulator.Initialize(), 1);
  EXPECT_NE(simulator.GetClientID(), -1);
  char joint[] = "UR5_joint1";
  simxInt handle = simulator.GetObjectHandle(joint);
  EXPECT_NE(simulator.GetParent(handle), -1);
  EXPECT_NE(simulator.GetChild(handle, 0), -1);
}

/**
 * @brief Tests Robot class
 */
TEST(TestSimulatorStub, test_robot) {
  Robot robotic_arm(&simulator);
  EXPECT_EQ(robotic_arm.Solve(0.1, 0.1, 0.3), true);
}
