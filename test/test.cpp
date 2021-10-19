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
#include "state.h"  // NOLINT
#include "robot.h"  // NOLINT
#include "simulator.h"  // NOLINT

/**
 * @brief Tests the default constructor
*/
TEST(TestIKStub, test_the_default_constructor) {
  Solver ik_solver;
  EXPECT_EQ(0, 0);
}

/**
 * @brief Tests IK solver stub
*/
TEST(TestIKStub, should_pass_solver) {
  Solver ik_solver;
  EXPECT_EQ(ik_solver.PerformIK(), 0);
}

/**
 * @brief Tests Set Error stub
*/
TEST(TestIKStub, set_error) {
  Solver ik_solver;
  EXPECT_EQ(ik_solver.SetErrorTolerance(0.007), true);
}

/**
 * @brief Tests Get Error stub
*/
TEST(TestIKStub, get_error) {
  Solver ik_solver;
  EXPECT_EQ(ik_solver.GetErrorTolerance(), 0.5);
}

/**
 * @brief Tests error tolance check stub
*/
TEST(TestIKStub, is_error_tolerable) {
  Solver ik_solver;
  EXPECT_EQ(ik_solver.IsErrorTolerable(0.0001), true);
}


/**
 * @brief Tests State default constructor check stub
*/
TEST(TestIKStub, test_state_object) {
  State state_;
  EXPECT_EQ(0, 0);
}

/**
 * @brief Tests robot default constructor
*/
TEST(TestIKStub, test_robot_object) {
  Robot robotic_arm;
  EXPECT_EQ(true, true);
}

/**
 * @brief Tests robot initialize method
*/
TEST(TestIKStub, test_robot_initialize) {
  Robot robotic_arm;
  EXPECT_EQ(robotic_arm.Initialize(), true);
}

/**
 * @brief Tests robot solve method
*/
TEST(TestIKStub, test_solver) {
  Robot robotic_arm;
  EXPECT_EQ(robotic_arm.Solver(), true);
}

/**
 * @brief Tests robot Trajectory planner
*/
TEST(TestIKStub, test_trajectory_planner) {
  Robot robotic_arm;
  EXPECT_EQ(robotic_arm.TrajectoryPlanner(), true);
}

/**
 * @brief Tests robot controller method
*/
TEST(TestIKStub, test_controller) {
  Robot robotic_arm;
  EXPECT_EQ(robotic_arm.Controller(), true);
}

/**
 * @brief Tests robot simulate method
*/
TEST(TestIKStub, test_simulate) {
  Robot robotic_arm;
  EXPECT_EQ(robotic_arm.Simulate(), true);
}

/**
 * @brief Tests Coppeliasim connection
*/
TEST(TestIKStub, test_connection) {
  Simulator sim;
  EXPECT_EQ((sim.GetClientID() != -1), true);
}
