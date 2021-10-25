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
#include "solver.h"     //NOLINT

using Eigen::Matrix4d;
using Eigen::MatrixXd;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

Robot::Robot(Simulator* simulator) {

    this->simulator = simulator;
    ///< Variable to store origin
    char origin_name[] = "Floor";

    ///< Variable to store robot joint names
    char joint_names[6][11] = {"UR5_joint1", "UR5_joint2", "UR5_joint3",
                               "UR5_joint4", "UR5_joint5", "UR5_joint6"};

    ///< Variable to store robot link names
    char link_names[6][11] = {"UR5_link1", "UR5_link2", "UR5_link3",
                              "UR5_link4", "UR5_link5", "UR5_link6"};

    ///< Assign IDs values to handles
    origin_handle = simulator->GetObjectHandle(origin_name);

    for (int it = 0; it < 6; it++) {
      joint_handle.push_back(simulator->GetObjectHandle(joint_names[it]));
      link_handle.push_back(simulator->GetObjectHandle(link_names[it]));

      // cout << "\n------Joint matrix " << it + 1 << " --------\n";
      // float* joint_ptr = new float[12];
      // joint_matrix.push_back(joint_ptr);
      // simulator->GetJointMatrix(joint_handle[it], joint_matrix[it]);

      // cout << "\n------Link matrix " << it << " --------\n";
      // float* link_ptr = new float[12];
      // link_matrix.push_back(link_ptr);
      // simulator->GetJointMatrix(link_handle[it], link_matrix[it]);
    }

    this->solver = new Solver(simulator, joint_handle);
}

bool Robot::Initialize() {
  State state;
  try {

    float theta = 0.5;
    //< Perform some actions by commanding joint angles(in radians).
    Controller(theta, theta, theta, theta, theta, theta);

    sleep(1);

    Solve();

    //< Get positions of objects(joints in this case).
    simxFloat position[3];
    simxFloat orientation[3];
    simxFloat matrix[12];

    // ChainTransformations();

    for (int it = 0; it < 6; it++) {
      cout << "\n------Joint position of " << it + 1
           << " [x, y, x] wrt to Origin --------\n";
      simulator->GetObjectPosition(joint_handle[it], origin_handle, position);
      simulator->GetObjectOrientation(joint_handle[it], origin_handle,
                                      orientation);
    }

    cout << "\n---Joint position and orientation of 1"
         << "  wrt to "
         << " orgin is: "
         << "---\n";
    simulator->GetObjectPosition(joint_handle[0], origin_handle, position);
    simulator->GetObjectOrientation(joint_handle[0], origin_handle,
                                    orientation);
    for (int it = 1; it < 6; it++) {
      cout << "\n---Joint position and orientation of " << it + 1 << "  wrt to "
           << it << " th joint"
           << "---\n";
      simulator->GetObjectPosition(joint_handle[it], joint_handle[it - 1],
                                   position);
      simulator->GetObjectOrientation(joint_handle[it], joint_handle[it - 1],
                                      orientation);
    }

    //< Set a Joint Position.
    // simulator->SetJointPosition(joint_handle[0], position);
    // cout << position[0];
    return true;
  } catch (const char* msg) { /* catch exception if any */
    std::cout << "Exception occurred" << std::endl;
  }
}

void Robot::ChainTransformations() {
  cout << "\nTransfomation matrix chain from Origin to End Effector:" << endl;
  double t1, t2, t3, t4, t5, t6;
  double a1 = -0.0703083;
  double d1 = 0.0660392;
  double a2 = 0.425103;
  double d2 = 0;
  double a3 = 0.392149;
  double a4 = 0.0455737;
  double d4 = 0.0397052;
  double d5 = 0.0491754;
  double a5 = 0.0144247;

  t1 = simulator->GetJointAngle(joint_handle[0]);
  t2 = simulator->GetJointAngle(joint_handle[1]);
  t3 = simulator->GetJointAngle(joint_handle[2]);
  t4 = simulator->GetJointAngle(joint_handle[3]);
  t5 = simulator->GetJointAngle(joint_handle[4]);
  t6 = simulator->GetJointAngle(joint_handle[5]);

  // Vector3f ot; << 0.3, -0.275, 0.04315;
  Matrix4d T(4, 4);
  T << 1, 0, 0, 0.3, 0, 1, 0, -0.275, 0, 0, 1, 0.04315, 0, 0, 0, 1;  // j1

  Matrix4d Tn(4, 4);

  Tn << cos(t1), -sin(t1), 0, a1, sin(t1), cos(t1), 0, 1.2219E-06, 0, 0, 1, d1,
      0, 0, 0, 1;
  T = T * Tn;

  // T = T*[roty(-90) z'; z 1]*[rotz(-90) z'; z 1]; %j2
  /*
  Tn << 0, 0, -1, 0,
  -1, 0, 0, 0,
  0, 1, 0, 0,
  0, 0, 0, 1;
  */

  // T = T*[roty(-90) z'; z 1]
  Tn << 0, 0, -1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1;

  T = T * Tn;  // j2

  Tn << cos(t2), -sin(t2), 0, a2, sin(t2), cos(t2), 0, 1.74344e-05, 0, 0, 1,
      9.50694e-06, 0, 0, 0, 1;
  T = T * Tn;  // j3

  Tn << cos(t3), -sin(t3), 0, a3, sin(t3), cos(t3), 0, -1.60933e-06, 0, 0, 1,
      1.40071e-06, 0, 0, 0, 1;
  T = T * Tn;  // j4

  Tn << cos(t4), -sin(t4), 0, a4, sin(t4), cos(t4), 0, 2.95043e-06, 0, 0, 1, d4,
      0, 0, 0, 1;
  T = T * Tn;
  // T = T*[roty(90) [0 0 0]'; z 1]; %j5
  Tn << 0, 0, 1, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 1;
  T = T * Tn;

  // T = T*[Rz(t5) [a5 0 d5]'; z 1]; %j6
  Tn << cos(t5), -sin(t5), 0, a5, sin(t5), cos(t5), 0, 3.27826e-07, 0, 0, 1, d5,
      0, 0, 0, 1;
  T = T * Tn;
  // T = T*[roty(-90) [0 0 0]'; z 1];
  Tn << 0, 0, -1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1;
  T = T * Tn;

  GetEndEffectorPosition();
  float error = pow(pow(state.x - T(0, 3), 2) + pow(state.y - T(1, 3), 2) +
                        pow(state.z - T(2, 3), 2),
                    0.5);
  cout << "\nTransformation matrix is: \n" << T << endl;
  cout << " Error is: " << error;
}

void Robot::GetEndEffectorPosition() {
  simxFloat position[3];
  simulator->GetObjectPosition(joint_handle[5], origin_handle, position);
  state.x = position[0];
  state.y = position[1];
  state.z = position[2];
}

vector<double> Robot::TrajectoryPlanner(double goal_x, double goal_y,
                                        double goal_z) {
  GetEndEffectorPosition();
  std::vector<double> dx_dy_dz = {(state.x - goal_x) * 0.0001,
                                  (state.y - goal_y) * 0.0001,
                                  (state.z - goal_z) * 0.0001};
  return dx_dy_dz;
}

bool Robot::Controller(float t1, float t2, float t3, float t4, float t5,
                       float t6) {
  simulator->SetJointTargetAngle(joint_handle[0], t1);
  simulator->SetJointTargetAngle(joint_handle[1], t2);
  simulator->SetJointTargetAngle(joint_handle[2], t3);
  simulator->SetJointTargetAngle(joint_handle[3], t4);
  simulator->SetJointTargetAngle(joint_handle[4], t5);
  simulator->SetJointTargetAngle(joint_handle[5], t6);
  return true;
}

bool Robot::Solve() {
  double goal_x, goal_y, goal_z;
  double start_x, start_y, start_z;
  GetEndEffectorPosition();
  start_x = state.x;
  start_y = state.y;
  start_z = state.z;
  std::cout << "Enter goal x, y, z co-ordinates: ";
  std::cin >> goal_x >> goal_y >> goal_z;
  double dxt, dyt, dzt;
  while (true) {
    std::vector<double> dx_dy_dz = TrajectoryPlanner(goal_x, goal_y, goal_z);
    dxt += dx_dy_dz[0];
    dyt += dx_dy_dz[1];
    dzt += dx_dy_dz[2];
    MatrixXd q_(4, 1);
    bool status = solver->PerformIK(dx_dy_dz[0], dx_dy_dz[1], dx_dy_dz[2], &q_);
    cout << "\n\nQ is: " << q_.transpose() << endl;
    double t1, t2, t3, t4, t5, t6;
    t1 = simulator->GetJointAngle(joint_handle[0]);
    t2 = simulator->GetJointAngle(joint_handle[1]);
    t3 = simulator->GetJointAngle(joint_handle[2]);
    t4 = simulator->GetJointAngle(joint_handle[3]);
    t5 = simulator->GetJointAngle(joint_handle[4]);
    t6 = simulator->GetJointAngle(joint_handle[5]);
    t1 += q_(0, 0);
    t2 += q_(1, 0);
    t3 += q_(2, 0);
    float error = pow(pow((state.x - start_x + dxt), 2) +
                          pow((state.y - start_y + dxt), 2) +
                          pow((state.z - start_z + dxt), 2),
                      0.5);
    cout << "Error from target position: " << error << endl;
    Controller(t1, t2, t3, t4, t5, t6);
    sleep(1);
  }
  return true;
}
