

#include <AccelStepper.h>
#include <MultiStepper.h>
#include <Servo.h>
#include <Rotary.h>


AccelStepper stepper1(1, 24, 30);//X
AccelStepper stepper2(1, 25, 31);//Y
AccelStepper stepper3(1, 26, 32);//Z

MultiStepper steppers;

long positions[3];

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
int pot5 = A10;
int pot6 = A11;
int pot7 = A12;


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
const int servo3MaxDegrees = 40;

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
int servo3SlowInterval = 100; // millisecs between servo moves
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
//====================
int servo1Stop = servo1Interval + 2000;
//===========================
//=========********circle variables START************=============
 int centerX = 0;
 int centerY = 0;
 float tau = 6.28;
 int x,y,z;
 int lengthX = 200;//random(300,1000);
 int lengthY = 200;
  float angle = 0.0;
   //float angle = 2*PI/4;
 // float angle_stepsize = PI/4;
 float angle_stepsize = 0.05;
 float circleXInterval = 20;
 float circleYInterval = 5;
 bool circleIntervalState;
 float speed2 = .5;
 float circleDegrees = .5;
 unsigned long currentMillis4;
 unsigned long previousMillis4 = 0;
 unsigned long currentMillis5;
 unsigned long previousMillis5 = 0;
 
//=========********circle variables END************=============
//============BlinkWithoutDelay======start==============
const int ledPin =  LED_BUILTIN;
int ledState = LOW;  
unsigned long previousMillis = 0;
int interval;  
//====================================end===========
 bool counter = true;
 int A = -500;
 int B = 0;
//*****************************RGB
// const int pot1 = A0;//R
/*
int speed1;
float RGB1[3];
float RGB2[3];
float INC[3];
int red, green, blue;
int RedPin = 3;
int GreenPin = 5;
int BluePin = 6;
*/
//****************************
//**********RGB Blink
  int speed1;
float RGB1[3];
float RGB2[3];
float INC[3];
int red, green, blue;
int RedPin = 44;// 3 on Uno 44 on Mega
int GreenPin = 45;// 5 on Uno 45 on Mega
int BluePin = 46;// 6 on Uno 46 on Mega
//const int pot1 = A0;//R
//const int pot2 = A1;//G
//const int pot3 = A2;//B
int inputVal1 = 0;
int inputVal2 = 0;
int inputVal3 = 0;

 


void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));

  steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
   steppers.addStepper(stepper3);



  stepper1.setMaxSpeed(500);//500
  stepper1.setAcceleration(1000);
  stepper2.setMaxSpeed(500);//500
  stepper2.setAcceleration(500);
  stepper3.setMaxSpeed(100);//500
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
  pinMode(pot5, INPUT);
  pinMode(pot6, INPUT);
  pinMode(pot7, INPUT);


  pinMode(button2,INPUT_PULLUP);
   pinMode(button3,INPUT_PULLUP);
   // pinMode(LED_BUILTIN, OUTPUT);
     pinMode(ledPin, OUTPUT);



  attachInterrupt(0, encoder1, CHANGE);//pin2
  attachInterrupt(1, encoder1, CHANGE);//pin3

  stepper3.setCurrentPosition(0);
  
z = 0;
 //stepper3.moveTo(-500);
 RGB1[0] = 0;
RGB1[1] = 0;
RGB1[2] = 0;
RGB2[0] = random(256);
RGB2[1] = random(256);
RGB2[2] = random(256);
inputVal1 = analogRead(pot1);
  inputVal2 = analogRead(pot2);
  inputVal3 = analogRead(pot3);
delay(2000);
}

void loop()
{//int step3Pos = stepper3.currentPosition();
//Serial.print("step3Pos = ");Serial.println(step3Pos);
  //int potTest = analogRead(A12);
  //Serial.println(potTest);
  //blink1();
  //zBounce();
  //analogWrite(LED_BUILTIN, 40); 
 // joystickPanTilt2();
//joystickXY(); 
  //test2();
  //circle1();
  //circle2();
  //circle3();
//test3();
  //setZ0();
//mode1();
 RGBBlink();
mode2();
//mode3();
//servoSweep1();
//Serial.println("loop");
   //stepper1.run();
  //stepper2.run();
   //  stepper3.run();
}


 
