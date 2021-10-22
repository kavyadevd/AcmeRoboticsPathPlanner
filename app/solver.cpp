/**
 * @file solver.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam (aswath@umd.edu)
 * @brief File for arm manipulator path planning solver definitions
 * @version 0.1
 * @date 2021-10-05
 * @copyright All rights reserved 
 * 
 */


#include<math.h>
#include "solver.h"     // NOLINT

Solver::Solver() {
    error_tolerance = 0.5;
}

int Solver::PerformIK() {
    return 0;
}

bool Solver::SetErrorTolerance(double _error) {
    error_tolerance = _error;
    return true;
}

double Solver::GetErrorTolerance() {
    return error_tolerance;
}

bool Solver::IsErrorTolerable(double _error) {
    return (error_tolerance >= _error);
}

/**
 * @brief Fetch angle for wrist frame in relation to the base frame
 * θ1 = atan2(0T5y,0T5x)+- acos[ d4 / (√ 0T5x^2  + 0T5y^2) ]
 * 
 * @return double 
 */
double GetTheta_1() {
    return 0.0;
}

/**
 * @brief Fetch angle for link 5 
 * θ5 = acos [ (0T6x sinθ1 - 0T6y cosθ1 - d4) / d6 ]
 * 
 * @return double 
 */
double GetTheta_5() {
    return 0.0;
}