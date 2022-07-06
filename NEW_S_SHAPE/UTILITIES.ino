
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
   stepper3.setMaxSpeed(100);
  stepper3.setAcceleration(100);
  stepper3.moveTo(30);
  stepper3.runToPosition();
  }
void s1down(){
   stepper3.setMaxSpeed(100);
  stepper3.setAcceleration(100);
   stepper3.moveTo(0);
  stepper3.runToPosition();
}

void Startup_BrushDip(){
   randomCup = random(1,5);
   if(randomCup == 1){cupPos = 97;}
    if(randomCup == 2){cupPos = 118;}
     if(randomCup == 3){cupPos = 140;}
      if(randomCup == 4){cupPos = 170;}
      
  stepper3.moveTo(-300);
  zLimitSwitchReading = digitalRead(zLimitSwitch);
  delay(200);
   servo1.attach(8);
 
    
  servo1.write(30);

      
  while(zLimitSwitchReading == 1){///////////////////////////////////////
    // stepper3.moveTo(-100);
    
    stepper3.run();
     zLimitSwitchReading = digitalRead(zLimitSwitch);
     Serial.println("inside loop  ");
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
   for(pos = 30; pos<= cupPos; pos+=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
 //  servo1.write(0); 
  // delay(100);
 
  stepper3.runToNewPosition(50);
  delay(500);
  
  stepper3.runToNewPosition(170);
  for(pos = cupPos; pos>=30; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  }
  stepper3.runToNewPosition(30); 
   //Serial.println("outside while loop3");
}

void BrushDip(){
   servo1.attach(8);
    stepper3.runToNewPosition(170);
    randomCup = random(1,5);
   if(randomCup == 1){cupPos = 100;}
    if(randomCup == 2){cupPos = 120;}
     if(randomCup == 3){cupPos = 145;}
      if(randomCup == 4){cupPos = 170;}
      servo1.write(30); 
     delay(200); 
 x = pos1x;
 y = pos1y;
  z = 170;
     positions[0] = x;
  positions[1] = y;
   positions[2] = z;  
 // steppers.moveTo(positions);
 // steppers.runSpeedToPosition();
 
  
  //Serial.print(" z after run call stepper3 (170 =   ");Serial.println(z);
  delay(100);
   for(pos = 30; pos<=cupPos; pos+=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
   //servo1.write(0); 
   delay(100);
     stepper3.runToNewPosition(50);
     delay(500);
       stepper3.runToNewPosition(170);
    //stepper3.setMaxSpeed(100);
    z = 90;
     positions[0] =  x;
  positions[1] =  y  ;
   positions[2] =  z;  
  //steppers.moveTo(positions);
  //steppers.runSpeedToPosition();
// steppers.runToPosition();
 // stepper3.runToNewPosition(90);
  delay(500);
  
   z = 170;
     positions[0] =  x;
  positions[1] =  y  ;
   positions[2] =  z;  
   // stepper3.setMaxSpeed(100);
 // steppers.moveTo(positions);
  //steppers.runSpeedToPosition();
 // stepper3.runToNewPosition(170);
  for(pos = cupPos; pos>=30; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
 // servo1.write(30);
   // stepper3.runToNewPosition(0);
    delay(500);
  // Serial.println("outside while loop3");
}


void joystick2(){

 // p1 = 0;
 // p2 = 0;
 button4 = digitalRead(34);
  button5 = digitalRead(36);
  unsigned long current_time = millis(); 
  if (current_time - last_input_time > INPUT_READ_INTERVAL) 
  { 
    joystick_in1 = analogRead(A8); 
    joystick_in2 = analogRead(A9); 

    desired_speed1 = map(joystick_in1, 13, 1016, -MAX_SPEED, MAX_SPEED); 
    desired_speed2 = map(joystick_in2, 4, 1017, -MAX_SPEED, MAX_SPEED); 

       if (desired_speed1 >-35 && desired_speed1 <35){
      desired_speed1 = 0;
       } 
       if (desired_speed2 >-50 && desired_speed2 <35){
      desired_speed2 = 0;
       }  

       if(button4 == 0){
      stepper3.moveTo(40);
       }
      else{ 
      stepper3.moveTo(0);
      }
      
      if(button5 == 0){
        BrushDip();
      }

    stepper1.setMaxSpeed(abs(desired_speed1)); 
    stepper2.setMaxSpeed(abs(desired_speed2)); 


    if (desired_speed1 == 0 && stepper1.speed() == 0) 
    { 

      stepper1.setCurrentPosition(0); 
    } 
    else if (desired_speed1 < 0) 
    { 
      stepper1.moveTo(testX); 
    } 
    else if (desired_speed1 > 0) 
    { 
      stepper1.moveTo(-testX); 
    } 

    if (desired_speed2 == 0 && stepper2.speed() == 0) 
    { 

      stepper2.setCurrentPosition(0); 
    } 
    else if (desired_speed2 < 0) 
    { 
      stepper2.moveTo(-testY);
    } 
    else if (desired_speed2 > 0) 
    { 
      stepper2.moveTo(testY); 
    } 

last_input_time = current_time; 

} 

  stepper1.run(); 
  stepper2.run();
  stepper3.run(); 

}


void checkForJoystick(){
   button2 = digitalRead(26);
  if(button2 == 0){
    buttonState = !buttonState;
//Serial.println("buttonState1 = ");Serial.println(buttonState );}

  while(buttonState == 1){
  joystick_in1 = analogRead(A8); 
  joystick_in2 = analogRead(A9);
  joystick2();
   button3 = digitalRead(28);
    if(button3 == 0){
      buttonState = !buttonState;
       stepper1.setMaxSpeed(800);
  stepper2.setMaxSpeed(800);
      }
  //Serial.println("button3 = ");Serial.println(button3 );
      }
}
  
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
  
