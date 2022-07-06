

#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;




const int servo1MinDegrees = 50;
const int servo1MaxDegrees = 100;
const int servo2MinDegrees = 130;
const int servo2MaxDegrees = 160;
const int servo3MinDegrees = 20;
const int servo3MaxDegrees = 50;
//...............................................................................................
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
int servo3SlowInterval = 300; // millisecs between servo moves
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



void setup() {
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);

   servo1.write(50);    // 50-100
  servo2.write(140);  //140 - 170
  servo3.write(20); //20 -70
}

void loop() {

  Serial.begin(9600);



  currentMillis1 = millis();
  currentMillis2 = millis();
  currentMillis3 = millis();
  servoSweep();
}


//========================================START
void servoSweep() {


  //==================================START SERVO1 IF STATEMENTS
  if (currentMillis1 - previousServo1Millis >= servo1Interval) {
    previousServo1Millis += servo1Interval;
    servo1Pos = servo1Pos + servo1Degrees;
    if (servo1Pos <= servo1MinDegrees) {
      if (servo1Interval == servo1SlowInterval) {
        servo1Interval = servo1FastInterval;
      }
      else {
        servo1Interval = servo1SlowInterval;
      }
    }
    if ((servo1Pos >= servo1MaxDegrees) || (servo1Pos <= servo1MinDegrees))  {
      servo1Degrees = - servo1Degrees; // reverse direction
      servo1Pos = servo1Pos + servo1Degrees;
    }
    servo1.write(servo1Pos);
  }

  //=========================================END SERVO1 IF STATEMENTS
  //==================================START SERVO2 IF STATEMENTS
  if (currentMillis2 - previousServo2Millis >= servo2Interval) {
    previousServo2Millis += servo2Interval;
    servo2Pos = servo2Pos + servo2Degrees;
    if (servo2Pos <= servo2MinDegrees) {
      if (servo2Interval == servo2SlowInterval) {
        servo2Interval = servo2FastInterval;
      }
      else {
        servo2Interval = servo2SlowInterval;
      }
    }
    if ((servo2Pos >= servo2MaxDegrees) || (servo2Pos <= servo2MinDegrees))  {
      servo2Degrees = - servo2Degrees; // reverse direction
      servo2Pos = servo2Pos + servo2Degrees;
    }
    servo2.write(servo2Pos);
  }

  //=========================================END SERVO2 IF STATEMENTS
  //==================================START SERVO3 IF STATEMENTS
  if (currentMillis3 - previousServo3Millis >= servo3Interval) {
    previousServo3Millis += servo3Interval;
    servo3Pos = servo3Pos + servo3Degrees;
    if (servo3Pos <= servo3MinDegrees) {
      if (servo3Interval == servo3SlowInterval) {
        servo3Interval = servo3FastInterval;
      }
      else {
        servo3Interval = servo3SlowInterval;
      }
    }
    if ((servo3Pos >= servo3MaxDegrees) || (servo3Pos <= servo3MinDegrees))  {
      servo3Degrees = - servo3Degrees; // reverse direction
      servo3Pos = servo3Pos + servo3Degrees;
    }
    servo3.write(servo3Pos);
  }

  //=========================================END SERVO3 IF STATEMENTS

}

//========================================END
