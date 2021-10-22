/**
 * @file solver.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam (aswath@umd.edu)
 * @brief File for arm manipulator path planning solver definitions
 * 
 * Note: Transformation matrix notations are as follows:
 *  0                               |06R    0P6|
 *      T(θ1,θ2,θ3,θ4,θ5,θ6) =      |          |
 *  6                               |0      1  |
 * 
 *                                  |0X6x   0Y6x     0Z6x    0P6x|
 *                                  |0X6y   0Y6y     0Z6y    0P6y|
 *                            =     |0X6z   0Y6z     0Z6z    0P6z|
 *                                  |  0     0        0        0 |
 * 
 * 
 * 
 * 
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
 * θ1 = atan2(0P5y,0P5x)+- acos[ d4 / (√ 0P5x^2  + 0P5y^2) ]
 * 
 * @return double 
 */
double GetTheta_1() {
    return 0.0;
}

/**
 * @brief Fetch angle for link 5 
 * θ5 = acos [ (0P6x sinθ1 - 0P6y cosθ1 - d4) / d6 ]
 * 
 * @return double 
 */
double GetTheta_5() {
    return 0.0;
}
