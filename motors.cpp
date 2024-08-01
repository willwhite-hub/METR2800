/*
* motors.cpp
*
* This is where functions for driving the steppers and servos of
* the collection arm are defined.
*/

#include <motors.hpp>
#include <Arduino.h>
#include <Servo.h> 

Servo bucketServo; // Create object to control bucket servo

void bucketAngle(int angle) {
    bucketServo.write(angle); // Lowers bucket to parallel with ground
}                         

// Delays will need to be added, and possibly more functions written, to get the correct distance depending
// on the ball position when extending/retracting
void extendArm(int time) {  
    analogWrite(horizontalMotorENA, armSpeed);
    digitalWrite(horizontalMotorPin1, HIGH);
    digitalWrite(horizontalMotorPin2, LOW);
    delay(time); // Run for time(ms)
    digitalWrite(horizontalMotorPin1, LOW);
    digitalWrite(horizontalMotorPin2, LOW);                                
}

void retractArm(int time) {
    analogWrite(horizontalMotorENA, armSpeed);
    digitalWrite(horizontalMotorPin1, LOW);
    digitalWrite(horizontalMotorPin2, HIGH);
    delay(time); // Run for time (ms) 
    digitalWrite(horizontalMotorPin1, LOW);
    digitalWrite(horizontalMotorPin2, LOW);
}

void elevateArm(int time) { // Runs the motor to elevate the arm for delay(); milliseconds
    analogWrite(verticalMotorENB, armSpeed);
    digitalWrite(verticalMotorPin1, HIGH);
    digitalWrite(verticalMotorPin2, LOW);
    delay(time); // Run for time (ms) 
    digitalWrite(verticalMotorPin1, LOW);
    digitalWrite(verticalMotorPin2, LOW);
}

void lowerArm(int time) {  // Runs the motor to lower the arm for delay(); milliseconds
    analogWrite(verticalMotorENB, armSpeed);
    digitalWrite(verticalMotorPin1, LOW);
    digitalWrite(verticalMotorPin2, HIGH);
    delay(time); // Run for time (ms)  
    digitalWrite(verticalMotorPin1, LOW);
    digitalWrite(verticalMotorPin2, LOW);
}