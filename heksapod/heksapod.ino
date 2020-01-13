#include <Wire.h>
#include "positions.h"

unsigned long periodRuning;

unsigned long speedGo = 8;
unsigned long formTime = 0;

String currentComand = "";
void setup()
{

  pwm.begin();
  pwm.setPWMFreq(50);
  Serial.begin(9600);
  Serial.print("Start program");
}

void delayServo(void runFunc(), int currentdely, int currentdely1)
{
  if (periodRuning > currentdely && periodRuning < currentdely1)
  {
    runFunc();
  }
}

void loop()
{

  if (periodRuning < formTime)
  {
    periodRuning = periodRuning + speedGo;
  }
  else
  {
    periodRuning = 0;
  }
  if (Serial.available() > 0)
  {
    currentComand = Serial.readString();
  }
  Serial.println(currentComand);
  if (currentComand.indexOf("start") > -1)
  {
    formTime = 2100;
    delayServo(TOP_LEFT_TWO_MIN, 500, 600);
    delayServo(TOP_LEFT_FIRST_MIN, 0, 500);
    delayServo(TOP_LEFT_FIRST_MAX, 500, 1000);
    delayServo(TOP_LEFT_TWO_MAX, 1000, 1100);

    delayServo(TOP_RIGHT_TWO_MIN, 1500, 1600);
    delayServo(TOP_RIGHT_FIRST_MIN, 1000, 1500);
    delayServo(TOP_RIGHT_FIRST_MAX, 1500, 2000);
    delayServo(TOP_RIGHT_TWO_MAX, 2000, 2100);

    delayServo(BOTTOM_RIGHT_FIRST_MIN, 500, 1000);
    delayServo(BOTTOM_RIGHT_FIRST_MAX, 0, 500);

    delayServo(BOTTOM_LEFT_FIRST_MAX, 1000, 1500);
    delayServo(BOTTOM_LEFT_FIRST_MIN, 1500, 2000);
  }

  if (currentComand.indexOf("read") > -1)
  {
    Serial.println("Start read");
    Serial.print("TOP_LEFT_FIRST: - ");
    Serial.println(digitalRead(TOP_LEFT_FIRST));
  }
  if (currentComand.indexOf("sDown") > -1)
  {
    TOP_LEFT_SECOND_DOWN();
    TOP_RIGHT_SECOND_DOWN();
    TOP_LEFT_FIRST_MAX();
    TOP_RIGHT_FIRST_MAX();
    BOTTOM_LEFT_FIRST_MAX();
    BOTTOM_RIGHT_FIRST_MAX();
  }
  if (currentComand.indexOf("sMin") > -1)
  {
    Serial.println("Start installation");
    TOP_LEFT_FIRST_MIN();
    TOP_LEFT_TWO_MIN();
    TOP_RIGHT_FIRST_MIN();
    TOP_RIGHT_TWO_MIN();
    BOTTOM_LEFT_FIRST_MIN();
    BOTTOM_RIGHT_FIRST_MIN();
  }
  if (currentComand.indexOf("sMax") > -1)
  {
    Serial.println("Start installation");
    TOP_LEFT_FIRST_MAX();
    TOP_LEFT_TWO_MAX();
    TOP_RIGHT_FIRST_MAX();
    TOP_RIGHT_TWO_MAX();
    BOTTOM_LEFT_FIRST_MAX();
    BOTTOM_RIGHT_FIRST_MAX();
  }
  if (currentComand.indexOf("testMax") > -1)
  {
    servoRotation(0, 0, 4000);
    delay(1000);
    servoRotation(0, 4000, 1000);
    delay(1000);
    servoRotation(0, 1000, 4000);
  }
}
