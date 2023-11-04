/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include "zirconLib.h"

// try to move in direction of pi radians
#define X1 0.7071067811865475244
#define X2 0.7071067811865475244

#define U1 -0.8660254037844386467
#define U2 0.5

#define V1 -0.5
#define V2 -0.8660254037844386467

#define W1 1.0
#define W2 0.0

#define MOTOR1 X1*U1+X2*U2
#define MOTOR2 X1*V1+X2*V2
#define MOTOR3 X1*W1+X2*W2

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  InitializeZircon();
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);

  // wait for a second
  delay(1000);

  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);

   // wait for a second
  delay(1000);

  motor1(MOTOR1*100, 0);
  motor2(MOTOR2*100, 0);
  motor3(MOTOR3*100, 0);
}
