

void setZ0(){
 
 
  newZReading = counter2 *10;
 if(newZReading != previousZReading){
  stepper3.moveTo(newZReading);
   
 }
 previousZReading = newZReading;
 
   }
   
//===================================================================
   
  void zLift(){

  
  if (stepper1.isRunning()==0 && stepper2.isRunning()==0){
  
  
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
 
  }


   if (stepper1.isRunning()==1 || stepper2.isRunning()==1 && buttonState3 == 0){//moving with button press
   
  stepper3.moveTo( newZReading -300);
  
  }
  

   if (stepper1.isRunning()==0 && stepper2.isRunning()==0 && buttonState3 == 1){//stopped with no button press
   
  stepper3.moveTo( newZReading -300);
 
  }
  }

  //===================================================================
   void zLiftV3(){
 
    
    buttonState3 = digitalRead(button3);
  if (stepper1.isRunning()==1 || stepper2.isRunning()==1){// moving with no button press
    if(buttonState3 == 1){
   
  stepper3.moveTo( newZReading);
    }
    
 
  }
else{
  stepper3.moveTo( newZReading -300);
}

  
  }
  
//====================================================================
void zAxis(){
  int zReading = analogRead(pot1);
  zReading = map(zReading,5,895, -100,100);
  if(zReading >= -10 && zReading <= 10){
    zReading = 0;
  }
 

  
}

void enable1(){
  int previousEnableTime;
int enableTime = millis();
if(stepper1.isRunning()==0 && stepper2.isRunning()==0 && stepper3.isRunning() ==0 && enableTime - previousEnableTime == 2000){
  digitalWrite(enablePin,LOW);}
  else{
    digitalWrite(enablePin,HIGH);
  }
 previousEnableTime = enableTime; 
}
//=====================================
void zBounce (){
  //bool counter1 = true;
   //if (stepper3.distanceToGo() == 0)
     // stepper3.moveTo(-stepper3.currentPosition());

       if (counter == true){
      stepper3.moveTo(A);}
       
       if (stepper3.currentPosition() == A){
     counter = false;
       }
      if( counter == false){
        stepper3.moveTo(B);
      }
       if (stepper3.currentPosition() == B){
     counter = true;
      
}
}
  
