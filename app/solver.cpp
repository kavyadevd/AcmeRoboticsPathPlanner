/**
 * @file solver.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam (aswath@umd.edu)
 * @brief File for arm manipulator path planning solver definitions
 * 
 * @version 0.1
 * @date 2021-10-05
 * @copyright  All rights reserved
 * Note: Transformation matrix notations are as follows:
 *  0                               |06R    0P6|
 *      T(θ1, θ2, θ3, θ4, θ5, θ6) =      |          |
 *  6                               |0      1  |
 * 
 *                                  |0X6x   0Y6x     0Z6x    0P6x|
 *                                  |0X6y   0Y6y     0Z6y    0P6y|
 *                            =     |0X6z   0Y6z     0Z6z    0P6z|
 *                                  |  0     0        0        0 |
 * 
 */

#include<math.h>
#include<iostream>
#include "ik.h"    // NOLINT
#include "environment.h"    // NOLINT
#include "solver.h"     // NOLINT

extern "C" {
    #include "extApi.h"
}

Solver::Solver() {
    error_tolerance = 0.5;
}

int Solver::PerformIK(int client_ID, double goal_x, double goal_y, double goal_z) {
    try {
    std::cout<< "created env start ";
    // Create an environment for IK solver
    ikCreateEnvironment();
    std::cout<< "created env end";

    int arm_handles[7];
    simReal sim_math_real = 0.0;
    C7Vector initial_transf;
    float simulationStep;

    ikGetObjectHandle("UR5_joint1", arm_handles+0);
    ikGetObjectHandle("UR5_joint2", arm_handles+1);
    ikGetObjectHandle("UR5_joint3", arm_handles+2);
    ikGetObjectHandle("UR5_joint4", arm_handles+3);
    ikGetObjectHandle("UR5_joint5", arm_handles+4);
    ikGetObjectHandle("UR5_joint6", arm_handles+5);
    int target_robot_handle;
    ikGetObjectHandle("UR5_joint6", &target_robot_handle);
    int base_robot_handle;
    ikGetObjectHandle("UR5_joint5", &base_robot_handle);

    ikGetObjectTransformation(target_robot_handle, base_robot_handle, &initial_transf);

    C7Vector tr(C4Vector(0, 0, 0), C3Vector::zeroVector);
    tr.X = C3Vector(goal_x, goal_y, goal_z);
    // Slow down the simulation
    simxUChar simWaitingForTrigger = 0;
    while ( (simWaitingForTrigger == 0) )
        simxGetBooleanParameter(client_ID, sim_boolparam_waiting_for_trigger,
        &simWaitingForTrigger, simx_opmode_blocking);

    simxGetFloatingParameter(client_ID, sim_floatparam_simulation_time_step,
    &simulationStep, simx_opmode_buffer);
    sim_math_real += simReal(0.6)*simReal(simulationStep);

    initial_transf.X = C3Vector(simReal(-0.3-cos(sim_math_real)*0.1),
     simReal(sin(sim_math_real)*0.1), simReal(0.629+sin(sim_math_real*9)*0.01));
    ikSetObjectTransformation(target_robot_handle, base_robot_handle, &initial_transf);

    ikHandleIkGroup(ik_handle_all);     // API call for IK solver

    simxPauseCommunication(client_ID, 1);

    simReal pos;
    ikGetJointPosition(arm_handles[0], &pos);

    int r = simx_return_remote_error_flag;  // Variable to store error flag
    while (r == simx_return_remote_error_flag)
        r = simxSynchronousTrigger(client_ID);  // Trigger next simulation step

    ikEraseEnvironment();
    ikEraseEnvironment();
    return 0;
    } catch (const char* msg) { /* catch exception if any */
        std::cout << "Exception occurred" << std::endl;
        return 0;
  }
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
 * @brief Get the Transformation Matrix
 * 
 */
void GetTransformationMatrix() {
    // TODO(aswath)
}


/**
 * @brief Fetch angle for wrist frame in relation to the base frame
 * 0P5 = 0      | 0 |
 *         T *  | 0 |
 *       6      |-d6|
 *              | 1 |
 * 
 * θ1 = atan2(0P5y, 0P5x)+- acos[ d4 / (√ 0P5x^2  + 0P5y^2) ]
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
