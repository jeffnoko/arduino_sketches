

#include <AccelStepper.h>
#include <Servo.h>
#include <Rotary.h>


AccelStepper stepper1(1, 24, 30);//X
AccelStepper stepper2(1, 25, 31);//Y
AccelStepper stepper3(1, 26, 32);//Z


//steppers
#define JOYSTICK_PIN1 A7
#define JOYSTICK_PIN2 A8
#define MAX_SPEED 500
#define INPUT_READ_INTERVAL 0//100
unsigned long last_input_time = 0;
//===========================================
Servo servo1;
Servo servo2;
Servo servo3;

#define JOYSTICK_PIN3 A5//servo
#define JOYSTICK_PIN4 A4//servo

//pots
int pot1 = A0;
int pot2 = A1;
int pot3 = A2;
int pot4 = A3;


int pot1Value;
int pot2Value;
int pot3Value;
int pot4Value;

int minDegrees;
int maxDegrees;
int slowInterval;
int fastInterval;

const int servo1MinDegrees = 50;
const int servo1MaxDegrees = 100;
const int servo2MinDegrees = 130;
const int servo2MaxDegrees = 160;
const int servo3MinDegrees = 20;
const int servo3MaxDegrees = 50;

int servo1Pos = 50;     // the current angle of the servo - starting at 50.
int servo1SlowInterval = 80; // millisecs between servo moves
int servo1FastInterval = 10;
int servo1Interval = servo1SlowInterval; // initial millisecs between servo moves
int servo1Degrees = 3;       // amount servo moves at each step

int servo2Pos = 130;     // the current angle of the servo - starting at 130.
int servo2SlowInterval = 80; // millisecs between servo moves
int servo2FastInterval = 10;
int servo2Interval = servo2SlowInterval; // initial millisecs between servo moves
int servo2Degrees = 3;       // amount servo moves at each step

int servo3Pos = 20;     // the current angle of the servo - starting at 20.
int servo3SlowInterval = 300; // millisecs between servo moves
int servo3FastInterval = 30;
int servo3Interval = servo3SlowInterval; // initial millisecs between servo moves
int servo3Degrees = 3;       // amount servo moves at each step
//..................................................................................................

unsigned long currentMillis1 = 0;    // stores the value of millis() in each iteration of loop()
unsigned long currentMillis2 = 0;    // stores the value of millis() in each iteration of loop()
unsigned long currentMillis3 = 0;    // stores the value of millis() in each iteration of loop()


unsigned long previousServo1Millis = 0; // the time when the servo was last moved
unsigned long previousServo2Millis = 0; // the time when the servo was last moved
unsigned long previousServo3Millis = 0; // the time when the servo was last moved
/*
//=================pump
int speed1;
int speedPin = 4;//enable pin  #1 on l293d chip
int direction1 = 5;// #2 on chip
int direction2 = 6; // #7 on chip
int button1 = 36;
int potentiometer = A6;
//====================================
*/
int buttonState1;
int counter1 = 0;

//encoder
Rotary rotary = Rotary(2, 3);
volatile int counter2 = 0;

int buttonState2;
int button2 = 12;
int buttonState3;
int button3 = 14;

//=========================
long zCurrentPos;
int newZReading;
int previousZReading;
//=========================
int enablePin;

void setup()
{
  Serial.begin(9600);


  stepper1.setMaxSpeed(500);//500
  stepper1.setAcceleration(1000);
  stepper2.setMaxSpeed(300);//500
  stepper2.setAcceleration(500);
  stepper3.setMaxSpeed(1000);//500
  stepper3.setAcceleration(2000);

  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);

  servo1.write(50);    // 50-100
  servo2.write(140);  //140 - 170
  servo3.write(20); //20 -70

  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(pot3, INPUT);
  pinMode(pot4, INPUT);

  pinMode(button2,INPUT_PULLUP);
   pinMode(button3,INPUT_PULLUP);

/*  //======================pumpStart
  pinMode(speedPin, OUTPUT);
  pinMode(direction1, OUTPUT);
  pinMode(direction2, OUTPUT);
  pinMode(speedPin, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

  //======================pumpEnd
*/
  attachInterrupt(0, rotate, CHANGE);//pin2
  attachInterrupt(1, rotate, CHANGE);//pin3

  stepper3.setCurrentPosition(0);


}

void loop()
{

  setZ0();
 // zLift();
 zLiftV2();

  joystickXY();
  joystickPanTilt2();
/*
  buttonState2 = digitalRead(button2);
  if (buttonState2 == LOW) {
    counter2 = 0;

  }
  */
//Serial.println(buttonState3);
  stepper1.run();
  stepper2.run();
   stepper3.run();
}


 
