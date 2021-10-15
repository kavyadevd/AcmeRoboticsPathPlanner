/**
 * @file simulator.h
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam (aswath@umd.edu)
 * @brief The header file for arm manipulator path simulation
 * @version 0.1
 * @date 2021-09-30
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SIMULATOR_H_  // NOLINT
#define SIMULATOR_H_

class Simulator{
 public:
    bool Initialize();
 private:
    int client_ID;
};

#endif  // SIMULATOR_H  // NOLINT
