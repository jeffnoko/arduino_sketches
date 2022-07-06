

void setZ0(){
  /*use a button. use the tilt servo to put the brush to the back position.
   * read pot1 and move z down until it touches the surface. press button to set zero.
   * stepper3.setCurrentPosition(0);
   * 
   */
  // buttonState1 = digitalRead(button1);
  // stepper3.setCurrentPosition(0);
  // while(buttonState1 == 1){
   // int zReading = counter2;
   // joystickPanTilt();

   // zReading = map(zReading,5,895, 100,-100);
 // if(zReading >= -10 && zReading <= 10){
   // zReading = 0;
 // }
  newZReading = counter2 *10;
 if(newZReading != previousZReading){
  stepper3.moveTo(newZReading);
   // stepper3.run();
    //previousZReading = newZReading;
    //newZReading = counter2 *10;
 }
 previousZReading = newZReading;
 // zReading = counter2 *10;
   // stepper3.moveTo(zReading);
   // stepper3.run();
   // buttonState1 = digitalRead(button1);
    //Serial.print("zReading =");Serial.println(zReading);
   }
   
//===================================================================
   
  void zLift(){

   // if(newZReading != previousZReading){
   // newZReading = counter2 *10;}
  if (stepper1.isRunning()==0 && stepper2.isRunning()==0){
   //zCurrentPos = stepper3.currentPosition();
  
   stepper3.moveTo( newZReading-300);
  stepper3.run();}
  else{
  
  stepper3.moveTo(newZReading);
  stepper3.run();
  }
  }

   void zLiftV2(){
 
    
    buttonState3 = digitalRead(button3);
  if (stepper1.isRunning()==1 || stepper2.isRunning()==1 && buttonState3 == 1){// moving with no button press
   
  stepper3.moveTo( newZReading);
  //stepper3.run();
  }
 // else{
  
  //stepper3.moveTo(newZReading - 300);
 // stepper3.run();
 // }

   if (stepper1.isRunning()==1 || stepper2.isRunning()==1 && buttonState3 == 0){//moving with button press
   
  stepper3.moveTo( newZReading -300);
  //stepper3.run();
  }
  //else{
  
 // stepper3.moveTo(newZReading - 300);
  //stepper3.run();
  //}

   if (stepper1.isRunning()==0 && stepper2.isRunning()==0 && buttonState3 == 1){//stopped with no button press
   
  stepper3.moveTo( newZReading -300);
  //stepper3.run();
  }
  }
  
//====================================================================
void zAxis(){
  int zReading = analogRead(pot1);
  zReading = map(zReading,5,895, -100,100);
  if(zReading >= -10 && zReading <= 10){
    zReading = 0;
  }
  //Serial.print("zReading = ");Serial.println(zReading);
//stepper3.setCurrentPosition(0);

  
}

void enable1(){
  int previousEnableTime;
int enableTime = millis();
if(stepper1.isRunning()==0 && stepper2.isRunning()==0 && stepper3.isRunning() == 0 && enableTime - previousEnableTime == 2000){
  digitalWrite(enablePin,LOW);}
  else{
    digitalWrite(enablePin,HIGH);
  }
 previousEnableTime = enableTime; 
}
  
//}
