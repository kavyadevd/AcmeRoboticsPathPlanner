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

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using namespace Eigen;

Robot::Robot() {}

bool Robot::Initialize(Simulator* simulator) {
  try {
    this->simulator = simulator;

    ///< Variable to store origin
    char origin_name[] = "Floor";

    ///< Variable to store robot joint names
    std::vector<char*> joint_names = {"UR5_joint1", "UR5_joint2", "UR5_joint3",
                                      "UR5_joint4", "UR5_joint5", "UR5_joint6"};

    ///< Variable to store robot link names
    std::vector<char*> link_names = {"UR5_link1", "UR5_link2", "UR5_link3",
                                     "UR5_link4", "UR5_link5", "UR5_link6"};

    ///< Assign IDs values to handles
    origin_handle = simulator->GetObjectHandle(origin_name);

    for (int it = 0; it < 6; it++) {
      joint_handle.push_back(simulator->GetObjectHandle(joint_names[it]));
      link_handle.push_back(simulator->GetObjectHandle(link_names[it]));

      cout << "\n------Joint matrix " << it << " --------\n";
      float* joint_ptr = new float[12];
      joint_matrix.push_back(joint_ptr);
      simulator->GetJointMatrix(joint_handle[it], joint_matrix[it]);

      // cout << "\n------Link matrix " << it << " --------\n";
      // float* link_ptr = new float[12];
      // link_matrix.push_back(link_ptr);
      // simulator->GetJointMatrix(link_handle[it], link_matrix[it]);
    }

    //< Perform some actions by commanding joint angles(in radians).
    ForwardKinematics(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

    //< Get positions of objects(joints in this case).
    simxFloat position[3];
    simxFloat orientation[3];

    for (int it = 0; it < 6; it++) {
      cout << "\n------Joint position of " << it
           << " [x, y, x] wrt to Origin --------\n";
      simulator->GetObjectPosition(joint_handle[it], origin_handle, position);
      simulator->GetObjectOrientation(joint_handle[it], origin_handle, orientation);

    }

    for (int it = 1; it < 6; it++) {
      cout << "\n------Joint position and orientation of " << it
           << " [x, y, x] wrt to previous joints --------\n";
      simulator->GetObjectPosition(joint_handle[it], joint_handle[it-1], position);
      simulator->GetObjectOrientation(joint_handle[it], joint_handle[it-1], orientation);

    }
    //< Set a Joint Position. 
    // simulator->SetJointPosition(joint_handle[0], position);
    // cout << position[0];
    return true;
  } catch (const char* msg) { /* catch exception if any */
    std::cout << "Exception occurred" << std::endl;
  }
}

void Robot::ForwardKinematics(float t1, float t2, float t3, float t4, float t5,
                              float t6) {
  cout << "Starting Froward Kinematics " << endl;
  simulator->SetJointTargetAngle(joint_handle[1], t1);
  simulator->SetJointTargetAngle(joint_handle[1], t2);
  simulator->SetJointTargetAngle(joint_handle[2], t3);
  simulator->SetJointTargetAngle(joint_handle[3], t4);
  simulator->SetJointTargetAngle(joint_handle[4], t5);
  simulator->SetJointTargetAngle(joint_handle[5], t6);

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
  /// Set transformations matrix
  Matrix4f transformation;
  int i = 0;
  // for(int i = 0; i < 5; i++){
  transformation << cos(t[i]), sin(t[i]), 0, a[i], sin(t[i]), cos(t[i]), 0, 0,
      0, 0, 1, d[i], 0, 0, 0, 1;
  //}

  cout << "Transformation matrix: " << endl;
  Matrix4f tr = transformation;
  cout << tr(0, 1) << "  " << tr(0, 2);

  Matrix4f tf06;

  VectorXf v(3);
  // v << tf06(0,3) , tf06(1,3) , tf06(2,3) ;
  // return v;
}

bool Robot::Solver() { return true; }

bool Robot::TrajectoryPlanner() { return true; }

bool Robot::Controller() { return true; }

bool Robot::Simulate() { return true; }
