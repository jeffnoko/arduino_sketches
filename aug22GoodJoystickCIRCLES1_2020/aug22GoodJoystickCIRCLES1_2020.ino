
#include<AccelStepper.h>
#include <MultiStepper.h>
#include <Servo.h> 

MultiStepper steppers;

#define JOYSTICK_PIN1 A14 
#define JOYSTICK_PIN2 A15 
#define MAX_SPEED 600 
#define INPUT_READ_INTERVAL 100

int desired_speed1;
int desired_speed2;

int joystick_in1 = analogRead(JOYSTICK_PIN1); 
int joystick_in2 = analogRead(JOYSTICK_PIN2); 
unsigned long last_input_time = 0; 
int maxUp = 500;

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
 int voltageS = 13;
 int voltageT = A12;
  int voltageU = A11;
   int voltageV = A10;
int i = 0;
int pos = 130;
int currentpos = 0;
int pos1= random(1000,13000);
int pos2= random(1000,13000);



 long positions[2];
 
 
  int x,y;
  int length = random(300,1000);
  //float angle = 0.0;
   float angle = 0.0;
 // float angle_stepsize = PI/4;
 float angle_stepsize = 0.05;

  /// float angle = PI/2;
 // float angle_stepsize = PI/6;
   unsigned long currentMillis ;
  unsigned long previousMillis = 0;
  const long interval= 100;
  
   int p1 = 0;
    int p2 = 0;
    
    
     
     //Smoothing voltageS
     const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A13;
//Smoothing voltageS

 long testX = 1000000000;
    long testY = 1000000000;
int average1 = average;
int average2;

void setup() {
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



  stepper1.setMaxSpeed(600);
  stepper1.setAcceleration(1000);
 // stepper1.moveTo(500);

  stepper2.setMaxSpeed(600);
  stepper2.setAcceleration(1000);
 // stepper2.moveTo(500);
 

  stepper3.setMaxSpeed(1000);
  stepper3.setAcceleration(2000);
  
  steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
  
  stepper1.setMaxSpeed(600);
  stepper2.setMaxSpeed(600);
  
 //Smoothing voltageS
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;          
 //Smoothing voltageS
}

//X full run is 14300  Y full run is 14600
void loop()
{
    //unsigned long seed=seedOut(31);
 // Serial.print("seed = ");
 // Serial.println(seed);
// randomSeed(seed);
 // delay(2000);
  /*
  for(i = 0; i<50;i ++){
  sensorValue1 = analogRead(A15);//delay(50);
sensorValue2 = analogRead(A14);//delay(50);
voltageS = analogRead(A13);voltageT = map(voltageT,0,1023, -500,500);
voltageT = analogRead(A12);voltageT = map(voltageT,0,1023, -500,500);
voltageU = analogRead(A11);voltageU = map(voltageU,0,1023, -500,500);
voltageV = analogRead(A10);voltageV = map(voltageV,0,1023, 0,500);
//Serial.print(" voltageS = "); Serial.println( voltageS );delay(500);
// Serial.print(" Svalue2 = "); Serial.println( sensorValue2 );delay(500);
  }
  */
 // voltageS = analogRead(A13);voltageS = map(voltageS,0,1023, -500,500);
  //int p= random(0,628);
 // float p2 = p / 100.00;
 // pos1= random(1000,10000);
// pos2= random(1000,10000);
  //length = random(500,1500);
  pos1 = 0;
  pos2 = 0;
  length = 500;
 // int length2 = length;
   int length2 = 500;
  //joystick2();
   voltageS = analogRead(A13);voltageS = map(voltageS,0,1023, -500,500);
  //for(i = 0; i <10000; i++){
    //Smoothing
    /*
     total= total - readings[readIndex];         
   readings[readIndex] = analogRead(inputPin); 
   total= total + readings[readIndex];       
    readIndex = readIndex + 1;                    
  if (readIndex >= numReadings){              
     readIndex = 0;  }                         
  average = total / numReadings; 
   */ 
    
    //Smoothing
     //joystick2();
     //Serial.print(" voltageS = "); Serial.println( voltageS );delay(500);
     stepper3.moveTo(voltageS);
     //stepper3.runSpeedToPosition();
    // pos1 = pos1 + p;
    // int p= random(0,628);
   // float p2 = p / 100.00;
   // angle = p2;
   // s1up();
    //delay(500);
   
   // length = random(500,1500);
    angle = 1.00;
   //  x = pos1  + length * cos (angle);
    //  y = pos2 + length2 * sin (angle);
    //   positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
   // positions[1] =  y ;//stepper#2 up down
   // steppers.moveTo(positions);
   // steppers.runSpeedToPosition();
   //s1down();
  // angle = 1; joystick_in1 = analogRead(JOYSTICK_PIN1); 
  joystick_in1 = analogRead(JOYSTICK_PIN1); 
     joystick_in2 = analogRead(JOYSTICK_PIN2);
    desired_speed1=  joystick_in1; //Serial.println(desired_speed1);
     desired_speed2= joystick_in2; //Serial.println(desired_speed2);
      desired_speed1 = map(joystick_in1, 0, 1023, -MAX_SPEED, MAX_SPEED); 
        desired_speed2 = map(joystick_in2, 0, 1023, -MAX_SPEED, MAX_SPEED); 
        // Serial.println(desired_speed1);
     // Serial.println(desired_speed2);
     //  Serial.print("testX =    ");
      // Serial.println(testX);
    while (desired_speed1 >20 || desired_speed1 <0 ||
    desired_speed2 > 30 || desired_speed2 < -30){
       //Serial.println(desired_speed2);
    joystick2();
  //}
  /*
    x =  pos1 + length * cos (angle);
    y =  pos2 + length2 * sin (angle);
   stepper1.setCurrentPosition(x);
   stepper2.setCurrentPosition(y); 
    //Serial.println(desired_speed2);
  while (angle < 7.00)
  {
    // stepper1.setMaxSpeed(600);
  //stepper2.setMaxSpeed(600);
   // joystick2();
   //  pos1 = pos1 + p1;
    //  pos2 = pos2 + p2;
    //calculate x , y from a vector with known lenght and angle
    x =  pos1 + length * cos (angle);
    y =  pos2 + length2 * sin (angle);
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y  ;//stepper#2 up down
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
    
    angle += angle_stepsize;
  //  pos2 = pos2- 5;
  //length2 = length2 +5;
  
  voltageS = analogRead(A13);voltageS = map(voltageS,0,1023, -500,500);
 voltageT = analogRead(A12);voltageT = map(voltageT,0,1023, 0,5000);
 voltageU = analogRead(A11);voltageU = map(voltageU,0,1023, 0,5000);
 //int average1 = average;
   total= total - readings[readIndex];         
 readings[readIndex] = voltageS;//analogRead(inputPin); 
 total= total + readings[readIndex];       
  readIndex = readIndex + 1;                    
if (readIndex >= numReadings){              
   readIndex = 0;  }                         
average = total / numReadings; 
 //average1 = average;
 //average2 = average1;
//if (average1 != average){
  //stepper3.moveTo(average);
  // stepper3.runSpeedToPosition();//}
    average1 = average;
   // Serial.print("average = ");
  //Serial.println(average);
  // Serial.print("voltageS = ");
  //Serial.println(voltageS);
 length =  voltageT;
  length2 =  voltageU;
  joystick_in1 = analogRead(JOYSTICK_PIN1); 
   joystick_in2 = analogRead(JOYSTICK_PIN2);
 // analogRead(JOYSTICK_PIN1); 
 // analogRead(JOYSTICK_PIN2);
 
// Serial.print(" voltageS = "); Serial.println( voltageS );delay(20);
   }*/
  
   joystick_in1 = analogRead(JOYSTICK_PIN1); 
   joystick_in2 = analogRead(JOYSTICK_PIN2);
   //analogRead(JOYSTICK_PIN2);
   // voltageT = analogRead(A12);voltageT = map(voltageT,0,1023, -500,500);
// voltageU = analogRead(A11);voltageU = map(voltageU,0,1023, -500,500);
 //length =  voltageT;
 // length2 =  voltageU;
   /*
   angle = 4;
   
    while (angle < 7)
  {
    
    //calculate x , y from a vector with known lenght and angle
    x = pos1 + length * cos (angle);
    y = pos2 + length2 * sin (angle);
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y  ;//stepper#2 up down
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
    
    angle += angle_stepsize;
   pos2 = pos2- 5;
  //length2 = length2 +3;
 
   }
   
   */
   
   
   //pos1 = pos1 + 300;
   // pos2 = pos2 - 300;
   angle = 1.00;
   //length = length + 200;
}

  

   
   
  
}
