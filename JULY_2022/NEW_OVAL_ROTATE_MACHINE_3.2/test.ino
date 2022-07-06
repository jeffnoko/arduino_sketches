void Startup_BrushDip2(){
  stepper3.moveTo(-300);
  zLimitSwitchReading = digitalRead(zLimitSwitch);
  delay(200);
   servo1.attach(10);
 
   Serial.print("z=  ");   Serial.println(z);
  servo1.write(50);

      
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
