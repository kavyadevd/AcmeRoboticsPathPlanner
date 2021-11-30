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
#include "arm.hpp"

// Simulator simulator;
Arm arm_(1);

/**
 * @brief Tests simulator class
 */
TEST(TestArmStub, test_get_client_id) {
  EXPECT_NE(arm_.GetClientID(), -1);
}
