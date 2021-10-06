/**
 * @file position.h
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam (aswath@umd.edu)
 * @brief The header file for coordinate system used in the project
 * @version 0.1
 * @date 2021-10-04
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef POSITION_H_  // NOLINT
#define POSITION_H_

class Position {
 public:
    double x;
    double y;
    double z;
    double theta;
    double phi;
    double shi;

/**
* @brief Construct a new position object. Sets default values to all attributes
*/
    Position();
};


#endif  // POSITION_H_  // NOLINT