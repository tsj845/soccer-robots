/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include "zirconLib.h"

double X1 = 0.707;
double X2 = 0.707;

double U1 = 0.5;
double U2 = 0.8660254037844386467;

double V1 = 0.5;
double V2 = -0.8660254037844386467;

double W1 = -1.0;
double W2 = 0.0;

double MOTOR1 = X1*U1+X2*U2;
double MOTOR2 = X1*V1+X2*V2;
double MOTOR3 = X1*W1+X2*W2;

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
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);

  // wait for a second
  delay(1000);

  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);

   // wait for a second
  delay(1000);

  // Serial.println(X1);
  // Serial.println(X2);
  // Serial.println();
  // Serial.println(U1);
  // Serial.println(U2);
  // Serial.println();
  // Serial.println(V1);
  // Serial.println(V2);
  // Serial.println();
  // Serial.println(W1);
  // Serial.println(W2);
  // Serial.println();
  // Serial.println(MOTOR1*255);
  // Serial.println(MOTOR2*255);
  // Serial.println(MOTOR3*255);
  // Serial.println();

  // motor1(50, 0);
  // motor2(25, 1);
  // motor3(25, 1);

  // motor2(255,0);

  motor1(abs(MOTOR1*100), MOTOR1 < 0);
  motor2(abs(MOTOR2*100), MOTOR2 < 0);
  motor3(abs(MOTOR3*100), MOTOR3 < 0);
}
