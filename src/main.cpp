/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include "zirconLib.h"

double T = 0;

double U1 = 0.5;
double U2 = 0.8660254037844386467;

double V1 = 0.5;
double V2 = -0.8660254037844386467;

double W1 = -1.0;
double W2 = 0.0;

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
  double x1 = cos(T);
  double x2 = sin(T);

  double m1 = x1*U1+x2*U2;
  double m2 = x1*V1+x2*V2;
  double m3 = x1*W1+x2*W2;

  motor1(abs(m1*100), m1 < 0);
  motor2(abs(m2*100), m2 < 0);
  motor3(abs(m3*100), m3 < 0);

  T += 0.001;

  delay(1);
}
