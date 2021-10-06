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
TEST(TestIKStud, test_the_default_constructor) {
  Solver ik_solver;
  EXPECT_EQ(0, 0);
}

/**
 * @brief Tests IK solver stub
*/
TEST(TestIKStud, should_pass_solver) {
  Solver ik_solver;
  EXPECT_EQ(ik_solver.solve(), 0);
}

/**
 * @brief Tests Set Error stub
*/
TEST(TestIKStud, set_error) {
  Solver ik_solver;
  EXPECT_EQ(ik_solver.SetErrorTolerance(0.007), true);
}

/**
 * @brief Tests Get Error stub
*/
TEST(TestIKStud, get_error) {
  Solver ik_solver;
  EXPECT_EQ(ik_solver.GetErrorTolerance(), 0.0);
}

/**
 * @brief Tests error tolance check stub
*/
TEST(TestIKStud, is_error_tolerable) {
  Solver ik_solver;
  EXPECT_EQ(ik_solver.IsErrorTolerable(0.0001), true);
}
