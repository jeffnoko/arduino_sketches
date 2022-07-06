
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

AccelStepper stepper1(1, 24, 30);//X
AccelStepper stepper2(1, 25, 31);//Y
AccelStepper stepper3(1, 26, 32);//Z


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
int pos1= random(100,300);
int pos2= random(100,300);



 long positions[3];
 
 
  int x,y,z;
  int length = random(100,500);
  //float angle = 0.0;
   float angle = 0.0;
 // float angle_stepsize = PI/4;
 float angle_stepsize = 0.05;

  /// float angle = PI/2;
 // float angle_stepsize = PI/6;

float c ;//controls the rotation of the oval
float a ;//x size of oval
float b ;//y size of oval
int xPos;
int yPos;
float t = 0;//# of steps around the oval
int count= 0;
 const int zLimitSwitch = 30; 
 int zLimitSwitchReading;
 int zTouchPoint = A10;
 int zTouchPointReading;


void setup()
{
  
   Serial.begin(9600);
   
  pinMode(9, INPUT_PULLUP);


   pinMode (A13, INPUT);
    pinMode (A12, INPUT);
    pinMode (A11, INPUT);
     pinMode (A10, INPUT);
      pinMode(zLimitSwitch, INPUT_PULLUP); 
    
 pinMode (A5, INPUT_PULLUP);
  servo1.attach(52);
  servo1.write(160);
   servo2.attach(50);
  servo2.write(165);



  stepper1.setMaxSpeed(400);
  stepper1.setAcceleration(1000);
 // stepper1.moveTo(500);

  stepper2.setMaxSpeed(400);
  stepper2.setAcceleration(1000);
 // stepper2.moveTo(500);
 

  stepper3.setMaxSpeed(100);
  stepper3.setAcceleration(100);



  
  
    steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
  steppers.addStepper(stepper3);
  
    stepper1.setMaxSpeed(400);
  stepper2.setMaxSpeed(400);
 
  
 
}
//X full run is 14300  Y full run is 14600
void loop()
{
   unsigned long seed=seedOut(31);
 
 randomSeed(seed);
 /* to check random
 //c = 2;
 while (c > 1){
    //randomSeed(seed);
    c = random(1,10000);
    Serial.print("c  =   ");
   Serial.println(c);
    delay(200);
 }
 */
  t = 0;//# of steps around the oval
c = random(0,628)*.01;

  //delay(2000);
   zLimitSwitchReading = digitalRead(zLimitSwitch);
   if (count == 0){
    //Startup_BrushDip2();
  }
  count++;
//Startup_BrushDip();
  //s1up();
  delay(500);
  
 //xPos = 0;
 random(0,500);//xPos
 //yPos = 0;
 random(0,500);//yPos
 z = 30;
  //xPos = 0;//xPos
// yPos = 0;//yPos
 
  positions[0] =  xPos;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  yPos ;//stepper#2 up down
   positions[2] = z;
  steppers.moveTo(positions);
  //steppers.runSpeedToPosition();
 //s1down();
 int k;
 for(int k = 0; k< 50; k++){
 for(int i = 0; i< 5; i++){
   
    xPos = random(0,500);//xPos  
 yPos = random(0,500);//yPos
 z = 30;
  //xPos = 0;//xPos
// yPos = 0;//yPos
 
  positions[0] =  xPos;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  yPos ;//stepper#2 up down
   positions[2] = z;
  steppers.moveTo(positions);
  //steppers.runSpeedToPosition();
 //s1down();
   a = random(100,300);
   b = random(100,400);
  // c = 2;
   random(0,6.28);
   
    x = a*cos(t)*cos(c)-b*sin(t)*sin(c)+xPos;
 y = a*cos(t)*sin(c)+b*sin(t)*cos(c)+yPos;
 
 
   positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] = z;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
  //delay(3000);
  
  z = 0;
    positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] = z;
  steppers.moveTo(positions);
  //steppers.runSpeedToPosition();
  
  
   while(t < 6.50){
     /*
 if(count == 62){
   c += .1;
   a = 500;
   b = 1000;
   xPos += 200;
   yPos += 100;
   t =0;
   count = 0;
 }
 */
 x = a*cos(t)*cos(c)-b*sin(t)*sin(c)+xPos;
 y = a*cos(t)*sin(c)+b*sin(t)*cos(c)+yPos;
 
 
 
  positions[0] = x;
  positions[1] = y ;
  positions[2] = z;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
  t += .1;
  //c += .1;
 // a -= .5;
 // b -= .5;
 
  
 }
 // delay(500);
 

 x = x;
 y = y;
 z = 50;
   positions[0] =  x;
  positions[1] =  y ;
   positions[2] = z;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
 //s1Up();
 t = 0;
 //delay(500);
 }
 //BrushDip();
 } 
}
