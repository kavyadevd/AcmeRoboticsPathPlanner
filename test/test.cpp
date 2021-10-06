/**
 * @file test.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam (aswath@umd.edu)
 * @brief File for running gtests
 * @version 0.1
 * @date 2021-10-05
 * @copyright All rights reserved 
 * 
 **/

#include <gtest/gtest.h>
#include "solver.h"  // NOLINT

/**
 * @brief Tests the default constructor
*/
TEST(Test_Driven_PID, test_the_default_constructor) {
  Solver ik_solver;
  EXPECT_EQ(0, 0);
}

/**
 * @brief Tests IK solver stub
*/
TEST(TestStud, should_pass_solver) {
  Solver ik_solver;
  EXPECT_EQ(ik_solver.solve(), 0);
}
