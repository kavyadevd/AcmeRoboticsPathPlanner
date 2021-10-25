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
 *      T(θ1,θ2,θ3,θ4,θ5,θ6) =      |          |
 *  6                               |0      1  |
 * 
 *                                  |0X6x   0Y6x     0Z6x    0P6x|
 *                                  |0X6y   0Y6y     0Z6y    0P6y|
 *                            =     |0X6z   0Y6z     0Z6z    0P6z|
 *                                  |  0     0        0        0 |
 * 
 */


#include<math.h>
#include "solver.h"     // NOLINT
#include <Eigen/Dense>
#include <unistd.h>
#include <cmath>
#include <iostream>
#include <vector>


using std::cout;
using std::endl;
using std::vector;
using Eigen::Matrix4d;
using Eigen::MatrixXd;


Solver::Solver(Simulator* simulator, vector<simxInt> joint_handle) {
    this->simulator = simulator;
    this->joint_handle = joint_handle;
    error_tolerance = 0.5;
}

int Solver::PerformIK() {

  cout<<"Starting Jacobian inverse motion........ "<<endl;
  double t1, t2, t3, t4, t5, t6;
  int i=0;
  float dx=-0.0,dy=0.001,dz=-0.001;
  MatrixXd J(3,4);
  MatrixXd q(4,1);
  MatrixXd q_(4,1);
  while(i<1000){
    i++;
  sleep(0.80);

  t1 = simulator->GetJointAngle(joint_handle[0]);
  t2 = simulator->GetJointAngle(joint_handle[1]);
  t3 = simulator->GetJointAngle(joint_handle[2]);
  t4 = simulator->GetJointAngle(joint_handle[3]);
  t5 = simulator->GetJointAngle(joint_handle[4]);
  t6 = simulator->GetJointAngle(joint_handle[5]);

  J(0,0) = (14573216048606699*sin(t1))/576460752303423488 - (7064328361094851*cos(t1)*sin(t2))/18014398509481984 - (7086922019705443*cos(t4)*(cos(t1)*cos(t2)*sin(t3) + cos(t1)*cos(t3)*sin(t2)))/144115188075855872 + (7086922019705443*sin(t4)*(cos(t1)*sin(t2)*sin(t3) - cos(t1)*cos(t2)*cos(t3)))/144115188075855872 - (6567862346812633*cos(t1)*cos(t2)*sin(t3))/144115188075855872 - (6567862346812633*cos(t1)*cos(t3)*sin(t2))/144115188075855872 ;
  J(0,1) = (7086922019705443*cos(t4)*(sin(t1)*sin(t2)*sin(t3) - cos(t2)*cos(t3)*sin(t1)))/144115188075855872 - (7064328361094851*cos(t2)*sin(t1))/18014398509481984 + (7086922019705443*sin(t4)*(cos(t2)*sin(t1)*sin(t3) + cos(t3)*sin(t1)*sin(t2)))/144115188075855872 + (6567862346812633*sin(t1)*sin(t2)*sin(t3))/144115188075855872 - (6567862346812633*cos(t2)*cos(t3)*sin(t1))/144115188075855872 ; 
  J(0,2) =(7086922019705443*cos(t4)*(sin(t1)*sin(t2)*sin(t3) - cos(t2)*cos(t3)*sin(t1)))/144115188075855872 + (7086922019705443*sin(t4)*(cos(t2)*sin(t1)*sin(t3) + cos(t3)*sin(t1)*sin(t2)))/144115188075855872 + (6567862346812633*sin(t1)*sin(t2)*sin(t3))/144115188075855872 - (6567862346812633*cos(t2)*cos(t3)*sin(t1))/144115188075855872 ;
  J(0,3) = (7086922019705443*cos(t4)*(sin(t1)*sin(t2)*sin(t3) - cos(t2)*cos(t3)*sin(t1)))/144115188075855872 + (7086922019705443*sin(t4)*(cos(t2)*sin(t1)*sin(t3) + cos(t3)*sin(t1)*sin(t2)))/144115188075855872;

  J(1,0) = (7086922019705443*sin(t4)*(sin(t1)*sin(t2)*sin(t3) - cos(t2)*cos(t3)*sin(t1)))/144115188075855872 - (7064328361094851*sin(t1)*sin(t2))/18014398509481984 - (7086922019705443*cos(t4)*(cos(t2)*sin(t1)*sin(t3) + cos(t3)*sin(t1)*sin(t2)))/144115188075855872 - (14573216048606699*cos(t1))/576460752303423488 - (6567862346812633*cos(t2)*sin(t1)*sin(t3))/144115188075855872 - (6567862346812633*cos(t3)*sin(t1)*sin(t2))/144115188075855872;
  J(1,1) = (7064328361094851*cos(t1)*cos(t2))/18014398509481984 - (7086922019705443*cos(t4)*(cos(t1)*sin(t2)*sin(t3) - cos(t1)*cos(t2)*cos(t3)))/144115188075855872 - (7086922019705443*sin(t4)*(cos(t1)*cos(t2)*sin(t3) + cos(t1)*cos(t3)*sin(t2)))/144115188075855872 - (6567862346812633*cos(t1)*sin(t2)*sin(t3))/144115188075855872 + (6567862346812633*cos(t1)*cos(t2)*cos(t3))/144115188075855872;
  J(1,2) = (6567862346812633*cos(t1)*cos(t2)*cos(t3))/144115188075855872 - (7086922019705443*sin(t4)*(cos(t1)*cos(t2)*sin(t3) + cos(t1)*cos(t3)*sin(t2)))/144115188075855872 - (6567862346812633*cos(t1)*sin(t2)*sin(t3))/144115188075855872 - (7086922019705443*cos(t4)*(cos(t1)*sin(t2)*sin(t3) - cos(t1)*cos(t2)*cos(t3)))/144115188075855872 ;
  J(1,3) = - (7086922019705443*cos(t4)*(cos(t1)*sin(t2)*sin(t3) - cos(t1)*cos(t2)*cos(t3)))/144115188075855872 - (7086922019705443*sin(t4)*(cos(t1)*cos(t2)*sin(t3) + cos(t1)*cos(t3)*sin(t2)))/144115188075855872 ;

  J(2,0) = 0; 
  J(2,1) = - (7064328361094851*sin(t2))/18014398509481984 - (6567862346812633*cos(t2)*sin(t3))/144115188075855872 - (6567862346812633*cos(t3)*sin(t2))/144115188075855872 - (7086922019705443*cos(t4)*(cos(t2)*sin(t3) + cos(t3)*sin(t2)))/144115188075855872 - (7086922019705443*sin(t4)*(cos(t2)*cos(t3) - sin(t2)*sin(t3)))/144115188075855872 ;
  J(2,2) = - (6567862346812633*cos(t2)*sin(t3))/144115188075855872 - (6567862346812633*cos(t3)*sin(t2))/144115188075855872 - (7086922019705443*cos(t4)*(cos(t2)*sin(t3) + cos(t3)*sin(t2)))/144115188075855872 - (7086922019705443*sin(t4)*(cos(t2)*cos(t3) - sin(t2)*sin(t3)))/144115188075855872;
  J(2,3) = - (7086922019705443*cos(t4)*(cos(t2)*sin(t3) + cos(t3)*sin(t2)))/144115188075855872 - (7086922019705443*sin(t4)*(cos(t2)*cos(t3) - sin(t2)*sin(t3)))/144115188075855872 ;

  MatrixXd Jp(4,3);
  //Jp = ( J.transpose()*J ).inverse() )*J.transpose();
  //Calculating Jacobian Inverse
  MatrixXd jtj = J.transpose()*J;
  MatrixXd jtji = jtj.inverse();
  MatrixXd jtjijt = jtji*J.transpose();
  Jp = jtjijt;
  cout<<"Jacobian pseudo inverse: \n"<<Jp<<endl;
  if (Jp(1,1) != Jp(1,1)){
    cout<<" Singularity " <<endl;
    continue;
  }
  MatrixXd v(3,1);
  v<< dx,dy,dz;
  q_ = Jp * v;
  q+=q_;
  cout<<"Computed joint angles: "<<q.transpose()<<endl<<endl;
  simulator->SetJointTargetAngle(joint_handle[0], q(0,0));
  simulator->SetJointTargetAngle(joint_handle[1], q(1,0));
  simulator->SetJointTargetAngle(joint_handle[2], q(2,0));  
  //simulator->SetJointTargetAngle(joint_handle[3], q(3,0));
  }

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
