/***************************************************
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 8 servos, one after the other on the
  first 8 pins of the PCA9685

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These drivers use I2C to communicate, 2 pins are required to
  interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(&Wire, 0x40);

// Depending on your servo make, the pulse width min and max may vary, you
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN 150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600 // this is the 'maximum' pulse length count (out of 4096)

unsigned long timimmg[5];
unsigned long periodRuning;
unsigned long currentMillis;

int LEFT_HAND_FIRST = 0;
int LEFT_HAND_TWO = 1;

int RIGHT_HAND_FIRST = 2;
int RIGHT_HAND_TWO = 3;

int BOTTOM_LEFT_HAND_FIRST = 4;
int BOTTOM_LEFT_HAND_TWO = 5;

bool test[3];

// our servo # counter
uint8_t servonum = 0;

void setup()
{
    Serial.begin(9600);
    Serial.println("8 cha");

    pwm.begin();

    pwm.setPWMFreq(60); // Analog servos run at ~60 Hz updates
}

void setServo(int port, int angle)
{

    pwm.setPWM(port, 0, angle);
}

// left Hand and two Servo
void leftHandTwoUp()
{
    setServo(LEFT_HAND_TWO, 150);
}
void leftHandTwoDown()
{
    setServo(LEFT_HAND_TWO, 300);
}
// left Hand and first servo
void leftHandUp()
{
    setServo(LEFT_HAND_FIRST, 300);
}
void leftHandDown()
{
    setServo(LEFT_HAND_FIRST, 150);
}

// right Hand and first servo
void rightHandUp()
{
    setServo(RIGHT_HAND_FIRST, 150);
}
void rightHandDown()
{
    setServo(RIGHT_HAND_FIRST, 350);
}

// right Hand and two servo
void rightHandTwoUp()
{
    setServo(RIGHT_HAND_TWO, 350);
}
void rightHandTwoDown()
{
    setServo(RIGHT_HAND_TWO, 150);
}

// bottom left Hand and one servo
void bottomLeftOneServoUp()
{
    setServo(BOTTOM_LEFT_HAND_FIRST, 150);
}
void bottomLeftOneServoDown()
{
    setServo(BOTTOM_LEFT_HAND_FIRST, 150);
}
// bottom left  Hand and two servo
void bottomLeftTwoServoUp()
{
    setServo(BOTTOM_LEFT_HAND_TWO, 150);
}
void bottomLeftTwoDown()
{
    setServo(BOTTOM_LEFT_HAND_TWO, 150);
}

void delayServo(void runFunc(), int startAnimation, int endAnimation)
{
    if (periodRuning > startAnimation && periodRuning < endAnimation)
    {
        runFunc();
    }
}

void LeftHand()
{
    //  Поднять ногу в верх
    delayServo(leftHandTwoUp, 0, 1000);
    //  //  Опустить ногу в низ
    delayServo(leftHandTwoDown, 1000, 2000);
    //  Предвинуть ногу в перед
    delayServo(leftHandUp, 0, 2000);
    //  Отодвинуть ногу назад
    delayServo(leftHandDown, 2000, 4000);
}

void rightHand()
{
    //  Поднять ногу в верх
    delayServo(rightHandTwoUp, 2000, 3000);
    //  Поднять ногу в низ
    delayServo(rightHandTwoDown, 3000, 4000);
    //  Предвинуть ногу в перед
    delayServo(rightHandUp, 2000, 4000);
    //  Предвинуть ногу в назад
    delayServo(rightHandDown, 5000, 6000);
}

void leftButtonHend()
{
    delayServo(bottomLeftTwoServoUp, 2000, 3000);
    delayServo(bottomLeftTwoDown, 3000, 4000);

    delayServo(bottomLeftOneServoUp, 2000, 4000);
    delayServo(bottomLeftOneServoDown, 5000, 6000);
}

void loop()
{

    if (periodRuning < 9000)
    {
        periodRuning = periodRuning + 1;
    }
    else
    {
        periodRuning = 0;
    }
    // Left hand
    LeftHand();
    rightHand();
    leftButtonHend();
}