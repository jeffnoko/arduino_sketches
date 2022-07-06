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

}
