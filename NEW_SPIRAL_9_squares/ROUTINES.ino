//SQUARE WITH ROUNDED CORNERS
void clockwise_square(){
int side1 = random(-500,1000);
int side2 = random(-500,1000);;
int startpointx = random(-1000,1000);
int startpointy = random(-1000,1000);
int pause = 0;
 x = startpointx;
    y = startpointy;
    z = 50;
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
   x = startpointx;
    y = startpointy;
    z = 0;
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();

 x = startpointx + side1;
    y = startpointy;
    z = 0;
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  delay(pause);
  y = startpointy + side2;
  
   positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  delay(pause);
  x = startpointx;
  
   positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  delay(pause);
   x = startpointx;
   y = startpointy;
  
   positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  delay(pause);
  z = 50;
    positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
}

//alphabete
void alphabete(){
int side1 = 100;
int side2 = 200;
int startpointx = 0;
int startpointy = 0;
int pause = 200;
int touchPoint = 5;
 x = startpointx;
    y = startpointy;
    z = 50;
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
   x = startpointx;
    y = startpointy;
    z = touchPoint;
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();

 x = startpointx + side1;
    y = startpointy;
    z =  touchPoint;
     positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  delay(pause);
  y = startpointy + side2;
  
   positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  delay(pause);
  x = startpointx;
  
   positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  delay(pause);
   x = startpointx;
   y = startpointy;
  
   positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  delay(pause);
  z = 50;
    positions[0] =  x;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  y ;//stepper#2 up down
   positions[2] =  z ;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
}

