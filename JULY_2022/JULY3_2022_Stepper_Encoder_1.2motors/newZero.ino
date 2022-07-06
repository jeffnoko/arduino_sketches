void newZero(){
 // newZeroX = StepperPosition1 + 20;
 // newZeroY = StepperPosition2 + 20;
   if (StepperPosition1 < newZeroX) {  // Stepper was moved CW
  // if(StepperPosition1 != newZeroX || StepperPosition2 != newZeroY){
        while (StepperPosition1 != newZeroX || StepperPosition2 != newZeroY){  //  Do until Motor position is back to ZERO
          digitalWrite(dir_pin1, HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
          digitalWrite(dir_pin2, HIGH);
          for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin1, HIGH);
              delay(10);
              digitalWrite(step_pin1, LOW);
              delay(10);  
              digitalWrite(step_pin2, HIGH);
              delay(10);
              digitalWrite(step_pin2, LOW);
              delay(10);            
            }
            StepperPosition1=StepperPosition1+StepsToTake;
            StepperPosition2=StepperPosition2+StepsToTake;
            /*
            if(StepperPosition1 == newZeroX && StepperPosition2 == newZeroY){
              StepperPosition1 = 0;
              StepperPosition2 = 0;
              newZeroX = 0;
              newZeroY = 0;
            }
            */
        }
       // StepperPosition1 = 0;
        //StepperPosition2 = 0;
      }
       //StepperPosition1 = 0;
       // StepperPosition2 = 0;
       Serial.println("hello2");
       Serial.print("newZeroX = ");Serial.print(newZeroX);
       Serial.print("     ");
       Serial.print("newZeroY = "); Serial.print(newZeroY);
       Serial.print("     ");
       Serial.print("StepperPosition1 = "); Serial.println(StepperPosition1);
  
}
//*********************
void newZero2(){
 // newZeroX = StepperPosition1 + 20;
 // newZeroY = StepperPosition2 + 20;
   if (StepperPosition1 < newZeroX) {  // Stepper was moved CW
  // if(StepperPosition1 != newZeroX || StepperPosition2 != newZeroY){
        while (StepperPosition1 != newZeroX || StepperPosition2 != newZeroY){  //  Do until Motor position is back to ZERO
          digitalWrite(dir_pin1, HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
          digitalWrite(dir_pin2, HIGH);
          for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin1, HIGH);
              delay(10);
              digitalWrite(step_pin1, LOW);
              delay(10);  
              digitalWrite(step_pin2, HIGH);
              delay(10);
              digitalWrite(step_pin2, LOW);
              delay(10);            
            }
            StepperPosition1=StepperPosition1+StepsToTake;
            StepperPosition2=StepperPosition2+StepsToTake;
            /*
            if(StepperPosition1 == newZeroX && StepperPosition2 == newZeroY){
              StepperPosition1 = 0;
              StepperPosition2 = 0;
              newZeroX = 0;
              newZeroY = 0;
            }
            */
        }
       // StepperPosition1 = 0;
        //StepperPosition2 = 0;
      }
       //StepperPosition1 = 0;
       // StepperPosition2 = 0;
       Serial.println("hello2");
  
}
