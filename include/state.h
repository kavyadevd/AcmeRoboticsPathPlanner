/**
 * @file state.h
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam (aswath@umd.edu)
 * @brief The header file for coordinate system used in the project
 * @version 0.1
 * @date 2021-10-04
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef STATE_H_  // NOLINT
#define STATE_H_

class State {
 public:
    double x;               ///< Variable to store the position x-coordinate
    double y;               ///< Variable to store the position y-coordinate
    double z;               ///< Variable to store the position z-coordinate
    double theta;           ///< Variable to store position position theta value
    double phi;             ///< Variable to store tposition position phi value
    double alpha;             ///< Variable to store position position alpha value

/**
* @brief Construct a new state object. Sets default values to all attributes
*/
    State();
};


#endif  // STATE_H_  // NOLINT