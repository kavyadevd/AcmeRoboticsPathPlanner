/**
 * @file state.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam (aswath@umd.edu)
 * @brief File for arm manipulator state definitions
 * @version 0.1
 * @date 2021-10-05
 * @copyright All rights reserved 
 * 
 */


#include "state.h"     // NOLINT

State::State() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
    theta = 0.0;
    phi = 0.0;
    alpha = 0.0;
}
