
#include<AccelStepper.h>
#include <MultiStepper.h>
#include <Servo.h> 

MultiStepper steppers;



Servo servo1; 
Servo servo2; 
const int analogInPin1 = A1;  // Analog input pin that the potentiometer is attached to
const int analogInPin2 = A2;  // Analog input pin that the potentiometer is attached to
int sensorValue1 = 0;        // value read from the pot
int sensorValue2 = 0;        // value read from the pot
int outputValue1 = 0;        // value output to the PWM (analog out)
int outputValue2 = 0;        // value output to the PWM (analog out)

AccelStepper stepper1(1,51,50);
AccelStepper stepper2(1,53,52);

//AccelStepper stepper1(1,2,3);   //set up the accelStepper intance, the "1" tells it we are using a driver
//AccelStepper stepper2(1,10,11);
AccelStepper stepper3(1,47,46);
volatile int state = LOW;
 int stepper1TotalSteps = 0;
 int stepper2TotalSteps = 0;
 int stepper1Steps;
 int stepper2Steps;
 
 int POTs;
  int POTu;
   int POTt;
   int POTv;
 int voltageS = 13;
 float voltageT = 12;
  float voltageU = 11;
   float voltageV = 10;
int i = 0;
int pos = 130;
int currentpos = 0;
int pos1= random(500,1000);
int pos2= random(500,1000);



 long positions[3];
 
 
  int x,y;
  int length = random(300,500);
  //float angle = 0.0;
   float angle = 0.0;
 // float angle_stepsize = PI/4;
 float angle_stepsize = 0.05;

  /// float angle = PI/2;
 // float angle_stepsize = PI/6;

float c = 2;
float a = 500;
float b = 1000;
int h,k,j;

float t = 0;
int count= 0;



void setup()
{
  
   Serial.begin(9600);
   
  pinMode(9, INPUT_PULLUP);


   pinMode (A13, INPUT);
    pinMode (A12, INPUT);
    pinMode (A11, INPUT);
     pinMode (A10, INPUT);
    
 pinMode (A5, INPUT_PULLUP);
  servo1.attach(52);
  servo1.write(160);
   servo2.attach(50);
  servo2.write(165);



  stepper1.setMaxSpeed(800);
  stepper1.setAcceleration(1000);
 // stepper1.moveTo(500);

  stepper2.setMaxSpeed(800);
  stepper2.setAcceleration(1000);
 // stepper2.moveTo(500);
 

  stepper3.setMaxSpeed(100);
  stepper3.setAcceleration(200);



  
  
    steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
  steppers.addStepper(stepper3);
  
    stepper1.setMaxSpeed(800);
  stepper2.setMaxSpeed(800);
   stepper3.setMaxSpeed(100);
 
  
 
}
//X full run is 14300  Y full run is 14600
void loop()
{ 
  delay(2000);

  //s1up();
  delay(500);
   unsigned long seed=seedOut(31);
 
   delay(500);
 randomSeed(seed);
  Serial.print("seed = ");
  Serial.println(seed);
   delay(500);
 h = 0;
 k = 0;
 j = 100;
 
  positions[0] =  h;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  k ;//stepper#2 up down
   positions[2] =  j ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
// s1down();
 for(int i = 0; i< 10; i++){
    h = random(200,500);
 k = random(200,500);
   while(t < 6.28){
 if(count == 62){
   c += .1;
   a = 500;
   b = 1000;
   h += 200;
   k += 100;
   t =0;
   count = 0;
 }
 
 x = a*cos(t)*cos(c)-b*sin(t)*sin(c)+h;
 y = a*cos(t)*sin(c)+b*sin(t)*cos(c)+k;
 
   positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  j ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
 //  h = random(2000,5000);
// k = random(2000,5000);
 j = 0;
   //s1down();
  count++;
  t += .1;
  a -= .5;
  b -= .5;
  //Serial.print("count = ");Serial.println(count);
  //Serial.print("t = ");Serial.println(t);
 }
// s1down();
 }
  
}
