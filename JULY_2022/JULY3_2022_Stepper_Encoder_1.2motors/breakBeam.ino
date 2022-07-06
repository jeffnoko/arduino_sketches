// pin #1 and pin #5
/*
 start program
 to find zero
 check to see if beam is broken
 if yes
 move counter clockwise until beam is not broken.

 if no
  move clockwise until beam is broken.

 

 void breakbeam(){
  if(digitalRead(beam1 == 0){
    Serial.println("beam1 is broken");
  }
   if(digitalRead(beam2 == 0){
    Serial.println("beam2 is broken");
  }
 }
*/
void breakBeam(){
  // int
  beam1State = digitalRead(beam1);
  beam2State = digitalRead(beam2);
//int beam2 = 5;
//digitalRead(beam1);
delay(10); 
/*
if (beamState1 > 0) {  // Stepper was moved CW
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

*/
 // int beam2State = digitalRead(beam2);
  //if(beam1 == 1){
    //Serial.println("beam1 is broken");
 // }
  // if(beam2 == 1){
    //Serial.println("beam2 is broken");
  //}
  //Serial.print("beam1 =");Serial.print(beam1State);
  //Serial.print("    ");
  //Serial.print("beam2 =");Serial.println(beam2State);
 }
