/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include "zirconLib.h"
#include "Movement.hpp"
// #include "Positioning.hpp"
// using Movement::Positioning::vector2;
// using Movement::Positioning::getPosition;

double T = 0;

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  InitializeZircon();
  Serial.begin(9600);
}

void loop()
{
  // moveInDirection(T);

  // T += 0.001;
  vector2 p = getPosition().normalize();
  // Serial.printf("%f, %f\n", p.x, p.y);
  Movement::moveInDirection(p);

  // motor2(100, 1);

  delay(1);
}
