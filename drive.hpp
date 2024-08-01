/*
* drive.hpp
*
* Function prototypes for wheel rotations used to move the build are found here
*/

#ifndef DRIVE_HPP
#define DRIVE_HPP

#include <Arduino.h>
 
// Define the wheels for each motor and the pins they will use
// Right wheel pin setup:
const byte RearRightWheelpin1 = 32;  // IN1
const byte RearRightWheelpin2 = 33;  // IN2

const byte FrontRightWheelpin1 = 30; // IN3
const byte FrontRightWheelpin2 = 31; // IN4

const byte RearRightENA = 5;         // ENB
const byte FrontRightENB = 4;        // ENA

// Left wheel pin setup:
const byte FrontLeftWheelpin1 = 38;  // IN1
const byte FrontLeftWheelpin2 = 39;  // IN2

const byte RearLeftWheelpin1 = 40;   // IN3
const byte RearLeftWheelpin2 = 41;   // IN4

const byte FrontLeftENA = 6;         // ENA
const byte RearLeftENB = 7;          // ENB

// Set individual wheel rotations to move forward
void moveForward(int speed);

// Set individual wheel rotations to move backwards
void moveBackward(int speed);

// Set individual wheel rotations to move sideways-right
void moveSidewaysRight(int speed);

// Set individual wheel rotations to move sideways-left
void moveSidewaysLeft(int speed);

// Set individual wheel rotations to rotate left
void rotateLeft(int time, int speed);

// Set individual wheel rotations to rotate right
void rotateRight(int time, int speed);

// Set individual wheel rotations to stop moving
// Called whenever turning, pickin up ball or depositing ball
void stopMoving(void);

#endif