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

unsigned long periodRuning;

int LEFT_HAND_FIRST = 0;
int LEFT_HAND_TWO = 1;

int RIGHT_HAND_FIRST = 2;
int RIGHT_HAND_TWO = 3;

int BOTTOM_LEFT_HAND_FIRST = 4;
int BOTTOM_LEFT_HAND_TWO = 5;

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

// --------------------- two hand ------------
// left Hand and two Servo
// max 200
//  min 150
int maxTwoHand = 200;
int minTwoHand = 150;

void leftHandTwoUp()
{

    setServo(LEFT_HAND_TWO, maxTwoHand);
}
void leftHandTwoDown()
{
    setServo(LEFT_HAND_TWO, minTwoHand);
}
// bottom left  Hand and two servo
// max 200
//  min 150
void bottomLeftTwoServoUp()
{
    setServo(BOTTOM_LEFT_HAND_TWO, maxTwoHand);
}
void bottomLeftTwoDown()
{
    setServo(BOTTOM_LEFT_HAND_TWO, minTwoHand);
}

// right Hand and two servo
// max 200
//  min 150
void rightHandTwoUp()
{
    setServo(RIGHT_HAND_TWO, maxTwoHand);
}
void rightHandTwoDown()
{
    setServo(RIGHT_HAND_TWO, minTwoHand);
}

// --------------------- two hand ------------
// --------------------- first hand ------------

// left Hand and first servo
// max 350
//  min 150
void leftHandUp()
{
    setServo(LEFT_HAND_FIRST, 350);
}
void leftHandDown()
{
    setServo(LEFT_HAND_FIRST, 150);
}

// right Hand and first servo
// max 150
//  min 350
void rightHandUp()
{
    setServo(RIGHT_HAND_FIRST, 150); // 150
}
void rightHandDown()
{
    setServo(RIGHT_HAND_FIRST, 350);
}

// bottom left Hand and one servo
// max 350
//  min 150
void bottomLeftOneServoUp()
{
    setServo(BOTTOM_LEFT_HAND_FIRST, 350); // 350
}
void bottomLeftOneServoDown()
{
    setServo(BOTTOM_LEFT_HAND_FIRST, 150);
}
// --------------------- first hand ------------

void delyServo(void runFunc(), int currentdely, int currentdely1)
{
    if (periodRuning > currentdely && periodRuning < currentdely1)
    {
        runFunc();
    }
}

void LeftHand()
{
    //  Поднять ногу в верх
    delyServo(leftHandTwoUp, 0, 1000);
    //  //  Опустить ногу в низ
    delyServo(leftHandTwoDown, 1000, 2000);
    //  Предвинуть ногу в перед
    delyServo(leftHandUp, 0, 2000);
    //  Отодвинуть ногу назад
    delyServo(leftHandDown, 2000, 4000);
}

void rightHand()
{
    //  Поднять ногу в верх
    delyServo(rightHandTwoUp, 4000, 5000);
    //  Поднять ногу в низ
    delyServo(rightHandTwoDown, 5000, 6000);
    //  Предвинуть ногу в перед
    delyServo(rightHandUp, 4000, 6000);
    //  Предвинуть ногу в назад
    delyServo(rightHandDown, 6000, 8000);
}

void leftButtonHand()
{
    delyServo(bottomLeftTwoServoUp, 8000, 9000);
    delyServo(bottomLeftTwoDown, 9000, 10000);

    delyServo(bottomLeftOneServoUp, 8000, 10000);
    delyServo(bottomLeftOneServoDown, 10000, 12000);
}

void loop()
{

    if (periodRuning < 12000)
    {
        periodRuning = periodRuning + 2;
    }
    else
    {
        periodRuning = 0;
    }
    // Left hand
    LeftHand();
    rightHand();
    leftButtonHand();
}