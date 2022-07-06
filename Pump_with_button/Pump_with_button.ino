
#include <Adafruit_MotorShield.h>


Adafruit_MotorShield AFMS = Adafruit_MotorShield();



Adafruit_DCMotor *myMotor = AFMS.getMotor(4);

const int buttonPin = 3; 
int buttonState = 0; 

void setup() {
  Serial.begin(9600);          
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  if (!AFMS.begin()) {         
  
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");

  
  myMotor->setSpeed(150);
  myMotor->run(FORWARD);
  // turn on motor
  myMotor->run(RELEASE);
}

void loop() {
  uint8_t i;
 buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    Serial.println("on");
    
    myMotor->setSpeed(255);
    myMotor->run(FORWARD);
  } else {
    // turn LED off:
    myMotor->setSpeed(0);
    myMotor->run(RELEASE);
    Serial.println("off");
  }
  //Serial.print("tick");

  myMotor->run(FORWARD);
 
}
