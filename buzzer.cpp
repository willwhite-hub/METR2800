/* 
*
* buzzer.hpp
*
* Function for the piezo buzzer whale call.
*/

#include <Arduino.h>
#include <buzzer.hpp>
#include <TimerFreeTone.h>

void playTone(int frequency, int duration) {
  TimerFreeTone(buzzerPin, frequency, duration);
  delay(duration);
}