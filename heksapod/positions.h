#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int TOP_LEFT_FIRST = 0;
int TOP_LEFT_TWO = 1;

int TOP_RIGHT_FIRST = 2;
int TOP_RIGHT_TWO = 3;

int BOTTOM_LEFT_FIRST = 4;
int BOTTOM_LEFT_TWO = 5;

int BOTTOM_RIGHT_FIRST = 7;
int BOTTOM_RIGHT_TWO = 8;

int MAX_TWO = 200;
int MIN_TWO = 150;

int MAX_ONE = 350;
int MIN_ONE = 150;

void setServo(int port, int angle)
{
  pwm.setPWM(port, 0, angle);
}

void TOP_LEFT_TWO_MIN() {
  setServo(TOP_LEFT_TWO, MIN_TWO);
}
void TOP_LEFT_TWO_MAX() {
  setServo(TOP_LEFT_TWO, MAX_TWO);
}
// bottom left  Hand and two servo
// max 200
// min 150
void BOTTOM_LEFT_TWO_MIN() {
  setServo(BOTTOM_LEFT_TWO, MIN_TWO);
}
void BOTTOM_LEFT_TWO_MAX() {
  setServo(BOTTOM_LEFT_TWO, MAX_TWO);
}

// right Hand and two servo
// max 200
// min 150
void TOP_RIGHT_TWO_MIN() {
  setServo(TOP_RIGHT_TWO, MIN_TWO);
}
void TOP_RIGHT_TWO_MAX() {
  setServo(TOP_RIGHT_TWO, MAX_TWO);
}

// --------------------- two hand ------------
// --------------------- first hand ------------

// left Hand and first servo
// max 350
// min 150
void TOP_LEFT_FIRST_MAX() {
  setServo(TOP_LEFT_FIRST, MAX_ONE);
}
void TOP_LEFT_FIRST_MIN() {
  setServo(TOP_LEFT_FIRST, MIN_ONE);
}

// right Hand and first servo
// max 150
//  min 350
void TOP_RIGHT_FIRST_MIN() {
  setServo(TOP_RIGHT_FIRST, MIN_ONE); // 150
}
void TOP_RIGHT_FIRST_MAX() {
  setServo(TOP_RIGHT_FIRST, MAX_ONE);
}

// bottom left Hand and one servo
// max 350
// min 150
void BOTTOM_LEFT_FIRST_MAX() {
  setServo(BOTTOM_LEFT_FIRST, MAX_ONE); // 350
}
void BOTTOM_LEFT_FIRST_MIN() {
  setServo(BOTTOM_LEFT_FIRST, MIN_ONE);
}

void BOTTOM_RIGHT_FIRST_MAX() {
  setServo(BOTTOM_RIGHT_FIRST, MAX_ONE); // 350
}
void BOTTOM_RIGHT_FIRST_MIN() {
  setServo(BOTTOM_RIGHT_FIRST, MIN_ONE);
}
