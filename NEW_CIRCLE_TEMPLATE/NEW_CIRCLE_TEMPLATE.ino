
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

//AccelStepper stepper1(1,51,50);
//AccelStepper stepper2(1,53,52);
//AccelStepper stepper3(1,47,46);
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
 float voltageS = 7;
 float voltageT = 9;
  float voltageU = 10;
   float voltageV = 11;
int i = 0;
int pos = 130;
int currentpos = 0;
int pos1=0;// random(500,800);
int pos2=0;// random(500,800);



 long positions[2];
 
 
  int x,y;
  int length = 200;//random(300,1000);
  //float angle = 0.0;
   float angle = 2*PI/4;
 // float angle_stepsize = PI/4;
 float angle_stepsize = 0.05;

  /// float angle = PI/2;
 // float angle_stepsize = PI/6;



 const int zLimitSwitch = 30; 
 int zLimitSwitchReading;
 int zTouchPoint = A10;
 int zTouchPointReading;


void setup()
{
  
   Serial.begin(9600);
   
  pinMode(9, INPUT_PULLUP);


   pinMode (A10, INPUT);
    pinMode (A11, INPUT);
    pinMode (A7, INPUT);
     pinMode (A5, INPUT);
    
 pinMode (A5, INPUT_PULLUP);
  servo1.attach(52);
  servo1.write(160);
   servo2.attach(50);
  servo2.write(165);



  stepper1.setMaxSpeed(500);
  stepper1.setAcceleration(1000);
 // stepper1.moveTo(500);

  stepper2.setMaxSpeed(300);
  stepper2.setAcceleration(1000);
 // stepper2.moveTo(500);
 

  stepper3.setMaxSpeed(100);
  stepper3.setAcceleration(100);



  
  
    steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
   steppers.addStepper(stepper3);
  
   // stepper1.setMaxSpeed(800);
 // stepper2.setMaxSpeed(800);
  // stepper3.setMaxSpeed(100);
 
  
 
}
//X full run is 14300  Y full run is 14600
void loop()
{
    unsigned long seed=seedOut(31);
  Serial.print("seed = ");
  Serial.println(seed);
 randomSeed(seed);
  delay(1000);
  Startup_BrushDip();
for(i = 0; i <2; i++){
  
  delay(500);
  // pos1= 0;//random(400,500);
 //pos2=0;// random(400,500);
  length = 200;//random(100,1200);
  // positions[0] =  pos1;//(g2 - random(-100,100) );//stepper#1  horizontal
 // positions[1] =  pos2 ;//stepper#2 up down
 // steppers.moveTo(positions);
 // steppers.runSpeedToPosition();
 // delay(2000);
 // int x,y;
 // int length = 3000;
 // float angle = 0.0;
 // float angle_stepsize = 0.1;
  
  //go through all angles from 0 to 2 * PI radians
  // x = pos1 + .937 * length * cos (angle);
    x = pos1 + length * cos (angle);
    y = pos2 + length * sin (angle);
    int z = 0;
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] = z;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
    z = 0;
      x = pos1 + length * cos (angle);
    y = pos2 + length * sin (angle);
   
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] = z;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
    // positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  //positions[1] =  y ;//stepper#2 up down
 //  positions[2] = z;
 // steppers.moveTo(positions);
 // steppers.runSpeedToPosition();
// s1down();
delay(1000);
  while (angle <  PI/.65)
  {
    
    //calculate x , y from a vector with known length and angle
   // x = pos1 + .937 * length * cos (angle);
     x = pos1 + length * cos (angle);
    y = pos2 + length * sin (angle);
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y  ;//stepper#2 up down
   positions[2] = z;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
    
    // for Processing  
    // putpixel (screen, x + SCREEN_W / 2, y + SCREEN_H / 2,
    // makecol (255, 255, 255));
    
    angle += angle_stepsize;
   
  
 
   }
   
   angle = 2*PI/4;
   pos2 = pos2 - 400;
     x = pos1 + length * cos (angle);
    y = pos2 + length * sin (angle);
     z = 0;
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] = z;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  delay(1000);
  while (angle <  PI/.65)
  {
    z = 0;
    //calculate x , y from a vector with known length and angle
   // x = pos1 + .937 * length * cos (angle);
     x = pos1 + length * cos (angle);
    y = pos2 + length * sin (angle);
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y  ;//stepper#2 up down
   positions[2] = z;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
    
    // for Processing  
    // putpixel (screen, x + SCREEN_W / 2, y + SCREEN_H / 2,
    // makecol (255, 255, 255));
    
    angle += angle_stepsize;
   
  
 
   }
}
   
   
   /* for a spiral
    //go through all angles from 0 to 2 * PI radians
   for(int i = 0; i < 5; i++){
  while (angle < 2 * PI)
  {
    //calculate x , y from a vector with known lenght and angle
    x = length * cos (angle);
    y = length * sin (angle);
    
    
   positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
    
    // for Processing  
    // putpixel (screen, x + SCREEN_W / 2, y + SCREEN_H / 2,
    // makecol (255, 255, 255));
    
    angle += angle_stepsize;
    length = length - 20;
  }
  angle = 0.0;
   }
   */
  
}
