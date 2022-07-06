
// steppers.addStepper(stepper1);
 // steppers.addStepper(stepper2);
  // steppers.addStepper(stepper3);

 //long positions[2];
void circle1(){
 int x,y;
  int length = 200;//random(300,1000);
  float angle = 0.0;
   //float angle = 2*PI/4;
 // float angle_stepsize = PI/4;
 float angle_stepsize = 0.05;

  /// float angle = PI/2;
 // float angle_stepsize = PI/6;

  while (angle < 2 * PI)
  {
    //calculate x , y from a vector with known lenght and angle
    x = length * cos (angle);
    y = length * sin (angle);
    
    
   positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] = z;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
    
    // for Processing  
    // putpixel (screen, x + SCREEN_W / 2, y + SCREEN_H / 2,
    // makecol (255, 255, 255));
    
    angle += angle_stepsize;
    //length = length - 20;
  }

}
//==========================***********START**************==========================
void circle2(){
 int speedX = analogRead(pot3);
 int speedY = analogRead(pot4);
 speedX = map(speedX,0,1023,0,25);
 speedY = map(speedY,0,1023,0,25);
currentMillis4 = millis();
currentMillis5 = millis();
circleXInterval = speedX;
circleYInterval = speedY;
z = 0;

if(stepper1.currentPosition() == x && stepper2.currentPosition() == y){   //Serial.println("hello1");
if(angle < tau && (currentMillis4 - previousMillis4) >= circleXInterval){//Serial.println("hello1");
  previousMillis4 += circleXInterval;
   x = centerX + lengthX * cos (angle);
   stepper1.moveTo(x);
    //Serial.println(" inside if #1 x ");
    //Serial.print("x = ");Serial.println(x);
}

if(angle < tau && (currentMillis5 - previousMillis5) >= circleYInterval){
  previousMillis5 += circleYInterval;
   y = centerY + lengthY * sin (angle);
   stepper2.moveTo(y);
   //Serial.println(" inside if #2 y ");
}

}


  
    
    
    //Serial.print("angle = ");Serial.println(angle);
    angle += angle_stepsize;
   
    //Serial.print("circleInterval = ");Serial.println(circleInterval);
    //Serial.print("positions[3] ");Serial.println(z);
   //Serial.print("angle = ");Serial.println(angle);
   if(angle >= tau){
  centerX = random(50,300);
  centerY = random(50,300);
  lengthX = random(100,300);
  lengthY = random(100,300);
  //Serial.println(" inside if #3 circle finished ");
  //Serial.print("centerX = ");Serial.println(centerX);
}

  if (angle >= tau){
    angle = 0;
  }

}
//==========================***********END**************==========================
//==========================***********START**************==========================
void circle3(){
 int speedX = analogRead(pot3);
 int speedY = analogRead(pot4);
 speedX = map(speedX,0,1023,0,2000);
 speedY = map(speedY,0,1023,0,2000);
currentMillis4 = millis();
currentMillis5 = millis();
circleXInterval = speedX;
circleYInterval = speedY;
z = 0;

if(stepper1.distanceToGo() == 0 && stepper2.distanceToGo() == 0){//   Serial.println("hello1");
if(angle < tau && (currentMillis4 - previousMillis4) >= circleXInterval){//Serial.println("hello2");
  previousMillis4 += circleXInterval;
   x = centerX + lengthX * cos (angle);
   stepper1.moveTo(x);
    //Serial.println(" inside if #1 x ");
    //Serial.print("x = ");Serial.println(x);
    //Serial.print("centerX = ");Serial.println(centerX);
}

if(angle < tau && (currentMillis5 - previousMillis5) >= circleYInterval){
  previousMillis5 += circleYInterval;
   y = centerY + lengthY * sin (angle);
   stepper2.moveTo(y);
   //Serial.println(" inside if #2 y ");
}
//angle += angle_stepsize;
}


  
    
    
    //Serial.print("angle = ");Serial.println(angle);
    angle += angle_stepsize;
   
    //Serial.print("circleInterval = ");Serial.println(circleInterval);
    //Serial.print("positions[3] ");Serial.println(z);
   //Serial.print("angle = ");Serial.println(angle);
   if(angle >= tau){
  centerX = random(50,300);
  centerY = random(50,300);
  lengthX = random(100,300);
  lengthY = random(100,300);
  //Serial.println(" inside if #3 circle finished ");
 // Serial.print("centerX = ");Serial.println(centerX);
  //Serial.print("x = ");Serial.println(x);
  //Serial.print(" stepper1.currentPosition()= ");Serial.println(stepper1.currentPosition());
  angle = 0;
}

 // if (angle >= tau){
  //  angle = 0;
 // }

}
//==========================***********END**************==========================
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
