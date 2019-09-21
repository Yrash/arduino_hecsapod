#include <Wire.h>

#include "positions.h"

unsigned long periodRuning;


void setup()
{
    pwm.begin();
    pwm.setPWMFreq(60);
}

void delayServo(void runFunc(), int currentdely, int currentdely1) {
  if (periodRuning > currentdely && periodRuning < currentdely1) {
    runFunc();
  }
}

void LeftHand() {
    //  Поднять ногу в верх
    delayServo(TOP_LEFT_TWO_MIN, 0, 1000);
    //  //  Опустить ногу в низ
    delayServo(TOP_RIGHT_TWO_MAX, 1000, 2000);
    //  Предвинуть ногу в перед
    delayServo(TOP_LEFT_FIRST_MAX, 0, 2000);
    //  Отодвинуть ногу назад
    delayServo(TOP_LEFT_FIRST_MIN, 2000, 4000);
}

void rightHand() {
    //  Поднять ногу в верх
    delayServo(TOP_RIGHT_TWO_MIN, 4000, 5000);
    //  Поднять ногу в низ
    delayServo(TOP_RIGHT_TWO_MAX, 5000, 6000);
    //  Предвинуть ногу в перед
    delayServo(TOP_RIGHT_FIRST_MIN, 4000, 6000);
    //  Предвинуть ногу в назад
    delayServo(TOP_RIGHT_FIRST_MAX, 6000, 8000);
}

void leftButtonHand() {
    delayServo(BOTTOM_LEFT_TWO_MIN, 8000, 9000);
    delayServo(BOTTOM_LEFT_TWO_MAX, 9000, 10000);

    delayServo(BOTTOM_LEFT_FIRST_MAX, 8000, 10000);
    delayServo(BOTTOM_LEFT_FIRST_MIN, 10000, 12000);
}

void runToForward() {
        //  Поднять ногу в верх
    delayServo(TOP_LEFT_TWO_MIN, 0, 1000);
    //  //  Опустить ногу в низ
    delayServo(TOP_RIGHT_TWO_MAX, 1000, 2000);

      //  Предвинуть ногу в перед
    delayServo(TOP_LEFT_FIRST_MAX, 0, 2000);
    //  Отодвинуть ногу назад
    delayServo(TOP_LEFT_FIRST_MIN, 2000, 4000);




    delayServo(BOTTOM_LEFT_TWO_MIN, 8000, 9000);
    delayServo(BOTTOM_LEFT_TWO_MAX, 9000, 10000);

    delayServo(BOTTOM_LEFT_FIRST_MAX, 8000, 10000);
    delayServo(BOTTOM_LEFT_FIRST_MIN, 10000, 12000);

        //  Поднять ногу в верх
    delayServo(TOP_RIGHT_TWO_MIN, 4000, 5000);
    //  Поднять ногу в низ
    delayServo(TOP_RIGHT_TWO_MAX, 5000, 6000);

          //  Предвинуть ногу в перед
    delayServo(TOP_RIGHT_FIRST_MIN, 4000, 6000);
    //  Предвинуть ногу в назад
    delayServo(TOP_RIGHT_FIRST_MAX, 6000, 8000);
      //  Предвинуть ногу в перед
      

      
}

void loop()
{
    
    if (periodRuning < 12000)
    {
        periodRuning = periodRuning + 1;
    }
    else
    {
        periodRuning = 0;
    }
    // Left hand
    // LeftHand();
    // rightHand();
    // leftButtonHand();
}
