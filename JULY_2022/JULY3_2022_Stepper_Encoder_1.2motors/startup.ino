void startup(){
  beam1State = digitalRead(beam1);
  beam2State = digitalRead(beam2);
  //****************beam1****************
  if (beam1State == 0 && beam1RoutineFinished == false) {  
        while (beam1State == 0){  //  Do until Motor position is back to ZERO
          digitalWrite(dir_pin1, LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
          for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin1, HIGH);
              delay(20);
              digitalWrite(step_pin1, LOW);
              delay(20);            
            }
            //StepperPosition1=StepperPosition1-StepsToTake;
             beam1State = digitalRead(beam1);
             Serial.print("beam1 =");Serial.println(beam1State);
             if(beam1State ==1){
              beam1RoutineFinished = true;
              StepperPosition1 = 0;
              Serial.println("hello1");
             }
        }
  }
        if(beam1State == 1 && beam1RoutineFinished == false){
          //StepperPosition1 = 0;
          //int StepperPosition1Target = 50;
          // while (StepperPosition1 != 50){  //  Do until Motor position is back to ZERO
             while (beam1State == 1){
          digitalWrite(dir_pin1, HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
          for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin1, HIGH);
              delay(20);
              digitalWrite(step_pin1, LOW);
              delay(20);            
            }
            //StepperPosition1=StepperPosition1-StepsToTake;
             beam1State = digitalRead(beam1);
             Serial.print("beam1.2 =");Serial.println(beam1State);
              if(beam1State ==0){
              beam1RoutineFinished = true;
              StepperPosition1 = 0;
             }
        }
        }
//}
/*
  if (beam1State == 1) {  // Stepper was moved CW
        while (beam1State == 1){  //  Do until Motor position is back to ZERO
          digitalWrite(dir_pin2, LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
          for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin2, HIGH);
              delay(20);
              digitalWrite(step_pin2, LOW);
              delay(20);            
            }
            StepperPosition1=StepperPosition1-StepsToTake;
             beam1State = digitalRead(beam1);
             Serial.print("beam1 =");Serial.println(beam1State);
        }
        
}
*/
//***********************************
if (beam2State == 0 && beam2RoutineFinished == false) {  // Stepper was moved CW
        while (beam2State == 0){  //  Do until Motor position is back to ZERO
          digitalWrite(dir_pin2, LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
          for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin2, HIGH);
              delay(20);
              digitalWrite(step_pin2, LOW);
              delay(20);            
            }
           // StepperPosition1=StepperPosition1-StepsToTake;
            beam2State = digitalRead(beam2);
             Serial.print("beam2 =");Serial.println(beam2State);
              if(beam2State ==1){
              beam2RoutineFinished = true;
              StepperPosition2 = 0;
             }
        }
}
if (beam2State == 1 && beam2RoutineFinished == false) {  // Stepper was moved CW
   //StepperPosition2 = 0;
        while (beam2State == 1){  //  Do until Motor position is back to ZERO
          digitalWrite(dir_pin2, HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
          for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin2, HIGH);
              delay(20);
              digitalWrite(step_pin2, LOW);
              delay(20);            
            }
           // StepperPosition1=StepperPosition1-StepsToTake;
            beam2State = digitalRead(beam2);
             Serial.print("beam2.2 =");Serial.println(beam2State);
              if(beam2State ==0){
              beam2RoutineFinished = true;
              StepperPosition2 = 0;
             }
        }
}
Serial.println("hello1");
mode1 = false;
}
