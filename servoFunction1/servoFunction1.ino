#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

int pos = 0;
int pos1 = 0;
int mapSpeed;
int servo1Pos = 50;
int servo2Pos = 150;// 150 straight up, 180 to left, 120 to right
int servo3Pos = 50;// 50 is straight up, 80 is brush back, 0 is forward

void setup() {
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);

}

void loop() {
servo2.write(150);
servo3.write(50);
  /*
  moveTo(60,20);
  delay(300);
  moveTo(30,10);
  delay(300);
  moveTo(10,5);
  delay(300);
  */

}

void moveTo(int position,int speed){
  mapSpeed = map(speed,0,30,30,0);
  if(position >pos){
    for (pos = pos1; pos <= position; pos +=1){
      servo2.write(pos);
      pos1 = pos;
      delay(mapSpeed);
    }
  }
}
