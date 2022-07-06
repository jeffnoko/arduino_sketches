
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

AccelStepper stepper1(1,51,50);//x
AccelStepper stepper2(1,53,52);//y
AccelStepper stepper3(1,47,46);//z

volatile int state = LOW;
 int stepper1TotalSteps = 0;
 int stepper2TotalSteps = 0;
 int stepper1Steps;
 int stepper2Steps;
 
 int POTs;
  int POTu;
   int POTt;
   int POTv;
 float voltageS = A12;
 float voltageT = A10;
  float voltageU = A0;
   float voltageV = A3;
int i = 0;
int pos = 130;
int currentpos = 0;
int pos1= random(500,1000);
int pos2= random(500,1000);



 long positions[3];
 
 
  int x,y;
  int length;
 
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
const int buttonPin = 24; 
int buttonState = 1;
 const int zLimitSwitch = 30; 
 int zLimitSwitchReading;
 int zTouchPoint = A10;
 int zTouchPointReading;
void setup()
{
  
   Serial.begin(9600);
   
  pinMode(9, INPUT_PULLUP);
 pinMode(buttonPin, INPUT_PULLUP); 
 pinMode(zLimitSwitch, INPUT_PULLUP);  

   pinMode (A12, INPUT);
    pinMode (zTouchPoint, INPUT);
    pinMode (A0, INPUT);
     pinMode (A3, INPUT);
    // pinMode(24,INPUT);
    
 pinMode (A5, INPUT_PULLUP);
 // servo1.attach(10);
 // servo1.write(50);
  // servo2.attach(30);
 // servo2.write(165);

 steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
   steppers.addStepper(stepper3);
  
    stepper1.setMaxSpeed(800);
  stepper2.setMaxSpeed(800);
  stepper3.setMaxSpeed(50);
 
  
 
}
//X full run is ?  Y full run is ?
void loop()
{
  //int YellowButton = digitalRead(24);
    unsigned long seed=seedOut(31);
 
 randomSeed(seed);
 delay(100);
 int f = 1;
 /*
 while(f > 0){
   zTouchPointReading = analogRead(zTouchPoint);
  // zTouchPointReading = map(zTouchPoint,0,1023,0,10);
   delay(10);
   
  Serial.print("zTouchPoint  =   ");
   Serial.println(zTouchPointReading);
 }
 */
  stepper1.setMaxSpeed(800);//1800
  stepper1.setAcceleration(1000);

  // pos1= random(300,800);
 //pos2= random(300,800);
  pos1= random(0,500);
 pos2= random(0,500);
  Serial.print("pos1  =   ");
   Serial.println(pos1);
    Serial.print("pos2  =   ");
   Serial.println(pos2);

  stepper2.setMaxSpeed(800);//1800
  stepper2.setAcceleration(1000);
   stepper3.setMaxSpeed(50);//1800
  stepper3.setAcceleration(100);
  
   float angle1 = random(0,628)*.01;
   int mod = random(2,6);
   float angle2 = angle1 + mod;
Startup_BrushDip();
//alphabete();
int g;
int gtimes = random(2,10);
//for(g= gtimes; g<10; g++){
//clockwise_square();
//}
    int j;
  for(j = 0; j <100; j++){/////////////////////for1///
     //pot3 = analogRead(A1);
  //stepper3.setMaxSpeed(100);
  //  zLimitSwitchReading = digitalRead(zLimitSwitch);
   x = 0;
   y = 0;
     // x = pos1 + length * cos (angle1);
   // y = pos2 + length * sin (angle1);
   /*
    z = 20;
     positions[0] =  x;
  positions[1] =  y ;
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
    delay(200);
    */
     // pos1= random(300,800);
// pos2= random(300,800);
// unsigned long seed=seedOut(31);
// randomSeed(seed);
 pos1= random(0,500);
 pos2= random(0,500);
 /*
    Serial.print("pos1.1  =   ");
   Serial.println(pos1);
    Serial.print("pos2.1  =   ");
   Serial.println(pos2);
   x = pos1 + length * cos (angle1);
    y = pos2 + length * sin (angle1);
    z = 30;
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
   */
 // steppers.moveTo(positions);
 // steppers.runSpeedToPosition();
// delay(5000);
gtimes = random(2,10);
 for(g= gtimes; g<10; g++){
clockwise_square();
}
  int counter2 = 0;
 
   int NumberOfSpirals = random(2,5);
  
  
while(counter2 < NumberOfSpirals){///////////////////////////while1  number of spirals

// for(g= gtimes; g<10; g++){
//clockwise_square();
//}
  buttonState = digitalRead(buttonPin);
  
  if(buttonState == LOW){//////////////if1//////
   
   x = pos1 + length * cos (angle1);
    y = pos2 + length * sin (angle1);
    z = 30;
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
   angle1 = random(0,628)*.01;

 counter2 = NumberOfSpirals;
 break;
}//...................................................if1...........

  //x = pos1 + length * cos (angle1);
  //  y = pos2 + length * sin (angle1);
    z = 30;
     positions[0] =  x;
  positions[1] =  y ;
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();// raise the z
  
  
  
  
  // stepper1.setMaxSpeed(800);//1800
 // stepper1.setAcceleration(800);


 // stepper2.setMaxSpeed(800);//1800
 // stepper2.setAcceleration(1000);
  
   mod = random(2,6);
     angle2 = angle1 + mod;
 
  pot1 = analogRead(A12);//= 
   pot1 = map(pot3,0,1023,200,3000);
   length = pot1;
   Serial.print("pot3 =   ");
   Serial.println(pot3);
   length = random(500,2000);
    Serial.print("length1  =   ");
   Serial.println(length);
   
    x = pos1 +  length * cos (angle1);
    y = pos2 + length * sin (angle1);
     positions[0] =  x;
  positions[1] =  y  ;
   positions[2] =  z;  
  steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // go to new position
 /*
   x = pos1 +  length * cos (angle1);
    y = pos2 + length * sin (angle1);
     positions[0] =  x;
  positions[1] =  y  ;
   positions[2] =  z;  
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
 */
  //pot1 = analogRead(A11);//= 
  // pot1 = map(pot1,0,1023,0,100);
    pot2 = analogRead(A10);//= 
   pot2 = map(pot2,0,1023,0,1000);
    pot3 = analogRead(A0);//= 
   pot3 = map(pot3,0,1023,100,5000);
     pot4 = analogRead(A3);//= 
   pot4 = map(pot4,0,1023,0,100);
   Serial.print("This is just before the (z down while loop)        ");
 Serial.print("pot4 = ");
 Serial.print(pot4);
  // Serial.print("z = ");
//Serial.println(z);
speed1 = 800;
  while (angle1 < angle2){//#1////////////////////////while2  clockwise
  // if(z > 0){/////////////////////////////////////////if3
  // z -=10;}//............................................if3
  z = 0;
  // if(z == 0){
   //  speed1 -=5;
  // }
   // speed1 = analogRead(A13);
   // speed1 = map(speed1,0,1023,0,800);
   // length = analogRead(A1);
    pot4 = analogRead(A3);//= 
   pot4 = map(pot4,0,1023,0,100);//was 100
    
  stepper1.setMaxSpeed(speed1);//800
  stepper1.setAcceleration(1000);
 // stepper1.moveTo(500);

  stepper2.setMaxSpeed(speed1);//800
  stepper2.setAcceleration(1000);
   
    x = pos1 +  length * cos (angle1);
    y = pos2 + length * sin (angle1);
     positions[0] =  x;
  positions[1] =  y  ;
   positions[2] =  z;  
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
    
    angle1 += angle_stepsize;
   
  length = length - (length/pot4);
  //length = length - (length/10);
  // Serial.print("length2  =   ");
  // Serial.println(length);
 
 //counter++;
//Serial.print("the end of (z down while loop)          ");
//Serial.print("z = ");
//Serial.println(z);
   }//..................................................while2 clockwise finish
   
   z = 30;
    x = pos1 +  length * cos (angle1);
    y = pos2 + length * sin (angle1);
     positions[0] =  x;
  positions[1] =  y  ;
   positions[2] =  z;  
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();///raise the z
   pot1 = analogRead(A12);//= 
   pot1 = map(pot3,0,1023,200,3000);
   length = pot1;
    length = random(200,1000);
   angle1 = random(0,628)*.01;
    mod = random(2,6);
     angle2 = angle1 - mod;
     
      z = 0;
    x = pos1 +  length * cos (angle1);
    y = pos2 + length * sin (angle1);
     positions[0] =  x;
  positions[1] =  y  ;
   positions[2] =  z;  
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();///raise the z
  
  
     //Serial.print("Hello angle1 = ");
     //Serial.println(angle1);
     // Serial.print("Hello angle2 = ");
     //Serial.println(angle2);
    while (angle1 > angle2){//#1////////////////////////while3  counter clockwise start
  // if(z > 0){/////////////////////////////////////////if3
  // z -=10;}//............................................if3
  z = 0;
  // if(z == 0){
   //  speed1 -=5;
   //}
   // speed1 = analogRead(A13);
   // speed1 = map(speed1,0,1023,0,800);
   // length = analogRead(A1);
    pot4 = analogRead(A3);//= 
   pot4 = map(pot4,0,1023,0,100);//was 100
    
  stepper1.setMaxSpeed(speed1);//800
  stepper1.setAcceleration(1000);
 // stepper1.moveTo(500);

  stepper2.setMaxSpeed(speed1);//800
  stepper2.setAcceleration(1000);
   
    x = pos1 +  length * cos (angle1);
    y = pos2 + length * sin (angle1);
     positions[0] =  x;
  positions[1] =  y  ;
   positions[2] =  z;  
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
    
    angle1 -= angle_stepsize;
   
  length = length - (length/pot4);
  //length = length - (length/10);
  // Serial.print("length2  =   ");
  // Serial.println(length);
 
 counter++;
//Serial.print("the end of (z down while loop)          ");
//Serial.print("z = ");
//Serial.println(z);
   }//..................................................while3 counter clockwise finish
   counter2++;
  // counter = 0;
  
   // int b = random(500,4000);
    
   
  
}   //..........................................................while1..........

 BrushDip();
 //Serial.print("j is a 100 loop event the current # = ");
 //Serial.println(j);
}//............................................................for1...

  
}///end
