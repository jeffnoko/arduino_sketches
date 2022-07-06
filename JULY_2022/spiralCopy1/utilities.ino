
unsigned int bitOut(void)
{
  static unsigned long firstTime=1, prev=0;
  unsigned long bit1=0, bit0=0, x=0, port=2, limit=99;
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
void s1up(){
   stepper3.setMaxSpeed(800);
  stepper3.setAcceleration(800);
  stepper3.moveTo(400);
  stepper3.runToPosition();
  }
void s1down(){
   stepper3.setMaxSpeed(800);
  stepper3.setAcceleration(800);
   stepper3.moveTo(0);
  stepper3.runToPosition();
}
void Startup_BrushDip(){
  stepper3.moveTo(-300);
  zLimitSwitchReading = digitalRead(zLimitSwitch);
  delay(200);
   servo1.attach(10);
 
    
  servo1.write(50);

      
  while(zLimitSwitchReading == 1){///////////////////////////////////////
    // stepper3.moveTo(-100);
    
    stepper3.run();
     zLimitSwitchReading = digitalRead(zLimitSwitch);
     //Serial.println("inside loop  ");
     //delay(1);
     //Serial.println(zLimitSwitchReading);
  }//.....................................................1.............
   //delay(500);
    Serial.println("outside while loop");
   stepper3.setCurrentPosition(0);
  stepper3.setMaxSpeed(100);
 stepper3.runToNewPosition(170);
  Serial.println("outside while loop2");
  delay(100);
   for(pos = 50; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
 //  servo1.write(0); 
  // delay(100);
 
  stepper3.runToNewPosition(90);
  delay(500);
  
  stepper3.runToNewPosition(170);
  for(pos = 0; pos<=50; pos+=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  stepper3.runToNewPosition(30); 
   //Serial.println("outside while loop3");
}


void BrushDip(){
  // Serial.println("inside brushdip       ");
  //  Serial.print(" z = ");Serial.println(z);
 // stepper3.moveTo(-300);
 // zLimitSwitchReading = digitalRead(zLimitSwitch);
 // delay(200);
   servo1.write(50); 
  
 

  //stepper3.setMaxSpeed(100);
   //stepper3.moveTo(170);
 //stepper3.runToPosition(170);
 z = 170;
     positions[0] =  x;
  positions[1] =  y  ;
   positions[2] =  z;  
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
 
  
  Serial.print(" z after run call stepper3 (170 =   ");Serial.println(z);
  delay(100);
   for(pos = 50; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
   //servo1.write(0); 
   delay(100);
    //stepper3.setMaxSpeed(100);
    z = 90;
     positions[0] =  x;
  positions[1] =  y  ;
   positions[2] =  z;  
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
// steppers.runToPosition();
 // stepper3.runToNewPosition(90);
  delay(500);
  
   z = 170;
     positions[0] =  x;
  positions[1] =  y  ;
   positions[2] =  z;  
   // stepper3.setMaxSpeed(100);
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
 // stepper3.runToNewPosition(170);
  for(pos = 0; pos<=50; pos+=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  // Serial.println("outside while loop3");
}

 /*
  button1Reading = digitalRead(A5);
  if (button1Reading == HIGH && button1Previous == LOW && millis() - time > debounce) {
    if (button1State == HIGH){
      button1State = LOW;
    }
    else
      button1State = HIGH;
    time = millis();    
  }

  button1Previous = button1Reading;

  if (button1State == HIGH ){      }
  
  */
  
