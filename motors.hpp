/*
* motors.cpp
*
* Header file for the function prottypes driving the steppers and servos of
* the collection arm.
*/

#ifndef MOTORS_HPP
#define MOTORS_HPP
#define armSpeed           200   // Motor speed for the arm extender motor
#define bucketStartingPos -90   // Lowers the bucket to parallel to ground
#define depositAngle      -45   // Lowers bucket 45deg to deposit balls in hole
#define incline30          30   // Increase angle 30 degrees to pick up ball

#include <Arduino.h>
#include <Servo.h>

// Class for using the servo motor
extern Servo bucketServo;

// Pins for the arm-horizontal DC motor
const byte horizontalMotorPin1 = 34; // IN1
const byte horizontalMotorPin2 = 35; // IN2
const byte horizontalMotorENA = 8;   // ENA

// Pins for the arm-vertical DC motor
const byte verticalMotorPin1 = 36;   //IN3
const byte verticalMotorPin2 = 37;   //IN4
const byte verticalMotorENB = 9;     //ENB

// Rotates the servo the lower the bucket parallel to ground to pick up the ball
void bucketAngle(int angle);

// Runs the DC motor responsible for extending the arm
void extendArm(int time);

// Runs the DC motor responsible for retracting the arm
void retractArm(int time);

// Runs the DC motor responsible for elevating the arm
void elevateArm(int time);

// Runs the DC motor responsible for lowering the arm
void lowerArm(int time);

#endif