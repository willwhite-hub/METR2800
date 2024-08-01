#include <Arduino.h>
#include <SPI.h>
#include <drive.hpp>
#include <sensors.hpp>
#include <motors.hpp>
#include <Server.h>
#include <time.h>
#include <buzzer.hpp>
#include <TimerFreeTone.h>

bool running = true; // For exiting loop once run completed

void setup() {
  
  // Set each wheel pin as an output
  pinMode(FrontLeftWheelpin1, OUTPUT);
  pinMode(FrontLeftWheelpin2, OUTPUT);

  pinMode(FrontRightWheelpin1, OUTPUT);
  pinMode(FrontRightWheelpin2, OUTPUT);

  pinMode(RearLeftWheelpin1, OUTPUT);
  pinMode(RearLeftWheelpin2, OUTPUT);

  pinMode(RearRightWheelpin1, OUTPUT);
  pinMode(RearRightWheelpin2, OUTPUT);

  // Bucket IR sensor pin modes
  pinMode(obstaclePin1, INPUT);
  pinMode(obstaclePin2, INPUT);

  // Set pin mode for servo
  bucketServo.attach(10);

  // Set pin mode for arm-horizontal motor as output
  pinMode(horizontalMotorPin1, OUTPUT);
  pinMode(horizontalMotorPin2, OUTPUT);

  // Set pin mode for arm-vertical motor as output
  pinMode(verticalMotorPin1, OUTPUT);
  pinMode(verticalMotorPin2, OUTPUT);

  // Set pin mode for piezo buzzer
  pinMode(buzzerPin, OUTPUT); 

  // Set baud rate
  Serial.begin(9600);
}

void loop() {
  if (running) {
    /* Ball 1 */
    moveSidewaysRight(130);
    delay(220);
    stopMoving();
    bucketAngle(95);
    extendArm(5100);
    bucketAngle(80);
    delay(500);
    elevateArm(3700);
    retractArm(5000); 

    /* Ball 2 */
    while (portIR() == 0 && bucketIR2() == 0) { // Move left until edge detected or ball/tower detected
      moveSidewaysLeft(130);
    }
    if (bucketIR2() ==1) {
       stopMoving();
       delay(500);
    }
    if (bucketIR2() == 0) {
      stopMoving();
    }
    stopMoving();
    moveSidewaysLeft(130); // Do small extra move to left to align with tower
    delay(250);
    stopMoving();
    extendArm(3800);
    delay(500);
    elevateArm(2400);
    delay(300); // Pause between functions
    bucketAngle(50);
    delay(1500);
    retractArm(3800);
    bucketAngle(70);
    delay(1500);
    
    /* Ball 3 */
    while (portIR() == 0) {
      moveSidewaysLeft(130); // Move left until edge detected
    }
    if (bucketIR2() ==1) {  // Incase the edge not detected
       stopMoving();
       delay(2000);
       moveSidewaysLeft(130); 
    }
    if (bucketIR2() == 0) {
      stopMoving();
    } 
    moveForward(130);
    delay(1000);
    stopMoving();
    moveBackward(130);
    delay(520);
    stopMoving();
    moveSidewaysLeft(130);
    delay(250);
    stopMoving();
    // Pick up ball
    lowerArm(4350);
    bucketAngle(87);
    delay(1500);
    extendArm(3200);
    delay(500);
    bucketAngle(60);
    delay(1500);
    retractArm(3200);

    /* Deposit Balls */
    moveSidewaysRight(130);
    delay(550); 
    stopMoving();
    rotateLeft(2900, 130);
    delay(300); 
    moveBackward(130);
    delay(600); 
    stopMoving();
    bucketAngle(110);
    delay(2000);

    /* Setup for next 3 balls */
    bucketAngle(20);
    delay(2500);
    // Move to the wall on oppostie side of the rig
    while (pingSonarForward() > 3) { // Stop when 3cm from wall
      moveForward(130);
    }      
    stopMoving();
    moveBackward(130);
    delay(500);
    stopMoving();

    while (portIR() == 0) {
      moveSidewaysLeft(130); // Move left until edge detected
    }
    stopMoving();
    moveForward(130); // Ram wall to straighten
    delay(1000);
    stopMoving();
    moveBackward(110);
    delay(500);
    stopMoving();
    bucketAngle(90);  // Should now be lined up with next wall
    delay(2000);

    /* Ball 4 */
    moveSidewaysRight(130);
    delay(280);
    stopMoving();
    extendArm(3000);
    delay(300);
    bucketAngle(75);
    delay(500);
    retractArm(3000);

    /* Ball 5 */
     while (starboardIR() == 0 && bucketIR2() == 0) { // Check no balls or edge
      moveSidewaysRight(130);
    }

    // Line up bucket with tower
    if (bucketIR2() ==1) {  // Stop moving if ball detected
       stopMoving();
       moveSidewaysLeft(130); // Inch left to line up bucket
       delay(250);
       stopMoving();
    }
    // Pick up ball
    extendArm(3200);
    delay(300);
    bucketAngle(45);
    delay(2000);
    elevateArm(1000);
    retractArm(3500);
    bucketAngle(60);
    delay(300);
    bucketAngle(80);
    delay(2000);
    lowerArm(900);

    /* Ball 6 */
    while (starboardIR() == 0) {
      moveSidewaysRight(130); // Move sideways right until edge detected
    }
    // Rotate body to line up ball 6
    stopMoving();
    moveBackward(130);
    delay(200);
    stopMoving();
    moveSidewaysLeft(130);
    delay(300);
    stopMoving();
    rotateRight(200, 130);
    delay(300);
    bucketAngle(88);
    delay(1500);
    extendArm(3800);
    delay(500);
    bucketAngle(75);
    delay(1500);
    retractArm(3400);

    /* Deposit balls */
    moveBackward(130); // Ram into wall to straighten, as robot will be at angle
    delay(3000);
    stopMoving();
    moveSidewaysRight(130); // ALign with hole
    delay(450);
    stopMoving();
    bucketAngle(110); // Lower bucket for balls to role into hole
    delay(1500);

    /* Start of whale call sequence */
    
    // Play the first part of the whale call
    for (int i = 200; i < 400; i += 5) {
      playTone(i, 100);
    }
    
    // Short pause between segments
    delay(500);
    
    // Play the second part of the whale call
    for (int i = 400; i > 200; i -= 5) {
      playTone(i, 100);
    }

    // bucketAngle(0);
    running = false;  // Exit loop and cease all functions
  }
}
