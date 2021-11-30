/**
 * @file arm.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu)
 * @brief File for robot arm class method definitions
 * @version 0.1
 * @date 2021-10-05
 * @copyright MIT
 *
 */


#ifndef ARM_HPP_  // NOLINT
#define ARM_HPP_


#include <iostream>
#include "./include/simulator.h"

class Arm : public Simulator {
 public:
    explicit Arm(int client_id);
    ~Arm();
    int GetClientID();
 private:
    int client_id;
};


#endif  // INCLUDE_ARM_HPP_
