
//goes with BRUSHSTROKE1
//3 multiStepper sending signals to a second arduino for servo motion brush
#include <AccelStepper.h>
#include <MultiStepper.h>

// EG X-Y position bed driven by 2 steppers
// Alas its not possible to build an array of these with different pins for each :-(
AccelStepper stepper1(1,2,3);
AccelStepper stepper2(1,10,11);
AccelStepper stepper3(1,5,6);

// Up to 10 steppers can be handled as a group by MultiStepper
MultiStepper steppers;
float angle = 0;
float targetAngle = 0;
float stepSize = 0.5;
int servoState = 0;
int brushstroke;
 int counter = 0;
 int a1,a2,a3,a4,b1,b2,b3,b4,c1,c2,c3,c4;
 int r = 1000;
 int startPointA = 0;
 int startPointB = 0;
 int pot1;
  int xLimit = 7000;
  int yLimit = 10000;

void setup() {
  Serial.begin(9600);

  // Configure each stepper
  stepper1.setMaxSpeed(1000);
  stepper2.setMaxSpeed(1000);
   stepper3.setMaxSpeed(1100);

  // Then give them to MultiStepper to manage
  steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
   steppers.addStepper(stepper3);
   pinMode(31,OUTPUT);//send signal to second arduino with pantiit
    pinMode(32,OUTPUT);
    pinMode(33,OUTPUT);
     pinMode(34,OUTPUT);
      pinMode(35,OUTPUT);
       pinMode(36,OUTPUT);
        pinMode(37,OUTPUT);
         pinMode(38,OUTPUT);
          pinMode(39,OUTPUT);
           pinMode(40,OUTPUT);
            pinMode(41,OUTPUT);
             pinMode(42,OUTPUT);
             
              unsigned long seed=seedOut(31);
            randomSeed(seed);
            
            startPointA = random(4000,xLimit);
            startPointB = random(5000,yLimit);
            delay(5000);
}

void loop() {
  
 // long time1 = millis();
    unsigned long seed=seedOut(31);
  randomSeed(seed);
  r = random(500,1000);
  long positions[3]; // Array of desired stepper positions
  int x =  random(0,800);
  int y =   random(0,800);
   pot1 = analogRead(A11);//= 
   pot1 = map(pot1,0,1023,-1000,1000);
  // Serial.print("pot1 = "); Serial.println(pot1); 
 // int r = random(200,500);
 counter = random(0,12);
 
 if(counter == 12){
   counter = 0;
   angle = 0;
   targetAngle = 0;
   //startPoint += 500;
 }

  if(counter == 0){
    brushstroke = 31;
   a1 = 0;b1 =0;c1 = 350;
  a2 = r * cos(angle);b2 =r *sin(angle);c2 =350;
  a3 = r * cos(angle);b3 =r *sin(angle);c2 =-150;
  a4 = 0; b4 = 0; c4 = 0;
  }
   if(counter == 1){
    brushstroke = 32;
     a1 = 0;b1 =0;c1 = 300;
  a2 = r * cos(angle);b2 =r *sin(angle);c2 =300;
  a3 = r * cos(angle);b3 =r *sin(angle);c2 =-200;
  a4 = 0; b4 = 0; c4 = 0;
  }
   if(counter == 2){
    brushstroke = 33;
     a1 = 0;b1 =0;c1 = 300;
  a2 = r * cos(angle);b2 =r *sin(angle);c2 =300;
  a3 = r * cos(angle);b3 =r *sin(angle);c2 =-200;
  a4 = 0; b4 = 0; c4 = 0;
   delay(100);
  }
   if(counter == 3){
    brushstroke = 34;
     a1 = 0;b1 =0;c1 = 100;
  a2 = r * cos(angle);b2 =r *sin(angle);c2 =250;
  a3 = r * cos(angle);b3 =r *sin(angle);c2 =0;
  a4 = 0; b4 = 0; c4 = 0;
  }
   if(counter == 4){
    brushstroke = 35;
     a1 = 0;b1 =0;c1 = 100;
  a2 = r * cos(angle);b2 =r *sin(angle);c2 =150;
  a3 = r * cos(angle);b3 =r *sin(angle);c2 =0;
  a4 = 0; b4 = 0; c4 = 0;
  }
   if(counter == 5){
    brushstroke = 36;
     a1 = 0;b1 =0;c1 = 100;
  a2 = r * cos(angle);b2 =r *sin(angle);c2 =150;
  a3 = r * cos(angle);b3 =r *sin(angle);c2 =0;
  a4 = 0; b4 = 0; c4 = 0;
  }
   if(counter == 6){//3.14
    brushstroke = 37;
     a1 = 0;b1 =0;c1 = 100;
  a2 = r * cos(angle);b2 =r *sin(angle);c2 =150;
  a3 = r * cos(angle);b3 =r *sin(angle);c2 =0;
  a4 = 0; b4 = 0; c4 = 0;
  }
   if(counter == 7){//3.14
    brushstroke = 38;
     a1 = 0;b1 =0;c1 = 100;
  a2 = r * cos(angle);b2 =r *sin(angle);c2 =150;
  a3 = r * cos(angle);b3 =r *sin(angle);c2 =0;
  a4 = 0; b4 = 0; c4 = 0;
  }
   if(counter == 8){//3.14
    brushstroke = 39;
     a1 = 0;b1 =0;c1 = 200;
  a2 = r * cos(angle);b2 =r *sin(angle);c2 =-250;
  a3 = r * cos(angle);b3 =r *sin(angle);c2 =-250;
  a4 = 0; b4 = 0; c4 = -100;
  }
   if(counter == 9){//3.14
    brushstroke = 40;
     a1 = 0;b1 =0;c1 = 200;
  a2 = r * cos(angle);b2 =r *sin(angle);c2 =-250;
  a3 = r * cos(angle);b3 =r *sin(angle);c2 =-250;
  a4 = 0; b4 = 0; c4 = -100;
  }
   if(counter == 10){//3.14
    brushstroke = 41;
     a1 = 0;b1 =0;c1 = 0;
  a2 = r * cos(angle);b2 =r *sin(angle);c2 =-250;
  a3 = r * cos(angle);b3 =r *sin(angle);c2 =-250;
  a4 = 0; b4 = 0; c4 = -100;
  }
   if(counter == 11){//3.14
    brushstroke = 42;
     a1 = 0;b1 =0;c1 = 0;
  a2 = r * cos(angle);b2 =r *sin(angle);c2 =-250;
  a3 = r * cos(angle);b3 =r *sin(angle);c2 =-250;
  a4 = 0; b4 = 0; c4 = -100;
  }
  
 // while(angle < 2*PI){
   // if(counter == 1){
    
   // digitalWrite(36,HIGH);
    //servoState = digitalRead(36);
      // Serial.println(a);
       // digitalWrite(36,LOW);
     //  counter = 0;
   // }
    //digitalWrite(31,HIGH);
   // int r = 1000;//random(200,1000);
    long time1 = millis();
     positions[0] = startPointA + a1;// 0;
  positions[1] =  startPointB + b1;//0;
   positions[2] = c1 + pot1;//100;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // Blocks until all are in position
   delay(100);
   digitalWrite(brushstroke,HIGH);
  positions[0] = startPointA + a2;//r * cos(angle);
  positions[1] =  startPointB + b2;//startPoint + b2;//r *sin(angle);
   positions[2] = c2 + pot1;//150;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // Blocks until all are in position
  //angle += 0.5;
  //}
  //digitalWrite(31,HIGH);
   positions[0] =startPointA + a3;// r * cos(angle);
  positions[1] = startPointB + b3;//startPoint + b3;//r *sin(angle);
   positions[2] = c3 + pot1;//0;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // Blocks until all are in position
 // delay(1000);
   digitalWrite(brushstroke,LOW);
  // Move to a different coordinate
  positions[0] = startPointA + a4;// 0;
  positions[1] = startPointB + b4;//startPoint + b4;// 0;
  positions[2] = c4 + pot1;// 0;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // Blocks until all are in position
  long time2 = millis();
 // delay(1000);
// int a = digitalRead(36);
 //Serial.print("brushstroke = "); Serial.println(brushstroke);
 // digitalWrite(31,LOW);
 // counter ++;
  delay(400);
  // angle += .52;
  //Serial.print("angle =  ");Serial.println(angle);
    angle += (2*PI)/12;
     targetAngle += (2*PI)/12;
   //counter++;
   //startPointA = ;
   // startPointB += random(-500,500);
   // startPointA = startPo;
   // startPointB += random(-2500,2500);
   startPointA = startPointA - a1-a2-a3-a4;
   startPointB = startPointB - b1-b2-b3-b4;
   if(startPointA < xLimit-1500 || startPointA > 2000){
     startPointA += random(-1500,1500);}
     
      if(startPointB < yLimit-1500 || startPointB > 2000){
     
    startPointB += random(-1500,1500);}
    if(startPointA > xLimit){
      startPointA = startPointA - 5000;}
      if(startPointA < 3000){
        startPointA = startPointA + 5000;}
        
         if(startPointB > yLimit){
      startPointB = startPointB - 5000;}
      if(startPointB < 3000){
        startPointB = startPointB + 5000;}
        
  Serial.print("startPointA =  ");Serial.println(startPointA);
  Serial.print("startPointB =  ");Serial.println(startPointB);
//}
}



unsigned int bitOut(void)
{
  static unsigned long firstTime=1, prev=0;
  unsigned long bit1=0, bit0=0, x=0, port=0, limit=99;
  if (firstTime)
  {
    firstTime=0;
    prev=analogRead(port);
  }
  while (limit--)
  {
    x=analogRead(port);
    bit1=(prev!=x?1:0);
    prev=x;
    x=analogRead(port);
    bit0=(prev!=x?1:0);
    prev=x;
    if (bit1!=bit0)
      break;
  }
  return bit1;
}
//------------------------------------------------------------------------------
unsigned long seedOut(unsigned int noOfBits)
{
  // return value with 'noOfBits' random bits set
  unsigned long seed=0;
  for (int i=0;i<noOfBits;++i)
    seed = (seed<<1) | bitOut();
  return seed;
}
