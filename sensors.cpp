/*
* sensors.cpp
*
* This is where functionality related to the sensors is found.
*/

#include <Arduino.h>
#include <sensors.hpp>
#include <NewPing.h>

// Setup pins and max distance for the sonar ping
NewPing sonar(triggerPin, echoPin, maxDist);

long duration;
int distance;

// int hasBallIR1 = LOW;
// int hasBallIR2 = HIGH;

int hasBallIR1 = HIGH;
int hasBallIR2 = HIGH;
int starboardEdgeAlert = HIGH;
int portEdgeAlert = HIGH;

int pingSonarForward() {
    delay(10); // Wait 30ms between pings 

    int distance = sonar.ping_cm(); // Send ping and get distance (cm)
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm ");
    return(distance);
}

int bucketIR1() {  
    delay(10); // Wait 30ms between pings
    hasBallIR1 = digitalRead(obstaclePin1);
    if (hasBallIR1 == LOW) {
        Serial.print("Sensor 1: Ball ");
        return 1;
    } else {
        return 0;
    }
}

int bucketIR2() {  
    delay(5); // Wait 30ms between pings
    hasBallIR2 = digitalRead(obstaclePin2);
    if (hasBallIR2 == LOW) {
        Serial.print("Sensor 2: Ball");
        return 1;
    } else {
        return 0;
    }
}

int portIR() {
  delay(5); // Wait 30ms between pings

    portEdgeAlert = digitalRead(portPin);
    if (portEdgeAlert == HIGH) {
        Serial.print("Port: edge detected ");
        return 1;
    } else {
        return 0;
    }
}

int starboardIR() {
  delay(5); // Wait 30ms between pings

    starboardEdgeAlert = digitalRead(starboardPin);
    if (starboardEdgeAlert == HIGH) {
        Serial.print("Starboard: edge detected ");
        return 1;
    } else {
        return 0;
    }
}

