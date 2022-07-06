
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

AccelStepper stepper1(1,2,3);
AccelStepper stepper2(1,10,11);

//AccelStepper stepper1(1,2,3);   //set up the accelStepper intance, the "1" tells it we are using a driver
//AccelStepper stepper2(1,10,11);
AccelStepper stepper3(1,5,6);
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
int pos1= random(1000,8000);
int pos2= random(1000,10000);

int apple;

 long positions[3];
 
 
  int x,y;
  int length;
  //float angle = 0.0;
   float angle = 0.0;
 // float angle_stepsize = PI/4;
 float angle_stepsize = 0.05;

  /// float angle = PI/2;
 // float angle_stepsize = PI/6;



int pot1;
int pot2;
int pot3;
int pot4;
int speed1;
int counter = 0;
int z;
const int buttonPin = 28; 
int buttonState = 1;
void setup()
{
  
   Serial.begin(9600);
   
  pinMode(9, INPUT_PULLUP);
 pinMode(buttonPin, INPUT_PULLUP);     

   pinMode (A10, INPUT);
    pinMode (A11, INPUT);
    pinMode (A7, INPUT);
     pinMode (A5, INPUT);
     pinMode(24,INPUT);
    
 pinMode (A5, INPUT_PULLUP);
  servo1.attach(52);
  servo1.write(160);
   servo2.attach(50);
  servo2.write(165);



  stepper1.setMaxSpeed(1800);
  stepper1.setAcceleration(1000);
 // stepper1.moveTo(500);

  stepper2.setMaxSpeed(1800);
  stepper2.setAcceleration(1000);
 // stepper2.moveTo(500);
 

  stepper3.setMaxSpeed(1800);
  stepper3.setAcceleration(1000);



  
  
    steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
   steppers.addStepper(stepper3);
  
    stepper1.setMaxSpeed(1800);
  stepper2.setMaxSpeed(1800);
  stepper3.setMaxSpeed(1100);
 
  
 
}
//X full run is 14300  Y full run is 14600
void loop()
{
  int YellowButton = digitalRead(24);
    unsigned long seed=seedOut(31);
  Serial.print("seed = ");
  Serial.println(seed);
 randomSeed(seed);
  stepper1.setMaxSpeed(1800);//1800
  stepper1.setAcceleration(1000);
 // stepper1.moveTo(500);
   pos1= random(4000,6000);
 pos2= random(4000,10000);

  stepper2.setMaxSpeed(1800);//1800
  stepper2.setAcceleration(1000);
   stepper3.setMaxSpeed(1100);//1800
  stepper3.setAcceleration(1000);
 
   float angle1 = random(0,628)*.01;
   int mod = random(2,6);
   float angle2 = angle1 + mod;
 //Serial.print("yellowButton  =  ");Serial.println(YellowButton);//delay(2000);
  delay(2000);
   x = 0;
  y = 0;
  z = 300;
   positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
    steppers.moveTo(positions);
  steppers.runSpeedToPosition();
    int j;
  for(j = 0; j <100; j++){
     pot3 = analogRead(A1);
     
 
 
      x = pos1 + length * cos (angle1);
    y = pos2 + length * sin (angle1);
    z = 300;
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
    delay(2000);
      pos1= random(3000,7000);
 pos2= random(3000,10000);
   //delay(3000);
   x = pos1 + length * cos (angle1);
    y = pos2 + length * sin (angle1);
    z = 300;
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
 
  int counter2 = 0;
  int NumberOfSpirals = random(2,10);
   //Serial.print("NumberOfSpirals =  ");
    Serial.println(NumberOfSpirals);
while(counter2 < NumberOfSpirals){
  // angle1 = random(0,628)*.01;
  buttonState = digitalRead(buttonPin);
  if(buttonState == LOW){i = NumberOfSpirals;
 //Serial.print("hello1  ");
 
   x = pos1 + length * cos (angle1);
    y = pos2 + length * sin (angle1);
    z = 300;
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
   angle1 = random(0,628)*.01;
//delay(5000);
// Serial.print("hello2  ");
 counter2 = NumberOfSpirals;
 break;
}
//Serial.print("no  ");
  x = pos1 + length * cos (angle1);
    y = pos2 + length * sin (angle1);
    z = 300;
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
  
   stepper1.setMaxSpeed(1800);//1800
  stepper1.setAcceleration(1000);
 // stepper1.moveTo(500);

  stepper2.setMaxSpeed(1800);//1800
  stepper2.setAcceleration(1000);
   // angle1 = random(0,628)*.01;
   mod = random(2,6);
     angle2 = angle1 + mod;
 //Serial.print("angle1 =  ");Serial.println(angle1);
 // s1up();
 // delay(500);
   //pos1= random(1000,8000);
// pos2= random(1000,10000);
 // length = random(500,3200);
  pot3 = analogRead(A1);//= 
   pot3 = map(pot3,0,1023,500,5000);
   //length = pot3;
   length = random(500,3000);
   //z = 0;
    x = pos1 +  length * cos (angle1);
    y = pos2 + length * sin (angle1);
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y  ;//stepper#2 up down
   positions[2] =  z;  
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  //z = 0;
   x = pos1 +  length * cos (angle1);
    y = pos2 + length * sin (angle1);
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y  ;//stepper#2 up down
   positions[2] =  z;  
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
 
  pot1 = analogRead(A11);//= 
   pot1 = map(pot1,0,1023,0,100);
    pot2 = analogRead(A13);//= 
   pot2 = map(pot2,0,1023,0,1000);
    pot3 = analogRead(A1);//= 
   pot3 = map(pot3,0,1023,100,5000);
     pot4 = analogRead(A0);//= 
   pot4 = map(pot4,0,1023,0,100);
  while (angle1 < angle2)//#1
  { if(z > 0){z -=10;}//Serial.print("counter =  ");Serial.println(counter);
   // YellowButton = digitalRead(24);
  // Serial.print("yellowButton  =  ");Serial.println(YellowButton);//delay(2000);
    speed1 = analogRead(A3);
    speed1 = map(speed1,0,1023,0,1800);
   // length = analogRead(A1);
    pot4 = analogRead(A0);//= 
   pot4 = map(pot4,0,1023,0,100);
    
  stepper1.setMaxSpeed(speed1);//1800
  stepper1.setAcceleration(1000);
 // stepper1.moveTo(500);

  stepper2.setMaxSpeed(speed1);//1800
  stepper2.setAcceleration(1000);
    //calculate x , y from a vector with known length and angle
    x = pos1 +  length * cos (angle1);
    y = pos2 + length * sin (angle1);
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y  ;//stepper#2 up down
   positions[2] =  z;  
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
    if(counter >=100){z += 5;}

    
    angle1 += angle_stepsize;
   
  length = length - (length/pot4);
 
 counter++;
// counter2++;
   }
   counter2++;
   counter = 0;
  
}   
}

  
}
