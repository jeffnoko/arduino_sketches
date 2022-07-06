#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;


int servo1Pos = 50;// 0 - 180 rack pinion
int servo2Pos = 150;// 150 straight up, 180 to left, 120 to right
int servo3Pos = 50;// 50 is straight up, 80 is brush back, 0 is forward


void setup() {
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
}

void loop() {
Serial.begin(9600);
  servo1.write(0);
   servo2.write(120);  
    servo3.write(0); 

     for (servo1Pos = 0,servo2Pos = 120,servo3Pos = 0; servo1Pos <= 100,servo2Pos <= 80,servo3Pos <= 180; servo1Pos += 2,servo2Pos += 1,servo3Pos += 1) {
    // in steps of 1 degree
    servo1.write(servo1Pos); 
    servo2.write(servo2Pos); 
    servo3.write(servo3Pos); 
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
 
 for (servo1Pos = 100,servo2Pos = 80,servo3Pos = 180; servo1Pos >= 0,servo2Pos >= 120,servo3Pos >= 0; servo1Pos -= 2,servo2Pos -= 1,servo3Pos -= 1) {
    // in steps of 1 degree
    servo1.write(servo1Pos); 
    servo2.write(servo2Pos); 
    servo3.write(servo3Pos); 
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  /*

    servo1.write(0);
    Serial.println(0); 
    delay(500);

  servo1.write(20);
  Serial.println(20); 
    delay(500);

  servo1.write(50);
  Serial.println(50); 
    delay(500);

  servo1.write(100);
  Serial.println(100); 
    delay(500);

  servo1.write(120);
  Serial.println(120); 
    delay(500);

  servo1.write(160);
  Serial.println(160); 
    delay(500);
 */
}
