/**
 * @file solver.cpp
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam
 * (aswath@umd.edu)
 * @brief File for arm manipulator path planning solver definitions
 *
 * @version 0.1
 * @date 2021-10-05
 * @copyright  All rights reserved
 * Note: Transformation matrix notations are as follows:
 *  0                               |06R    0P6|
 *      T(θ1, θ2, θ3, θ4, θ5, θ6) = |          |
 *  6                               |0      1  |
 *
 *                                  |0X6x   0Y6x     0Z6x    0P6x|
 *                                  |0X6y   0Y6y     0Z6y    0P6y|
 *                            =     |0X6z   0Y6z     0Z6z    0P6z|
 *                                  |  0     0        0        0 |
 *
 */

#include "solver.h"  // NOLINT

#include <math.h>
#include <unistd.h>  // NOLINT

#include <Eigen/Dense>  // NOLINT
#include <cmath>        // NOLINT
#include <iostream>     // NOLINT
#include <vector>       // NOLINT

using Eigen::Matrix4d;
using Eigen::MatrixXd;
using std::cout;
using std::endl;
using std::vector;

Solver::Solver(Simulator* simulator, vector<simxInt> joint_handle) {
  this->simulator = simulator;
  this->joint_handle = joint_handle;
  SetErrorTolerance(0.5);
}

bool Solver::PerformIK(double dx, double dy, double dz, MatrixXd* q_ptr) {
  std::cout << "Starting Jacobian inverse motion........ " << std::endl;
  double t1, t2, t3, t4;  // t5, t6;
  // float dx = -0.0, dy = 0.001, dz = -0.001;  // For test against hard-coded
  // values
  MatrixXd J(3, 4);
  sleep(0.80);
  t1 = simulator->GetJointAngle(joint_handle[0]);
  t2 = simulator->GetJointAngle(joint_handle[1]);
  t3 = simulator->GetJointAngle(joint_handle[2]);
  t4 = simulator->GetJointAngle(joint_handle[3]);
  //t5 = simulator->GetJointAngle(joint_handle[4]);
  //t6 = simulator->GetJointAngle(joint_handle[5]);

  // Computing Jacobian Matrix. Constant values for calculation obtained using
  // MATLAB simulation
  J(0, 0) =
      (14573216048606699 * sin(t1)) / 576460752303423488 -
      (7064328361094851 * cos(t1) * sin(t2)) / 18014398509481984 -
      (7086922019705443 * cos(t4) *
       (cos(t1) * cos(t2) * sin(t3) + cos(t1) * cos(t3) * sin(t2))) /
          144115188075855872 +
      (7086922019705443 * sin(t4) *
       (cos(t1) * sin(t2) * sin(t3) - cos(t1) * cos(t2) * cos(t3))) /
          144115188075855872 -
      (6567862346812633 * cos(t1) * cos(t2) * sin(t3)) / 144115188075855872 -
      (6567862346812633 * cos(t1) * cos(t3) * sin(t2)) / 144115188075855872;
  J(0, 1) =
      (7086922019705443 * cos(t4) *
       (sin(t1) * sin(t2) * sin(t3) - cos(t2) * cos(t3) * sin(t1))) /
          144115188075855872 -
      (7064328361094851 * cos(t2) * sin(t1)) / 18014398509481984 +
      (7086922019705443 * sin(t4) *
       (cos(t2) * sin(t1) * sin(t3) + cos(t3) * sin(t1) * sin(t2))) /
          144115188075855872 +
      (6567862346812633 * sin(t1) * sin(t2) * sin(t3)) / 144115188075855872 -
      (6567862346812633 * cos(t2) * cos(t3) * sin(t1)) / 144115188075855872;
  J(0, 2) =
      (7086922019705443 * cos(t4) *
       (sin(t1) * sin(t2) * sin(t3) - cos(t2) * cos(t3) * sin(t1))) /
          144115188075855872 +
      (7086922019705443 * sin(t4) *
       (cos(t2) * sin(t1) * sin(t3) + cos(t3) * sin(t1) * sin(t2))) /
          144115188075855872 +
      (6567862346812633 * sin(t1) * sin(t2) * sin(t3)) / 144115188075855872 -
      (6567862346812633 * cos(t2) * cos(t3) * sin(t1)) / 144115188075855872;
  J(0, 3) = (7086922019705443 * cos(t4) *
             (sin(t1) * sin(t2) * sin(t3) - cos(t2) * cos(t3) * sin(t1))) /
                144115188075855872 +
            (7086922019705443 * sin(t4) *
             (cos(t2) * sin(t1) * sin(t3) + cos(t3) * sin(t1) * sin(t2))) /
                144115188075855872;
  J(1, 0) =
      (7086922019705443 * sin(t4) *
       (sin(t1) * sin(t2) * sin(t3) - cos(t2) * cos(t3) * sin(t1))) /
          144115188075855872 -
      (7064328361094851 * sin(t1) * sin(t2)) / 18014398509481984 -
      (7086922019705443 * cos(t4) *
       (cos(t2) * sin(t1) * sin(t3) + cos(t3) * sin(t1) * sin(t2))) /
          144115188075855872 -
      (14573216048606699 * cos(t1)) / 576460752303423488 -
      (6567862346812633 * cos(t2) * sin(t1) * sin(t3)) / 144115188075855872 -
      (6567862346812633 * cos(t3) * sin(t1) * sin(t2)) / 144115188075855872;
  J(1, 1) =
      (7064328361094851 * cos(t1) * cos(t2)) / 18014398509481984 -
      (7086922019705443 * cos(t4) *
       (cos(t1) * sin(t2) * sin(t3) - cos(t1) * cos(t2) * cos(t3))) /
          144115188075855872 -
      (7086922019705443 * sin(t4) *
       (cos(t1) * cos(t2) * sin(t3) + cos(t1) * cos(t3) * sin(t2))) /
          144115188075855872 -
      (6567862346812633 * cos(t1) * sin(t2) * sin(t3)) / 144115188075855872 +
      (6567862346812633 * cos(t1) * cos(t2) * cos(t3)) / 144115188075855872;
  J(1, 2) =
      (6567862346812633 * cos(t1) * cos(t2) * cos(t3)) / 144115188075855872 -
      (7086922019705443 * sin(t4) *
       (cos(t1) * cos(t2) * sin(t3) + cos(t1) * cos(t3) * sin(t2))) /
          144115188075855872 -
      (6567862346812633 * cos(t1) * sin(t2) * sin(t3)) / 144115188075855872 -
      (7086922019705443 * cos(t4) *
       (cos(t1) * sin(t2) * sin(t3) - cos(t1) * cos(t2) * cos(t3))) /
          144115188075855872;
  J(1, 3) = -(7086922019705443 * cos(t4) *
              (cos(t1) * sin(t2) * sin(t3) - cos(t1) * cos(t2) * cos(t3))) /
                144115188075855872 -
            (7086922019705443 * sin(t4) *
             (cos(t1) * cos(t2) * sin(t3) + cos(t1) * cos(t3) * sin(t2))) /
                144115188075855872;
  J(2, 0) = 0;
  J(2, 1) =
      -(7064328361094851 * sin(t2)) / 18014398509481984 -
      (6567862346812633 * cos(t2) * sin(t3)) / 144115188075855872 -
      (6567862346812633 * cos(t3) * sin(t2)) / 144115188075855872 -
      (7086922019705443 * cos(t4) * (cos(t2) * sin(t3) + cos(t3) * sin(t2))) /
          144115188075855872 -
      (7086922019705443 * sin(t4) * (cos(t2) * cos(t3) - sin(t2) * sin(t3))) /
          144115188075855872;
  J(2, 2) =
      -(6567862346812633 * cos(t2) * sin(t3)) / 144115188075855872 -
      (6567862346812633 * cos(t3) * sin(t2)) / 144115188075855872 -
      (7086922019705443 * cos(t4) * (cos(t2) * sin(t3) + cos(t3) * sin(t2))) /
          144115188075855872 -
      (7086922019705443 * sin(t4) * (cos(t2) * cos(t3) - sin(t2) * sin(t3))) /
          144115188075855872;
  J(2, 3) =
      -(7086922019705443 * cos(t4) * (cos(t2) * sin(t3) + cos(t3) * sin(t2))) /
          144115188075855872 -
      (7086922019705443 * sin(t4) * (cos(t2) * cos(t3) - sin(t2) * sin(t3))) /
          144115188075855872;
  MatrixXd Jp(4, 3);
  // Jp = ( J.transpose()*J ).inverse() )*J.transpose();
  // Calculating Jacobian Inverse
  MatrixXd jtj = J.transpose() * J;
  MatrixXd jtji = jtj.inverse();
  MatrixXd jtjijt = jtji * J.transpose();
  Jp = jtjijt;
  std::cout << "Jacobian pseudo inverse: \n" << Jp << std::endl;

  if (Jp(1, 1) != Jp(1, 1)) {
    std::cout << " Singularity " << std::endl;
    return false;
  }

  MatrixXd v(3, 1);
  v << dx, dy, dz;
  MatrixXd q_ = *(q_ptr);
  q_ = Jp * v;
  if (abs(q_(0, 0)) > 1.5 || abs(q_(1, 0)) > 1.5 || abs(q_(2, 0)) > 1.5) {
    std::cout << "Very large angle displacement\n Computing in next iteration "
                 "after a small perturbation.\n";
  }

  std::cout << "Computed joint angles: " << q_.transpose() << std::endl;
  *q_ptr << q_;
  return true;
}

bool Solver::SetErrorTolerance(double _error) {
  error_tolerance = _error;
  return true;
}

double Solver::GetErrorTolerance() { return error_tolerance; }

bool Solver::IsErrorTolerable(double _error) {
  return (error_tolerance >= _error);
}
