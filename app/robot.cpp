/**
 * @file robot.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam
 * (aswath@umd.edu)
 * @brief File for robot class method definitions
 * @version 0.1
 * @date 2021-10-05
 * @copyright All rights reserved
 *
 */

#include "robot.h"  // NOLINT

#include <unistd.h>
#include <Eigen/Dense>
#include <cmath>


#include <iostream>
#include <vector>

#include "simulator.h"  // NOLINT

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using namespace Eigen;

Robot::Robot() {}

bool Robot::Initialize(Simulator* simulator) {
  try {
  ///< Variable to store robot joint names
  std::vector<char*> joint = {"UR5_joint1", "UR5_joint2", "UR5_joint3", "UR5_joint4", "UR5_joint5", "UR5_joint6"};

  ///< Variable to store robot link names
  std::vector<char*> link = {"UR5_link1", "UR5_link2", "UR5_link3", "UR5_link4", "UR5_link5", "UR5_link6"};

  for (int it = 0; it < 6; it++) {
    joint_handle[it] = simulator->GetObjectHandle(joint[it]);
    link_handle[it] = simulator->GetObjectHandle(link[it]);

    cout << "\n------Joint matrix " << it << " --------\n";
    simulator->GetJointMatrix(joint_handle[it], joint_matrix[it+1]);

    cout << "\n------Link matrix " << it << " --------\n";
    simulator->GetJointMatrix(link_handle[it], joint_matrix[it+1]);
  }

  cout << "Starting Froward Kinematics Demo" << endl;
  simxSetJointTargetPosition(simulator->GetClientID(), joint_handle[0], 0.0,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), joint_handle[0], 18.13,
                             simx_opmode_blocking);
  sleep(1);
  simxSetJointTargetPosition(simulator->GetClientID(), joint_handle[1], 0.6,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), joint_handle[2], 0.6,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), joint_handle[3], 0.6,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), joint_handle[4], 1.2,
                             simx_opmode_blocking);
  simxSetJointTargetPosition(simulator->GetClientID(), joint_handle[5], 1.2,
                             simx_opmode_blocking);
    for (int it = 0; it < 6; it++) {
    cout << "\n------Joint matrix " << it << " --------\n";
    simulator->GetJointMatrix(joint_handle[it], joint_matrix[it+1]);

    cout << "\n------Link matrix " << it << " --------\n";
    simulator->GetJointMatrix(link_handle[it], joint_matrix[it+1]);
  }

  sleep(1);
  simulator->GetJointMatrix(joint_handle[0], joint_matrix[0]);
  simulator->SetJointPosition(joint_handle[0], pos);
  cout << pos[0];
  return true;
} catch (const char *msg) { /* catch exception if any */
  std::cout << "Exception occurred" << std::endl;
}
}

void Robot::ForwardKinematics(float t1, float t2, float t3, float t4, float t5,
                              float t6) {
  cout << "Starting Froward Kinematics" << endl;
  simulator->SetJointTargetAngle(j1, t1);
  simulator->SetJointTargetAngle(j2, t2);
  simulator->SetJointTargetAngle(j3, t3);
  simulator->SetJointTargetAngle(j4, t4);
  simulator->SetJointTargetAngle(j5, t5);
  simulator->SetJointTargetAngle(j6, t6);

  //------------1 to 2------------//
  

}

VectorXf Robot::GetEndEffectorPosition() {
  cout << "Starting Froward Kinematics" << endl;
  
  vector<double> a;
  vector<double> d;
  vector<double> al;
  vector<double> t;
  a.push_back(0.2);
  d.push_back(0.3);
  t.push_back(0.6);
  ///Set transformations matrix
  Matrix4f transformation;
  int i=0;
  //for(int i = 0; i < 5; i++){
    transformation << cos(t[i]) , sin(t[i]) , 0 , a[i] ,
    sin(t[i]) , cos(t[i]) , 0 , 0,
    0 , 0 , 1 , d[i],
    0 , 0 , 0 , 1 ;
  //}

  cout<<"Transformation matrix: "<<endl;
    Matrix4f tr = transformation;
    cout<< tr(0,1)<< "  "<< tr(0,2);
  
  Matrix4f tf06;

  VectorXf v(3);
  //v << tf06(0,3) , tf06(1,3) , tf06(2,3) ;
  //return v;
}

bool Robot::Solver() { return true; }

bool Robot::TrajectoryPlanner() { return true; }

bool Robot::Controller() { return true; }

bool Robot::Simulate() { return true; }
