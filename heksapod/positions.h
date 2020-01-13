#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int TOP_LEFT_FIRST = 0;
int TOP_LEFT_TWO = 1;

int TOP_RIGHT_FIRST = 2;
int TOP_RIGHT_TWO = 3;

int BOTTOM_LEFT_FIRST = 4;
int BOTTOM_LEFT_TWO = 5;

int BOTTOM_RIGHT_FIRST = 6;
int BOTTOM_RIGHT_TWO = 7;

int MAX_TWO = 200;
int MIN_TWO = 150;

int MAX_ONE = 350;
int MIN_ONE = 150;

void setServo(int port, int angle)
{
  pwm.setPWM(port, 0, angle);
}
// if from = 150 and to = 350 
void servoRotation (int port, int from, int to) {
  if (from > to) {
     for (uint16_t microsec = from; microsec > to; microsec--) {
        pwm.writeMicroseconds(port, microsec);
      }
  } else {
    for (uint16_t microsec = from; microsec < to; microsec++) {
      pwm.writeMicroseconds(port, microsec);
    }
  }
}

// left hand first
void TOP_LEFT_FIRST_MAX() {
  setServo(TOP_LEFT_FIRST, 350);
}
void TOP_LEFT_FIRST_MIN() {
  setServo(TOP_LEFT_FIRST, 150);
}

// left hand second
void TOP_LEFT_TWO_MIN() {
  setServo(TOP_LEFT_TWO, 400);
}
void TOP_LEFT_TWO_MAX() {
  setServo(TOP_LEFT_TWO, 500);
}
void TOP_LEFT_SECOND_DOWN() {
  setServo(TOP_LEFT_TWO, 300);
}

// bottom left hand
void BOTTOM_LEFT_FIRST_MAX() {
  setServo(BOTTOM_LEFT_FIRST, MIN_TWO); // 350
}
void BOTTOM_LEFT_FIRST_MIN() {
  setServo(BOTTOM_LEFT_FIRST, 350);
}

// right hand
void TOP_RIGHT_FIRST_MIN() {
  setServo(TOP_RIGHT_FIRST, 350); // 150
}
void TOP_RIGHT_FIRST_MAX() {
  setServo(TOP_RIGHT_FIRST, 150);
}

// Rignt hand second
void TOP_RIGHT_TWO_MIN() {
  setServo(TOP_RIGHT_TWO, 400);
}
void TOP_RIGHT_TWO_MAX() {
  setServo(TOP_RIGHT_TWO, 500);
}
void TOP_RIGHT_SECOND_DOWN() {
  setServo(TOP_RIGHT_TWO, 300);
}



// right Hand and two servo



// --------------------- two hand ------------
// --------------------- first hand ------------

// left Hand and first servo
// max 350
// min 150


// right Hand and first servo
// max 150
//  min 350


// bottom left Hand and one servo
// max 350
// min 150


void BOTTOM_RIGHT_FIRST_MAX() {
  setServo(BOTTOM_RIGHT_FIRST, MAX_ONE); // 350
}
void BOTTOM_RIGHT_FIRST_MIN() {
  setServo(BOTTOM_RIGHT_FIRST, MIN_ONE);
}
