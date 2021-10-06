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

TEST(TestStud, should_pass_solver) {
  Solver ik_solver;
  EXPECT_EQ(ik_solver.solve(), 1);
}
