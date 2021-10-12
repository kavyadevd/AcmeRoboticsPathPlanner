/**
 * @file main.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu) - Driver, Aswath Muthuselvam (aswath@umd.edu) - Navigator
 * @brief A program for arm manipulator path planning
 * @version 0.1
 * @date 2021-10-05
 * @copyright All rights reserved 
 * 
 */


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <solver.h>
#include <robot.h>


//#define NON_MATLAB_PARSING
//#define MAX_EXT_API_CONNECTIONS 255
//#define DO_NOT_USE_SHARED_MEMORY

extern "C" {
#include "extApi.h"
}

using namespace std;
#define PI 3.14
int main()
{

    bool VERBOSE = true;
    int clientID = 0;
    int leftmotorHandle = 0;
    int rightmotorHandle = 0;
    
    int lbrJoint1 = 0;
    int lbrJoint2 = 0;
    int lbrJoint3 = 0;
    int lbrJoint4 = 0;
    int lbrJoint5 = 0;
    int lbrJoint6 = 0;
    int lbrJoint7 = 0;

    int counter = 0;

    //! Todo Naresh: check to run this in parallel with real robot driver. May need to integrate my planner
    bool WORK = true;
    simxFinish(-1);                                                     //! Close any previously unfinished business
    clientID = simxStart((simxChar*)"127.0.0.1", 19997, true, true, 5000, 5);  //!< Main connection to V-REP
    sleep(1);
    if (clientID != -1)
    {
        cout << " Connection status to VREP: SUCCESS" << endl;
        simxInt syncho = simxSynchronous(clientID, 1);
        int start = simxStartSimulation(clientID, 1);
        int TEST1 = simxGetObjectHandle(clientID, "Pioneer_p3dx_leftMotor", &leftmotorHandle, simx_opmode_oneshot_wait);
        int TEST2 = simxGetObjectHandle(clientID, "Pioneer_p3dx_rightMotor", &rightmotorHandle, simx_opmode_oneshot_wait);

        simxGetObjectHandle(clientID, "LBR_iiwa_14_R820_joint1", &lbrJoint1, simx_opmode_oneshot_wait);
        simxGetObjectHandle(clientID, "LBR_iiwa_14_R820_joint2", &lbrJoint2, simx_opmode_oneshot_wait);
        simxGetObjectHandle(clientID, "LBR_iiwa_14_R820_joint3", &lbrJoint3, simx_opmode_oneshot_wait);
        simxGetObjectHandle(clientID, "LBR_iiwa_14_R820_joint4", &lbrJoint4, simx_opmode_oneshot_wait);
        simxGetObjectHandle(clientID, "LBR_iiwa_14_R820_joint5", &lbrJoint5, simx_opmode_oneshot_wait);
        simxGetObjectHandle(clientID, "LBR_iiwa_14_R820_joint6", &lbrJoint6, simx_opmode_oneshot_wait);
        simxGetObjectHandle(clientID, "LBR_iiwa_14_R820_joint7", &lbrJoint7, simx_opmode_oneshot_wait);

        if (VERBOSE)
        {
            cout << "Computed object handle: " << TEST1 << "  " << leftmotorHandle << endl;
            cout << "Computed object handle: " << TEST2 << "  " << rightmotorHandle << endl;
        }

        //        simxPauseCommunication(clientID,true);
        simxSetJointTargetPosition(clientID, lbrJoint1, 0.0, simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, lbrJoint2, 0.0, simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, lbrJoint3, 0.0, simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, lbrJoint4, 0.0, simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, lbrJoint5, 0.0, simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, lbrJoint6, 0.0, simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, lbrJoint7, 0.0, simx_opmode_oneshot_wait);
        //        simxPauseCommunication(clientID,false);

        cout << "At Second Block..." << endl;

        //        simxPauseCommunication(clientID,1);
        simxSetJointTargetPosition(clientID, lbrJoint1, 90.0* (PI / 180), simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, lbrJoint2, 90.0* (PI / 180), simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, lbrJoint3, 170.0* (PI / 180), simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, lbrJoint4, -90.0* (PI / 180), simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, lbrJoint5, 90.0* (PI / 180), simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, lbrJoint6, 90.0* (PI / 180), simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, lbrJoint7, 0.0* (PI / 180), simx_opmode_oneshot_wait);
    }
    else
    {
        cout << " Connection status to VREP: FAILED" << endl;
    }
    simxFinish(clientID);
    
    return clientID;
}