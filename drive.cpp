/*
* drive.cpp
*
* This is where functionality related to movement of
* the build are defined.
*/
#include <Arduino.h>
#include <drive.hpp>

// Set individual wheel rotations for given movement
void moveForward(int speed) {
  // Set front motors to forward
  digitalWrite(FrontLeftWheelpin1, HIGH);
  digitalWrite(FrontLeftWheelpin2, LOW);
  digitalWrite(FrontRightWheelpin1, HIGH);
  digitalWrite(FrontRightWheelpin2, LOW);
  // Set rear motors to forward
  digitalWrite(RearLeftWheelpin1, HIGH);
  digitalWrite(RearLeftWheelpin2, LOW);
  digitalWrite(RearRightWheelpin1, HIGH);
  digitalWrite(RearRightWheelpin2, LOW);

  analogWrite(FrontLeftENA, speed);   // Send PWM to FL motor
  analogWrite(FrontRightENB, 200);  // Send PWM to FR motor
  analogWrite(RearLeftENB, speed);    // Send PWM to RL motor
  analogWrite(RearRightENA, speed);   // Send PWM to RR motor

}

void moveBackward(int speed) {
  // Set front motors to reverse. 
  digitalWrite(FrontLeftWheelpin1, LOW);
  digitalWrite(FrontLeftWheelpin2, HIGH);
  digitalWrite(FrontRightWheelpin1, LOW);
  digitalWrite(FrontRightWheelpin2, HIGH);
  // Set rear motors to reverse
  digitalWrite(RearLeftWheelpin1, LOW);
  digitalWrite(RearLeftWheelpin2, HIGH);
  digitalWrite(RearRightWheelpin1, LOW);
  digitalWrite(RearRightWheelpin2, HIGH);

  analogWrite(FrontLeftENA, speed);   // Send PWM to FL motor
  analogWrite(FrontRightENB, 210);  // Send PWM to FR motor
  analogWrite(RearLeftENB, speed);    // Send PWM to RL motor
  analogWrite(RearRightENA, speed);   // Send PWM to RR motor
  
}

void moveSidewaysRight(int speed) {
  // Set front motors to sideways right
  digitalWrite(FrontLeftWheelpin1, HIGH);
  digitalWrite(FrontLeftWheelpin2, LOW);
  digitalWrite(FrontRightWheelpin1, LOW);
  digitalWrite(FrontRightWheelpin2, HIGH);
  // Set rear motors to sideways right
  digitalWrite(RearLeftWheelpin1, LOW);
  digitalWrite(RearLeftWheelpin2, HIGH);
  digitalWrite(RearRightWheelpin1, HIGH);
  digitalWrite(RearRightWheelpin2, LOW);

  analogWrite(FrontLeftENA, speed);   // Send PWM to FL motor
  analogWrite(FrontRightENB, 200);  // Send PWM to FR motor
  analogWrite(RearLeftENB, speed);    // Send PWM to RL motor
  analogWrite(RearRightENA, speed);   // Send PWM to RR motor

}

void moveSidewaysLeft(int speed) {
  // Set front left to forward; front right to reverse
  digitalWrite(FrontLeftWheelpin1, LOW);
  digitalWrite(FrontLeftWheelpin2, HIGH);
  digitalWrite(FrontRightWheelpin1, HIGH);
  digitalWrite(FrontRightWheelpin2, LOW);
  // Set rear left to reverse; rear right to forward
  digitalWrite(RearLeftWheelpin1, HIGH);
  digitalWrite(RearLeftWheelpin2, LOW);
  digitalWrite(RearRightWheelpin1, LOW);
  digitalWrite(RearRightWheelpin2, HIGH);

  analogWrite(FrontLeftENA, 150);   // Send PWM to FL motor
  analogWrite(FrontRightENB, 200);  // Send PWM to FR motor
  analogWrite(RearLeftENB, speed);    // Send PWM to RL motor
  analogWrite(RearRightENA, speed);   // Send PWM to RR motor

}

void rotateLeft(int time, int speed) {
  // Set left motors to reverse; right to forward
  digitalWrite(FrontLeftWheelpin1, LOW);
  digitalWrite(FrontLeftWheelpin2, HIGH);
  digitalWrite(FrontRightWheelpin1, HIGH);
  digitalWrite(FrontRightWheelpin2, LOW);
  // Set left motors to reverse; right to forward
  digitalWrite(RearLeftWheelpin1, LOW);
  digitalWrite(RearLeftWheelpin2, HIGH);
  digitalWrite(RearRightWheelpin1, HIGH);
  digitalWrite(RearRightWheelpin2, LOW);

  analogWrite(FrontLeftENA, speed);   // Send PWM to FL motor
  analogWrite(FrontRightENB, 220);  // Send PWM to FR motor
  analogWrite(RearLeftENB, speed);    // Send PWM to RL motor
  analogWrite(RearRightENA, speed);   // Send PWM to RR motor
  
  delay(time); // Run for given period of time

  // Set all motor pins to low to stop after given time 
  digitalWrite(FrontLeftWheelpin1, LOW);
  digitalWrite(FrontLeftWheelpin2, LOW);
  digitalWrite(FrontRightWheelpin1, LOW);
  digitalWrite(FrontRightWheelpin2, LOW);
  
  digitalWrite(RearLeftWheelpin1, LOW);
  digitalWrite(RearLeftWheelpin2, LOW);
  digitalWrite(RearRightWheelpin1, LOW);
  digitalWrite(RearRightWheelpin2, LOW);
}

void rotateRight(int time, int speed) {
    // Set left motors to forward; right to reverse
  digitalWrite(FrontLeftWheelpin1, HIGH);
  digitalWrite(FrontLeftWheelpin2, LOW);
  digitalWrite(FrontRightWheelpin1, LOW);
  digitalWrite(FrontRightWheelpin2, HIGH);
  // Set left motors to forward; right to reverse
  digitalWrite(RearLeftWheelpin1, HIGH);
  digitalWrite(RearLeftWheelpin2, LOW);
  digitalWrite(RearRightWheelpin1, LOW);
  digitalWrite(RearRightWheelpin2, HIGH);

  analogWrite(FrontLeftENA, speed);   // Send PWM to FL motor
  analogWrite(FrontRightENB, 220);  // Send PWM to FR motor
  analogWrite(RearLeftENB, speed);    // Send PWM to RL motor
  analogWrite(RearRightENA, speed);   // Send PWM to RR motor
  
  delay(time); // Run for given period of time

  // Set all motor pins to low to stop after given time 
  digitalWrite(FrontLeftWheelpin1, LOW);
  digitalWrite(FrontLeftWheelpin2, LOW);
  digitalWrite(FrontRightWheelpin1, LOW);
  digitalWrite(FrontRightWheelpin2, LOW);
  
  digitalWrite(RearLeftWheelpin1, LOW);
  digitalWrite(RearLeftWheelpin2, LOW);
  digitalWrite(RearRightWheelpin1, LOW);
  digitalWrite(RearRightWheelpin2, LOW);
}

void stopMoving() {
  digitalWrite(FrontLeftWheelpin1, LOW);
  digitalWrite(FrontLeftWheelpin2, LOW);
  digitalWrite(FrontRightWheelpin1, LOW);
  digitalWrite(FrontRightWheelpin2, LOW);

  digitalWrite(RearLeftWheelpin1, LOW);
  digitalWrite(RearLeftWheelpin2, LOW);
  digitalWrite(RearRightWheelpin1, LOW);
  digitalWrite(RearRightWheelpin2, LOW);
  delay(500);
}