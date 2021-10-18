/**
 * @file solver.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam (aswath@umd.edu)
 * @brief File for arm manipulator path planning solver definitions
 * @version 0.1
 * @date 2021-10-05
 * @copyright All rights reserved 
 * 
 */


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
    return (error_tolerance <= _error);
}
