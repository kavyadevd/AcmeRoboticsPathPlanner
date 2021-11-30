/**
 * @file gmocktest.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu)
 * @brief A program for Gmock test implementation
 * @version 0.1
 * @date 2021-11-29
 * @copyright MIT
 *
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include "gmocktest.hpp"
#include "arm.hpp"

using ::testing::_;

TEST(TestArmStub, test_get_client_id) {
    Arm arm_(1);
    EXPECT_NE(arm_.GetClientID(), -1);
}

