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



      //cout << "\n------Joint matrix " << it + 1 << " --------\n";
      //float* joint_ptr = new float[12];
      //joint_matrix.push_back(joint_ptr);
      //simulator->GetJointMatrix(joint_handle[it], joint_matrix[it]);

      // cout << "\n------Link matrix " << it << " --------\n";
      // float* link_ptr = new float[12];
      // link_matrix.push_back(link_ptr);
      // simulator->GetJointMatrix(link_handle[it], link_matrix[it]);
    }
    float theta=0.0;
    //< Perform some actions by commanding joint angles(in radians).
    ForwardKinematics(theta, theta, theta, theta, theta, theta);
    
    sleep(1);

    //< Get positions of objects(joints in this case).
    simxFloat position[3];
    simxFloat orientation[3];
    simxFloat matrix[12];

    simulator->GetObjectPosition(joint_handle[4], origin_handle, position);
    ChainTransformations(position[0], position[1], position[2]);


    for (int it = 0; it < 6; it++) {
      cout << "\n------Joint position of " << it +1 
           << " [x, y, x] wrt to Origin --------\n";
      simulator->GetObjectPosition(joint_handle[it], origin_handle, position);
      simulator->GetObjectOrientation(joint_handle[it], origin_handle,
                                      orientation);
    }

      cout << "\n---Joint position and orientation of 1"  << "  wrt to "
           << " orgin is: "
           << "---\n";
      simulator->GetObjectPosition(joint_handle[0], origin_handle,
                                   position);
      simulator->GetObjectOrientation(joint_handle[0], origin_handle,
                                      orientation);
    for (int it = 1; it < 6; it++) {
      cout << "\n---Joint position and orientation of " << it +1 << "  wrt to "
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

void Robot::ForwardKinematics(float t1, float t2, float t3, float t4, float t5,
                              float t6) {
  cout << "Starting Froward Kinematics " << endl;
  simulator->SetJointTargetAngle(joint_handle[0], t1);
  simulator->SetJointTargetAngle(joint_handle[1], t2);
  simulator->SetJointTargetAngle(joint_handle[2], t3);
  simulator->SetJointTargetAngle(joint_handle[3], t4);
  simulator->SetJointTargetAngle(joint_handle[4], t5);
  simulator->SetJointTargetAngle(joint_handle[5], t6);

  //------------1 to 2------------//
}

void Robot::ChainTransformations(float x, float y, float z){
  cout<<"\nTransfomation matrix chain from Origin to End Effector:"<<endl;
  double t1, t2, t3, t4, t5, t6;
  double a1= -0.0703083;
  double d1= 0.0660392;
  double a2 = 0.425103;
  double d2=0;
  double a3=0.392149;
  double a4 = 0.0455737;
  double d4 = 0.0397052;
  double d5= 0.0491754;
  double a5 = 0.0144247;

  t1 = t2 = t3 = t4 = t5 = 0.0;

  //Vector3f ot; << 0.3, -0.275, 0.04315;
  Matrix4d T(4,4);
  T << 1, 0, 0, 0.3,
  0, 1, 0, -0.275,
  0, 0, 1, 0.04315,
  0, 0, 0, 1; //j1

  Matrix4d Tn(4,4);
  
  Tn << cos(t1), -sin(t1), 0, a1,
        sin(t1), cos(t1), 0, 1.2219E-06,
        0, 0, 1, d1,
        0, 0, 0, 1;
  T=T*Tn; 

  //T = T*[roty(-90) z'; z 1]*[rotz(-90) z'; z 1]; %j2
  /*
  Tn << 0, 0, -1, 0,
  -1, 0, 0, 0,
  0, 1, 0, 0,
  0, 0, 0, 1;
  */

  //T = T*[roty(-90) z'; z 1]
  Tn << 0, 0, -1, 0,
  0, 1, 0, 0,
  1, 0, 0, 0,
  0, 0, 0, 1;

  T = T*Tn; //j2

  Tn << cos(t2), -sin(t2), 0, a2,
        sin(t2), cos(t2), 0, 1.74344e-05,
        0, 0, 1, 9.50694e-06,
        0, 0, 0, 1;
  T = T*Tn; //j3

  Tn<<  cos(t3), -sin(t3), 0, a3,
        sin(t3), cos(t3), 0, -1.60933e-06,
        0, 0, 1, 1.40071e-06,
        0, 0, 0, 1;
  T = T*Tn; //j4

  Tn << cos(t4), -sin(t4), 0, a4,
        sin(t4), cos(t4), 0, 2.95043e-06,
        0, 0, 1, d4,
        0, 0, 0, 1;
  T = T*Tn;
  //T = T*[roty(90) [0 0 0]'; z 1]; %j5
  Tn << 0, 0, 1, 0,
  0, 1, 0, 0,
  -1, 0, 0, 0,
  0, 0, 0, 1;
  T = T*Tn;

 // T = T*[Rz(t5) [a5 0 d5]'; z 1]; %j6
    Tn << cos(t5), -sin(t5), 0, a5,
        sin(t5), cos(t5), 0, 3.27826e-07,
        0, 0, 1, d5,
        0, 0, 0, 1;
  T = T * Tn;
  //T = T*[roty(-90) [0 0 0]'; z 1];
  Tn << 0, 0, -1, 0,
  0, 1, 0, 0,
  1, 0, 0, 0,
  0, 0, 0, 1;
  T = T*Tn;
  
  float error = pow( pow( x-T(0,3) ,2 )  + pow(  y-T(1,3), 2 )  + pow( z-T(2,3),2 ) , 0.5 )  ;
  cout<<"\nTransformation matrix is: \n"<<T <<endl;
  cout<<" Error is: "<<error; 


  cout<<"Starting Jacobian inverse motion........ "<<endl;
  int i=0;
  while(i<50){
    i++;
  sleep(0.1);
  float dx=0.0000001,dy=0.0,dz=0.0;
  dx += dx;

  t1 = simulator->GetJointAngle(joint_handle[0]);
  t2 = simulator->GetJointAngle(joint_handle[1]);
  t3 = simulator->GetJointAngle(joint_handle[2]);
  t4 = simulator->GetJointAngle(joint_handle[3]);
  t5 = simulator->GetJointAngle(joint_handle[4]);
  t6 = simulator->GetJointAngle(joint_handle[5]);


  
  MatrixXd J(3,4);
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
  MatrixXd jtj = J.transpose()*J;
  MatrixXd jtji = jtj.inverse();
  MatrixXd jtjijt = jtji*J.transpose();
  //Jp = ( J.transpose()*J ).inverse() )*J.transpose();
  Jp = jtjijt;
  cout<<"Jacobian pseudo inverse: \n"<<Jp<<endl;
  if (Jp(1,1) != Jp(1,1)){
    cout<<" Singularity " <<endl;
    continue;
  }
  MatrixXd q(4,1);
  MatrixXd v(3,1);
  v<< dx,dy,dz;
  q = Jp * v;
  cout<<"Computed joint angles: "<<q.transpose()<<endl<<endl;
  simulator->SetJointTargetAngle(joint_handle[0], q(0,0));
  simulator->SetJointTargetAngle(joint_handle[1], q(1,0));
  simulator->SetJointTargetAngle(joint_handle[2], q(2,0));  
  simulator->SetJointTargetAngle(joint_handle[3], q(3,0));
  }
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
