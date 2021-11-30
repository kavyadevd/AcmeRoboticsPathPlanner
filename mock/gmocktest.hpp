/**
 * @file gmocktest.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu)
 * @brief A program for Gmock test class
 * @version 0.1
 * @date 2021-11-29
 * @copyright MIT
 *
 */

#ifndef MOCK_GMOCKTEST_HPP_  // NOLINT
#define MOCK_GMOCKTEST_HPP_

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include "arm.hpp"

class MockArm:public Arm {
   public:  // NOLINT
    MOCK_METHOD();
};

#endif  // MOCK_GMOCKTEST_HPP_
