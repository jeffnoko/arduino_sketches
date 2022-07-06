

#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

int pos;
int servo1Pos = 50;// 0-180
int servo2Pos = 150;// 150 straight up, 180 to left, 120 to right
int servo3Pos = 50;// 50 is straight up, 80 is brush back, 0 is forward


void setup() {
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
}

void loop() {
  Serial.begin(9600);
  //servo1.write(80);
  //servo2.write(150);
  //servo3.write(50);

  int rand1 = random(0, 50); int rand2 = random(60, 110);
  int rand3 = random(120, 140); int rand4 = random(140, 170);
  int rand5 = random(0, 30); int rand6 = random(50, 80);
servo1Pos = random(20,50);
  for ( servo2Pos = rand3, servo3Pos = rand5; servo2Pos <= rand4, servo3Pos <= rand6; servo2Pos += 1, servo3Pos += 1) {
    servo1.write(servo1Pos);
    servo2.write(servo2Pos);
    servo3.write(servo3Pos);
    delay(40);
//servo1Pos = random(20,50);
    Serial.print("rand1  =");  Serial.println(rand1);
    Serial.print("rand2  =");  Serial.println(rand2);
    //Serial.print("servo3Pos  =");  Serial.println(servo3Pos);
    // Serial.println("");
    // Serial.println("");
  }
  delay(5000);
servo1Pos = random(80,110);
  for ( servo2Pos = rand4, servo3Pos = rand6;  servo2Pos >= rand3, servo3Pos >= rand6; servo2Pos -= 1, servo3Pos -= 1) {
    //servo1Pos = random(80,110);
    servo1.write(servo1Pos);
    servo2.write(servo2Pos);
    servo3.write(servo3Pos);
    delay(40);
    // Serial.print("servo1Pos  =");  Serial.println(servo1Pos);
    // Serial.print("servo2Pos  =");  Serial.println(servo2Pos);
    // Serial.print("servo3Pos  =");  Serial.println(servo3Pos);
    //Serial.println("");
    //Serial.println("");

  }

  /*
     for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15 ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15 ms for the servo to reach the position

    }
  */
}
