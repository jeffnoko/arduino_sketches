
void buttonResetMotor1(){
 // StepperPosition1 = 0;
  //StepperPosition2 = 0;
   if (!(digitalRead(PinSW1))) {
    //Serial.println("Button1 Pressed");// check if button is pressed
  if (StepperPosition1 == 0) {  // check if button was already pressed
  } else {
      if (StepperPosition1 > 0) {  // Stepper was moved CW
        while (StepperPosition1 != 0){  //  Do until Motor position is back to ZERO
          digitalWrite(dir_pin1, HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
          for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin1, HIGH);
              delay(10);
              digitalWrite(step_pin1, LOW);
              delay(10);            
            }
            StepperPosition1=StepperPosition1-StepsToTake;
        }
      }
      else {
        while (StepperPosition1 != 0){ 
          digitalWrite(dir_pin1, LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
              for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin1, HIGH);
              delay(10);
              digitalWrite(step_pin1, LOW);
              delay(10);            
            }
           StepperPosition1=StepperPosition1+StepsToTake;
        }
      }
      StepperPosition1=0; // Reset position to ZERO after moving motor back
    }
    //delay(200);
   // Serial.print("StepperPosition1 = ");Serial.println(StepperPosition1);
  }
}

//*******************motor2

void buttonResetMotor2(){
   if (!(digitalRead(PinSW2))) {
    //Serial.println("Button2 Pressed");// check if button is pressed
  if (StepperPosition2 == 0) {  // check if button was already pressed
  } else {
      if (StepperPosition2 > 0) {  // Stepper was moved CW
        while (StepperPosition2 != 0){  //  Do until Motor position is back to ZERO
          digitalWrite(dir_pin2, HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
          for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin2, HIGH);
              delay(10);
              digitalWrite(step_pin2, LOW);
              delay(10);            
            }
            StepperPosition2=StepperPosition2-StepsToTake;
        }
      }
      else {
        while (StepperPosition2 != 0){ 
          digitalWrite(dir_pin2, LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
              for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin2, HIGH);
              delay(10);
              digitalWrite(step_pin2, LOW);
              delay(10);            
            }
           StepperPosition2=StepperPosition2+StepsToTake;
        }
      }
      StepperPosition2=0; // Reset position to ZERO after moving motor back
    }
   // delay(200);
    //Serial.print("StepperPosition2 = ");Serial.println(StepperPosition2);
  }
}
