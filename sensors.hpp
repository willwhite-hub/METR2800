/*
*
* sensors.hpp
*
* Defines all variables and function prototypes related to the sensors
*/

#ifndef SENSORS_HPP
#define SENSORS_HPP

#include <Arduino.h>
#include <NewPing.h>


// US sensor setup
const byte triggerPin = 46; // Trigger pin
const byte echoPin = 47;    // Echo pin
const byte maxDist = 200;    // Max distance we want to measure (cm)

// Bucket IR sensor (1) pin
const byte obstaclePin1 = 23; 
// Bucket IR sensor (2) pin
const byte obstaclePin2 = 24; 
// Port side IR sensor pin
const byte portPin = 52;
// Starboard IR sensor pin
const byte starboardPin = 22;

// Sends out ping every 30ms to get distance to obstacle in forward direction
int pingSonarForward();

// Checks for ball, returns 1 if ball in path, nothing otherwise
int bucketIR1();

// Checks for ball, returns 1 if ball in path, nothing otherwise
int bucketIR2();

// Edge detection on port side
int portIR();

// Edge detection starboard side
int starboardIR();

#endif