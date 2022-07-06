

#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;


//int servo1Pos = 50;// 0 - 180 rack pinion
//int servo2Pos = 150;// 150 straight up, 180 to left, 120 to right
//int servo3Pos = 50;// 50 is straight up, 80 is brush back, 0 is forward

const int servo1MinDegrees = 50; 
const int servo1MaxDegrees = 100;
const int servo2MinDegrees = 130; 
const int servo2MaxDegrees = 160;
const int servo3MinDegrees = 20; 
const int servo3MaxDegrees = 50;
//...............................................................................................
int servo1Pos = 50;     // the current angle of the servo - starting at 90.
int servo1SlowInterval = 80; // millisecs between servo moves
int servo1FastInterval = 10;
int servo1Interval = servo1SlowInterval; // initial millisecs between servo moves
int servo1Degrees = 2;       // amount servo moves at each step 

int servo2Pos = 130;     // the current angle of the servo - starting at 90.
int servo2SlowInterval = 80; // millisecs between servo moves
int servo2FastInterval = 10;
int servo2Interval = servo2SlowInterval; // initial millisecs between servo moves
int servo2Degrees = 2;       // amount servo moves at each step 

int servo3Pos = 20;     // the current angle of the servo - starting at 90.
int servo3SlowInterval = 300; // millisecs between servo moves
int servo3FastInterval = 30;
int servo3Interval = servo3SlowInterval; // initial millisecs between servo moves
int servo3Degrees = 1;       // amount servo moves at each step 
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
}

void loop() {
  /*
Serial.begin(9600);
  servo1.write(50);    // 50-100
   servo2.write(140);  //140 - 170
    servo3.write(20); //20 -70

     for (servo1Pos = 50,servo2Pos = 140,servo3Pos = 20;     servo1Pos <= 80 && servo2Pos <= 170 && servo3Pos <= 50;     servo1Pos +=1,servo2Pos +=1,servo3Pos +=1) {
    // in steps of 1 degree
    servo1.write(servo1Pos); 
    servo2.write(servo2Pos); 
    servo3.write(servo3Pos); 
    delay(20); 
    Serial.print("servo1Pos =  "); Serial.println(servo1Pos);
  }
 Serial.println("");
 for (servo1Pos = 80,servo2Pos = 170,servo3Pos = 50;    servo1Pos >= 50 && servo2Pos >= 140 && servo3Pos >= 20;     servo1Pos -= 1,servo2Pos -= 1,servo3Pos -= 1) {
    // in steps of 1 degree
    servo1.write(servo1Pos); 
    servo2.write(servo2Pos); 
    servo3.write(servo3Pos); 
    delay(20);                       // waits 15 ms for the servo to reach the position
    Serial.print("servo1Pos =  "); Serial.println(servo1Pos);
    
  }
 Serial.println("");
*/
currentMillis1 = millis(); 
currentMillis2 = millis(); 
currentMillis3 = millis(); 
servoSweep();
}


//========================================START
void servoSweep() {

      // this is similar to the servo sweep example except that it uses millis() rather than delay()

      // nothing happens unless the interval has expired
      // the value of currentMillis was set in loop()
  //==================================START SERVO1 IF STATEMENTS
  if (currentMillis1 - previousServo1Millis >= servo1Interval) {
        // its time for another move
    previousServo1Millis += servo1Interval;
    
    servo1Pos = servo1Pos + servo1Degrees; // servoDegrees might be negative

    if (servo1Pos <= servo1MinDegrees) {
          // when the servo gets to its minimum position change the interval to change the speed
       if (servo1Interval == servo1SlowInterval) {
         servo1Interval = servo1FastInterval;
       }
       else {
        servo1Interval = servo1SlowInterval;
       }
    }

    if ((servo1Pos >= servo1MaxDegrees) || (servo1Pos <= servo1MinDegrees))  {
          // if the servo is at either extreme change the sign of the degrees to make it move the other way
      servo1Degrees = - servo1Degrees; // reverse direction
          // and update the position to ensure it is within range
      servo1Pos = servo1Pos + servo1Degrees; 
    }
    
        // make the servo move to the next position
    servo1.write(servo1Pos);
        // and record the time when the move happened
//Serial.println("servo1If");
  }

  //=========================================END SERVO1 IF STATEMENTS
  //==================================START SERVO2 IF STATEMENTS
  if (currentMillis2 - previousServo2Millis >= servo2Interval) {
        // its time for another move
    previousServo2Millis += servo2Interval;
    
    servo2Pos = servo2Pos + servo2Degrees; // servoDegrees might be negative

    if (servo2Pos <= servo2MinDegrees) {
          // when the servo gets to its minimum position change the interval to change the speed
       if (servo2Interval == servo2SlowInterval) {
         servo2Interval = servo2FastInterval;
       }
       else {
        servo2Interval = servo2SlowInterval;
       }
    }

    if ((servo2Pos >= servo2MaxDegrees) || (servo2Pos <= servo2MinDegrees))  {
          // if the servo is at either extreme change the sign of the degrees to make it move the other way
      servo2Degrees = - servo2Degrees; // reverse direction
          // and update the position to ensure it is within range
      servo2Pos = servo2Pos + servo2Degrees; 
    }
    
        // make the servo move to the next position
    servo2.write(servo2Pos);
        // and record the time when the move happened

  }

  //=========================================END SERVO2 IF STATEMENTS
  //==================================START SERVO3 IF STATEMENTS
  if (currentMillis3 - previousServo3Millis >= servo3Interval) {
        // its time for another move
    previousServo3Millis += servo3Interval;
    
    servo3Pos = servo3Pos + servo3Degrees; // servoDegrees might be negative

    if (servo3Pos <= servo3MinDegrees) {
          // when the servo gets to its minimum position change the interval to change the speed
       if (servo3Interval == servo3SlowInterval) {
         servo3Interval = servo3FastInterval;
       }
       else {
        servo3Interval = servo3SlowInterval;
       }
    }

    if ((servo3Pos >= servo3MaxDegrees) || (servo3Pos <= servo3MinDegrees))  {
          // if the servo is at either extreme change the sign of the degrees to make it move the other way
      servo3Degrees = - servo3Degrees; // reverse direction
          // and update the position to ensure it is within range
      servo3Pos = servo3Pos + servo3Degrees; 
    }
    
        // make the servo move to the next position
    servo3.write(servo3Pos);
        // and record the time when the move happened

  }

  //=========================================END SERVO3 IF STATEMENTS
  
}

//========================================END
