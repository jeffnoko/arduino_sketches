
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
float voltageP = A1;
float voltageQ = A0;
float voltageR = A4;
int voltageS = A13;
int voltageT = A12;
int voltageU = A11;
int voltageV = A10;
float voltageW = A3;

int i = 0;
int pos = 130;
int currentpos = 0;
int xPos= random(100,1300);
int yPos= random(100,1300);



long positions[2];


int x,y,z;
int r = random(300,1000);
//float angle = 0.0;
float angle = 0.0;
// float angle_stepsize = PI/4;
float angle_stepsize = 0.05;

/// float angle = PI/2;
// float angle_stepsize = PI/6;

int rNum1;
float rNum1f;
int rNum2;
float rNum2f;
int rNum3;
float rNum3f;

float p = 0.0;
//float Rnumber2 ;
// float Rnumber3 ;
int xPos2;
int yPos2;
int startUp = 0;

//limit switch settings**************
const int zLimitSwitch = 30; 
int zLimitSwitchReading;
int zTouchPoint = A10;
int zTouchPointReading;
//limit switch settings**************
float pos1x = 0;
float pos1y = 0;

int cup1 = 90;
int cup2 = 115;
int cup3 = 140;
int cup4 = 170;
int dipCup;
int cupPos;
int randomCup;
int count = 0;

#define JOYSTICK_PIN1 A8//A14 x
#define JOYSTICK_PIN2 A9//A15 y
#define MAX_SPEED 1000 
#define INPUT_READ_INTERVAL 100
int button1;
long testX = 1000000;
long testY = 1000000;
const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int average1 = average;
int average2;


int desired_speed1;
int desired_speed2;

int joystick_in1 = analogRead(A8); 
int joystick_in2 = analogRead(A9); 
unsigned long last_input_time = 0; 
int button2;
int button3;
int button4;
int button5;
int buttonState = 0;


void setup()
{

  Serial.begin(9600);

  pinMode(9, INPUT_PULLUP);


  pinMode (A13, INPUT);
  pinMode (A12, INPUT);
  pinMode (A11, INPUT);
  pinMode (A10, INPUT);
  pinMode (A3, INPUT);
  pinMode (A1, INPUT);
  pinMode (A0, INPUT);
  pinMode (A4, INPUT);
  pinMode(zLimitSwitch, INPUT_PULLUP);  
  pinMode (26, INPUT_PULLUP);
   pinMode (28, INPUT_PULLUP);
    pinMode (34, INPUT_PULLUP);
     pinMode (36, INPUT_PULLUP);

  pinMode (A5, INPUT_PULLUP);
  servo1.attach(8);
  //servo1.write(160);
  //servo2.attach(50);
  //servo2.write(165);



  stepper1.setMaxSpeed(800);
  stepper1.setAcceleration(800);
  // stepper1.moveTo(500);

  stepper2.setMaxSpeed(800);
  stepper2.setAcceleration(800);
  // stepper2.moveTo(500);


  stepper3.setMaxSpeed(100);
  stepper3.setAcceleration(100);





  steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);

  stepper1.setMaxSpeed(800);
  stepper2.setMaxSpeed(800);



}
//X full run is 19000  Y full run is 28000
void loop()
{
  unsigned long seed=seedOut(31);
  // Serial.print("seed = ");
  //Serial.println(seed);
  randomSeed(seed);
  
   stepper1.setMaxSpeed(800);
  stepper2.setMaxSpeed(800);
  // delay(1000);

  //voltageS = analogRead(A13);
  //voltageT = analogRead(A12);
  // voltageU = analogRead(A11);
  // voltageT = analogRead(A10);
  //  voltageT = analogRead(A3);
  //  voltageT = analogRead(A1);
  // voltageT = analogRead(A0);
  //  voltageT = analogRead(A14);
  // Serial.println(voltageT);

  if(startUp == 0){
    Startup_BrushDip();
    startUp = 1;
  }
  xPos = 0;//random(0,500);
  yPos = 0;//random(0,500);

  for(i =0;i < 5; i++){
     checkForJoystick();
    voltageS = analogRead(A13);
    voltageT = analogRead(A12);
    voltageU = analogRead(A11);
    // voltageS = random(100,500);//map(voltageS,0,1023,100,1000);
    //voltageT = random(100,500);//map(voltageT,0,1023,100,1000);
    //voltageU = random(100,500);//map(voltageU,0,1023,0,300);
    voltageS = map(voltageS,0,1023,100,500);
    voltageT = map(voltageT,0,1023,100,500);
    voltageU = map(voltageU,0,1023,0,300);
    Serial.print("voltageU = ");
    Serial.println(voltageU);
   // rNum1 = random(0,314);
   // rNum2 = random(314,628);
    
     rNum1 = random(0,628);
   // rNum2 = random(314,628);
    rNum2 = rNum1 + random(100,400);

    // rNum1f = rNum1 / 100.00;//to turn a int to a float
    // rNum2f = rNum2 / 100.00;//to turn a int to a float


    /* 
     if(rNum2f < rNum1f ){//to make rNum2f larger than rNum1f  //while loop #1
     //Serial.println("hello1");
     rNum2 = random(0,628);
     rNum2f = rNum2 / 100.00;
     }
     */
    // while(rNum2 < rNum1){
    // rNum2 = random(0,628);

    // }
    rNum1f = rNum1 / 100.00;//to turn a int to a float
    rNum2f = rNum2 / 100.00;//to turn a int to a float

    Serial.print("rNum1f ="); Serial.println(rNum1f);
     Serial.print("rNum2f ="); Serial.println(rNum2f);

    //s1up();

    //xPos += random(0,100);
    //yPos += random(0,100);

    //int r1 =500;//random(100,200);
    int r1 = voltageS;//random(10,voltageS);
    Serial.print("r1 = ");
    Serial.println(r1);

    int r2 = voltageT;//random(10,voltageT);
    //Serial.print("r2 = ");Serial.println(r2);

    // rNum2f = rNum1f + random(1,4);
    angle = rNum1f;

    int ad = voltageU;
    r1 = r1 + ad;
    float b = (rNum2f/3)/angle_stepsize;
    //int r1,r2;
    Serial.print("b = ");
    Serial.println(b);
    Serial.print("ad = ");
    Serial.println(ad);
    Serial.print("r1.2 = ");
    Serial.println(r1);

    if( xPos +  r1 * cos (angle) > 0 || xPos +  r1 * cos (angle) < 19000 || yPos + r1 * sin (angle) > 0 || yPos + r1 * sin (angle) < 25000){
      x = xPos +  r1 * cos (angle);
      y = yPos + r1 * sin (angle);
      xPos2 = xPos + (r2 + r1) * cos (angle);
      yPos2 =yPos + (r2+ r1) * sin (angle);
      positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
      positions[1] =  y ;//stepper#2 up down
      steppers.moveTo(positions);
      steppers.runSpeedToPosition();
      s1down();
      Serial.println("first if ");
    }
    //Serial.println("hello");
    //angle = rNum1f;

    Serial.println("first circle ");
    Serial.print("angle = ");
    Serial.println(angle); 
    Serial.print("rNum2 = ");
    Serial.println(rNum2);
    //Serial.print("x = ");Serial.println(x);  
    // Serial.print("y = ");Serial.println(y); 
    Serial.println(" ");
    //while (angle < rNum2f/2 && x > 0 && x < 19000 && y > 0 && y < 25000)///first circle counter clockwise
    while (angle < rNum2f/2)
    { checkForJoystick();
      //Serial.println("inside while loop1 ");

      x = xPos +  r1 * cos (angle);
      y = yPos + r1 * sin (angle);
      xPos2 = xPos +( r2+ r1) * cos (angle);
      yPos2 = yPos +(r2 + r1) * sin (angle);
      positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
      positions[1] =  y  ;//stepper#2 up down
      steppers.moveTo(positions);
      steppers.runSpeedToPosition();

      r1 = r1 - b;
      angle += angle_stepsize;
    }

    while (angle < rNum2f )///first circle counter clockwise
    { checkForJoystick();
      // Serial.println("inside while loop2 ");
      x = xPos +  r1 * cos (angle);
      y = yPos + r1 * sin (angle);
      xPos2 = xPos +( r2+ r1) * cos (angle);
      yPos2 = yPos +(r2 + r1) * sin (angle);
      positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
      positions[1] =  y  ;//stepper#2 up down
      steppers.moveTo(positions);
      steppers.runSpeedToPosition();

      r1 = r1 + b;
      angle += angle_stepsize;

    }

    angle = angle - angle_stepsize;

    //angle = angle - PI;
    rNum1 = random(400,628);
    rNum2 = random(0,314);

    rNum1f = rNum1 / 100.00;
    rNum2f = rNum2 / 100.00;//to turn a int to a float
    angle = rNum1f;
    //rNum2f = angle - random(1,4);
    angle = angle - PI;
    Serial.println("second circle ");
    Serial.print("angle = ");
    Serial.println(angle); 
    Serial.print("rNum2f = ");
    Serial.println(rNum2f);
    // Serial.print("x = ");Serial.println(x);
    //  Serial.print("y = ");Serial.println(y);
    Serial.println("");

    //while (angle > rNum2f && x > 0 && x < 19000 && y > 0 && y < 25000)//second circle
    while (angle > rNum2f )
    { checkForJoystick();
      //Serial.println("inside while loop3 ");
      x = xPos2 + r2 * cos (angle);
      y = yPos2  + r2 * sin (angle);
      positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
      positions[1] =  y  ;//stepper#2 up down
      steppers.moveTo(positions);
      steppers.runSpeedToPosition();



      angle -= angle_stepsize;
    }

    //}  
    count++;
    if (count == 5){
      //s1up();
      BrushDip();
      count = 0;
    }
  }//for loop
  
  checkForJoystick();
  /*
  button2 = digitalRead(26);
  if(button2 == 0){
    buttonState = !buttonState;
Serial.println("buttonState1 = ");Serial.println(buttonState );}

  while(buttonState == 1){
  joystick_in1 = analogRead(A8); 
  joystick_in2 = analogRead(A9);
  joystick2();
   button3 = digitalRead(28);
    if(button3 == 0){
      buttonState = !buttonState;
      }
  //Serial.println("button3 = ");Serial.println(button3 );
      }
  */
  
}//end loop

