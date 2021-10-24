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
  this->simulator = simulator;

  char name_floor[] = "Floor";
  char name_joint1[] = "UR5_joint1";
  char name_joint2[] = "UR5_joint2";
  char name_joint3[] = "UR5_joint3";
  char name_joint4[] = "UR5_joint4";
  char name_joint5[] = "UR5_joint5";
  char name_joint6[] = "UR5_joint6";

  char name_link1[] = "UR5_link1";
  char name_link2[] = "UR5_link2";
  char name_link3[] = "UR5_link3";
  char name_link4[] = "UR5_link4";
  char name_link5[] = "UR5_link5";
  char name_link6[] = "UR5_link6";

  simxInt floorh = simulator->GetObjectHandle(name_floor);
  j1 = simulator->GetObjectHandle(name_joint1);
  j2 = simulator->GetObjectHandle(name_joint2);
  j3 = simulator->GetObjectHandle(name_joint3);
  j4 = simulator->GetObjectHandle(name_joint4);
  j5 = simulator->GetObjectHandle(name_joint5);
  j6 = simulator->GetObjectHandle(name_joint6);

  simxInt l1 = simulator->GetObjectHandle(name_link1);
  simxInt l2 = simulator->GetObjectHandle(name_link2);
  simxInt l3 = simulator->GetObjectHandle(name_link3);
  simxInt l4 = simulator->GetObjectHandle(name_link4);
  simxInt l5 = simulator->GetObjectHandle(name_link5);
  simxInt l6 = simulator->GetObjectHandle(name_link6);

  // Get joint Matrix
  float T00[12];
  float T01[12];
  float T02[12];
  float T03[12];
  float T04[12];
  float T05[12];
  float T06[12];

  simxFloat pos[3];

  //GetEndEffectorPosition();
  simulator->GetObjectPosition(j1, j1, pos);
   cout << "\nPosition of 1 wrt to 1:\n"
       << pos[0] << " " << pos[1] << " " << pos[2]<<endl;
  simulator->GetObjectPosition(j2, j1, pos);
   cout << "\nPosition of 2 wrt to 1:\n"
       << pos[0] << " " << pos[1] << " " << pos[2]<<endl;
  simulator->GetObjectPosition(j3, j1, pos);
   cout << "\nPosition of 3 wrt to 1:\n"
       << pos[0] << " " << pos[1] << " " << pos[2]<<endl;
  simulator->GetObjectPosition(j4, j1, pos);
   cout << "\nPosition of 4 wrt to 1:\n"
       << pos[0] << " " << pos[1] << " " << pos[2]<<endl;
  simulator->GetObjectPosition(j5, j1, pos);
   cout << "\nPosition of 5 wrt to 1:\n"
       << pos[0] << " " << pos[1] << " " << pos[2]<<endl;
  simulator->GetObjectPosition(j6, j1, pos);
   cout << "\nPosition of 6 wrt to 1:\n"
       << pos[0] << " " << pos[1] << " " << pos[2]<<endl;
  int k;
  cin>>k;

/*
  cout << "\n------Joint matrix--------";
  simulator->GetJointMatrix(j1, T01);
  simulator->GetJointMatrix(j2, T02);
  simulator->GetJointMatrix(j3, T03);
  simulator->GetJointMatrix(j4, T04);
  simulator->GetJointMatrix(j5, T05);
  simulator->GetJointMatrix(j6, T06);

  cout << "\n------Link matrix--------";
  simulator->GetJointMatrix(l1, T01);
  simulator->GetJointMatrix(l2, T02);
  simulator->GetJointMatrix(l3, T03);
  simulator->GetJointMatrix(l4, T04);
  simulator->GetJointMatrix(l5, T05);
  simulator->GetJointMatrix(l6, T06);

  //ForwardKinematics(1, 0, 0, 0, 0, 0);

  cout << "\n------Joint matrix--------" << endl;
  simulator->GetJointMatrix(j1, T01);
  simulator->GetJointMatrix(j2, T02);
  simulator->GetJointMatrix(j3, T03);
  simulator->GetJointMatrix(j4, T04);
  simulator->GetJointMatrix(j5, T05);
  simulator->GetJointMatrix(j6, T06);

  cout << "\n------Link matrix--------" << endl;
  simulator->GetJointMatrix(l1, T01);
  simulator->GetJointMatrix(l2, T02);
  simulator->GetJointMatrix(l3, T03);
  simulator->GetJointMatrix(l4, T04);
  simulator->GetJointMatrix(l5, T05);
  simulator->GetJointMatrix(l6, T06);
*/
  //&pos = 1;
  //simulator->SetJointPosition(j1, pos);
  //cout << pos[0];

  simulator->SetJointTargetAngle(j1, 0.3);
  simulator->SetJointTargetAngle(j2, 0.3);
  simulator->SetJointTargetAngle(j3, 0.3);

  sleep(1);

  //GetEndEffectorPosition();
  simulator->GetObjectPosition(j1, j1, pos);
   cout << "\nPosition of 1 wrt to 1:\n"
       << pos[0] << " " << pos[1] << " " << pos[2]<<endl;
  simulator->GetObjectPosition(j2, j1, pos);
   cout << "\nPosition of 2 wrt to 1:\n"
       << pos[0] << " " << pos[1] << " " << pos[2]<<endl;
  simulator->GetObjectPosition(j3, j1, pos);
   cout << "\nPosition of 3 wrt to 1:\n"
       << pos[0] << " " << pos[1] << " " << pos[2]<<endl;
  simulator->GetObjectPosition(j4, j1, pos);
   cout << "\nPosition of 4 wrt to 1:\n"
       << pos[0] << " " << pos[1] << " " << pos[2]<<endl;
  simulator->GetObjectPosition(j5, j1, pos);
   cout << "\nPosition of 5 wrt to 1:\n"
       << pos[0] << " " << pos[1] << " " << pos[2]<<endl;
  simulator->GetObjectPosition(j6, j1, pos);
   cout << "\nPosition of 6 wrt to 1:\n"
       << pos[0] << " " << pos[1] << " " << pos[2]<<endl;
  cin>>k;

  return true;
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
