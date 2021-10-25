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
Robot robotic_arm;


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
 * @brief Tests robot initialize method
 */
TEST(TestIKStub, test_robot_initialize) {
  EXPECT_EQ(robotic_arm.Initialize(&simulator), true);
}

