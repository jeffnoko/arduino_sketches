
#include <Adafruit_MotorShield.h>


Adafruit_MotorShield AFMS = Adafruit_MotorShield();


Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);//yellow
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);//blue
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);//red
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);//water


const int buttonPin1 = 3; // water
const int buttonPin2 = 4;// red
const int buttonPin3 = 5;// yellow
const int buttonPin4 = 6;// blue
int buttonState1 = 0; 
int buttonState2 = 0; 
int buttonState3 = 0; 
int buttonState4 = 0; 

void setup() {
  Serial.begin(9600);          
  pinMode(buttonPin1, INPUT_PULLUP);//water, black button
   pinMode(buttonPin2, INPUT_PULLUP);//red, red button
    pinMode(buttonPin3, INPUT_PULLUP);//yellow
     pinMode(buttonPin4, INPUT_PULLUP);//blue
 // Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  if (!AFMS.begin()) {         
  
   
    while (1);
  }
 

  
 // myMotor1->setSpeed(150);
 // myMotor1->run(FORWARD);
  
 // myMotor1->run(RELEASE);
}

void loop() {

 buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
   buttonState3 = digitalRead(buttonPin3);
    buttonState4 = digitalRead(buttonPin4);
    
  if (buttonState1 == LOW) {////water
    Serial.println("on1");
    myMotor4->setSpeed(255);
    myMotor4->run(FORWARD);
  } else {
   myMotor4->setSpeed(0);
    myMotor4->run(RELEASE);
    Serial.println("off");
  }
  myMotor4->run(FORWARD);

 //*********
 if (buttonState2 == LOW) {//red
    Serial.println("on2");
    myMotor3->setSpeed(255);
    myMotor3->run(FORWARD);
  } else {
   myMotor3->setSpeed(0);
    myMotor3->run(RELEASE);
    Serial.println("off");
  }
  myMotor3->run(FORWARD);
  //**************
  if (buttonState3 == LOW) {//yellow
    Serial.println("on3");
    myMotor1->setSpeed(255);
    myMotor1->run(BACKWARD);
  } else {
   myMotor1->setSpeed(0);
    myMotor1->run(RELEASE);
    Serial.println("off");
  }
  myMotor1->run(BACKWARD);
  //*************
  if (buttonState4 == LOW) {//blue
    Serial.println("on4");
    myMotor2->setSpeed(255);
    myMotor2->run(BACKWARD);
  } else {
   myMotor2->setSpeed(0);
    myMotor2->run(RELEASE);
    Serial.println("off");
  }
  myMotor2->run(BACKWARD);
 
}
