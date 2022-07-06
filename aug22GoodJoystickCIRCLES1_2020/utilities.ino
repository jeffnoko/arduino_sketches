
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
void s1up(){
   stepper3.setMaxSpeed(800);
  stepper3.setAcceleration(800);
  stepper3.moveTo(100);
  stepper3.runToPosition();
  }
void s1down(){
   stepper3.setMaxSpeed(800);
  stepper3.setAcceleration(800);
   stepper3.moveTo(0);
  stepper3.runToPosition();
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
   void joystick(){
     p1 = 0;
      p2 = 0;
   sensorValue1 = analogRead(A15);//delay(50);
sensorValue2 = analogRead(A14);//delay(50);
if(sensorValue2 < 450 && sensorValue1 > 500 && sensorValue1 < 550 ) {
   currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
   previousMillis = currentMillis; 
   sensorValue1 = analogRead(A15);
  sensorValue2 = analogRead(A14);
  }
  

// stepper1.move(-10000); //x = 1;
 
// stepper1.run();
p1 = p1 - 10;
//Serial.print(" p = "); Serial.println( p );delay(500);
 
}
if(sensorValue2 < 500 && sensorValue1 > 550  ) {
   currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
   previousMillis = currentMillis; 
   sensorValue1 = analogRead(A15);
  sensorValue2 = analogRead(A14);
  }
  
  
 

// stepper1.move(-10000); //x = 1;
//  stepper2.move(-10000);
 
// stepper1.run();
 // stepper2.run();
 p1 = p1 - 10;
  p2 = p2 - 10;
 
}
if(sensorValue2 < 500 && sensorValue1 < 500  ) {
    currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
   previousMillis = currentMillis; 
   sensorValue1 = analogRead(A15);
  sensorValue2 = analogRead(A14);
  }
  
 

// stepper1.move(-10000); //x = 1;
 // stepper2.move(10000);
 
 //stepper1.run();
 // stepper2.run();
  p1 = p1 - 10;
  p2 = p2 + 10;
 
}
if(sensorValue2 > 550 && sensorValue1 > 500 && sensorValue1 < 550 ) {
    currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
   previousMillis = currentMillis; 
   sensorValue1 = analogRead(A15);
  sensorValue2 = analogRead(A14);
  }
 

// stepper1.move(10000); //x = 1;
 
// stepper1.run();
 p1 = p1 + 10;
 // p2 = p2 - 10;

}
if(sensorValue2 > 550 && sensorValue1 > 550  ) {
    currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
   previousMillis = currentMillis; 
   sensorValue1 = analogRead(A15);
  sensorValue2 = analogRead(A14);
  }
 

 //stepper1.move(10000); //x = 1;
 // stepper2.move(-10000);
 
 //stepper1.run();
 // stepper2.run();
  p1 = p1 + 10;
  p2 = p2 - 10;
 
}
if(sensorValue2 > 550 && sensorValue1 < 500  ) {
    currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
   previousMillis = currentMillis; 
   sensorValue1 = analogRead(A15);
  sensorValue2 = analogRead(A14);
  }
 

 //stepper1.move(10000); //x = 1;
 // stepper2.move(10000);
 
// stepper1.run();
 // stepper2.run();
  p1 = p1 + 10;
  p2 = p2 + 10;
 
 
}
if(sensorValue1 > 550 && sensorValue2 < 550 && sensorValue2 > 500 ) {
    currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
   previousMillis = currentMillis; 
   sensorValue1 = analogRead(A15);
  sensorValue2 = analogRead(A14);
  }
  
// stepper2.move(-10000); //x = 1;
 
// stepper2.run();
// p1 = p1 - 10;
  p2 = p2 - 10;
 
}
if(sensorValue1 < 500 && sensorValue2 < 550 && sensorValue2 > 500 ) {
    currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
   previousMillis = currentMillis; 
   sensorValue1 = analogRead(A15);
  sensorValue2 = analogRead(A14);
  }
  

 //stepper2.move(10000); //x = 1;
 
// stepper2.run();
// p1 = p1 - 10;
  p2 = p2 + 10;
 
}
   }
   
   
    void joystick2(){
      
       p1 = 0;
      p2 = 0;
   unsigned long current_time = millis(); 
  if (current_time - last_input_time > INPUT_READ_INTERVAL) 
  { //delay(500);
     joystick_in1 = analogRead(JOYSTICK_PIN1); 
      joystick_in2 = analogRead(JOYSTICK_PIN2); 
    //Serial.print(" p = "); Serial.println(joystick_in);delay(500);
    // Map the raw analog value to speed range from -MAX_SPEED to MAX_SPEED 
    desired_speed1 = map(joystick_in1, 0, 1023, -MAX_SPEED, MAX_SPEED); 
      desired_speed2 = map(joystick_in2, 0, 1023, -MAX_SPEED, MAX_SPEED); 
     // int desired_speed2 = map(joystick_in2, 0, 1032, -MAX_SPEED, MAX_SPEED);
      if (desired_speed2 >-30 && desired_speed2 <30){desired_speed2 = 0;}  
   // Serial.print(desired_speed2);
   // Serial.print("  desired_speed1 =                ");Serial.println(desired_speed1);
   //  Serial.print("  desired_speed2 =                ");Serial.println(desired_speed2);
    //Serial.println(stepper2.speed()); 
     // Serial.print(desired_speed2);
    //Serial.print("                  ");
    //Serial.println(stepper2.speed()); 

    // Based on the input, set targets and max speed 
    stepper1.setMaxSpeed(abs(desired_speed1)); 
     stepper2.setMaxSpeed(abs(desired_speed2)); 
     
     
    if (desired_speed1 == 0 && stepper1.speed() == 0) 
    { 
      // Prevent running off the end of the position range 
        stepper1.setCurrentPosition(0); 
    } 
    else if (desired_speed1 < 0) 
    { 
      stepper1.moveTo(-testX); 
    } 
    else if (desired_speed1 > 0) 
    { 
      stepper1.moveTo(testX); 
    } 
   // last_input_time = current_time;
   
   
    
    
    
     //if (desired_speed2 == 17 && stepper2.speed() == 17) 
      if (desired_speed2 >0 &&desired_speed2 <35 && stepper2.speed() > 0 && stepper2.speed()<35) 
    { 
      // Prevent running off the end of the position range 
        stepper2.setCurrentPosition(0); 
    } 
    else if (desired_speed2 < -35) 
    { 
      stepper2.moveTo(testY); 
    } 
    else if (desired_speed2 > 35) 
    { 
      stepper2.moveTo(-testY); 
    } 
   
   
   
   
    last_input_time = current_time; 
    
    
    
    
    
   stepper3.moveTo(voltageS); 
  } 
 //Serial.print("testX =    ");
   //  Serial.println(testX);
    //  Serial.print("testY =    ");
    // Serial.println(testY);
     
     //Serial.print("stepper1 =    ");
    // Serial.println(stepper1.currentPosition());
     int newX = stepper1.currentPosition();
      int newY = stepper2.currentPosition();
      // Serial.print("stepper1 =    ");
     //Serial.println(stepper1.currentPosition());
     // Serial.print("stepper2 =    ");
    // Serial.println(stepper2.currentPosition());
// Serial.println("hello");
  stepper1.run(); 
   stepper2.run();
  stepper3.run(); 
   //stepper1.setCurrentPosition(0); 
   // stepper2.setCurrentPosition(0); 
    }
  
