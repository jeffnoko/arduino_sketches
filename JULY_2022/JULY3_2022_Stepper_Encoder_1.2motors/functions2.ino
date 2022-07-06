void turnDetected1(){
   if (TurnDetected1)  {
    // Serial.println("Turn detected 1");
        TurnDetected1 = false;  // do NOT repeat IF loop until new rotation detected

// Which direction to move Stepper motor
        if (rotationdirection1) { // Move motor CCW  if(rotationdirection1 !=0)
            digitalWrite(dir_pin1, HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
            for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin1, HIGH);
              delay(1);
              digitalWrite(step_pin1, LOW);
              delay(1);            
            }
            StepperPosition1=StepperPosition1-StepsToTake;
           // Serial.print("StepperPosition1 = ");Serial.println(StepperPosition1);
        }

        if (!rotationdirection1) { // Move motor CW
            digitalWrite(dir_pin1, LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
            for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin1, HIGH);
              delay(1);
              digitalWrite(step_pin1, LOW); 
              delay(1);         
            }
            StepperPosition1=StepperPosition1+StepsToTake;
            //Serial.print("StepperPosition1 = ");Serial.println(StepperPosition1);
            
        }
       //Serial.print("StepperPosition1 = ");Serial.println(StepperPosition1);
} 
}

//******************turnDetected2

void turnDetected2(){
   if (TurnDetected2)  {
    // Serial.println("Turn detected 1");
        TurnDetected2 = false;  // do NOT repeat IF loop until new rotation detected

// Which direction to move Stepper motor
        if (rotationdirection2) { // Move motor CCW
            digitalWrite(dir_pin2, HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
            for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin2, HIGH);
              delay(1);
              digitalWrite(step_pin2, LOW);
              delay(1);            
            }
            StepperPosition2=StepperPosition2-StepsToTake;
           // Serial.print("StepperPosition2 = ");Serial.println(StepperPosition2);
        }

        if (!rotationdirection2) { // Move motor CW
            digitalWrite(dir_pin2, LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
            for (int x = 0; x < StepsToTake; x++) {
              digitalWrite(step_pin2, HIGH);
              delay(1);
              digitalWrite(step_pin2, LOW); 
              delay(1);         
            }
            StepperPosition2=StepperPosition2+StepsToTake;
            //Serial.print("StepperPosition2 = ");Serial.println(StepperPosition2);
            
        }
       //Serial.print("StepperPosition1 = ");Serial.println(StepperPosition1);
} 
}
