/* 
*
* buzzer.hpp
*
* Function definition for the piezo buzzer whale call.
*/

#ifndef BUZZER_HPP
#define BUZZER_HPP
#include <TimerFreeTone.h>
#include <Arduino.h>

// Define the pin for the piezo buzzer
const byte buzzerPin = 11;

// Function to play a tone for a certain duration
void playTone(int frequency, int duration);

#endif