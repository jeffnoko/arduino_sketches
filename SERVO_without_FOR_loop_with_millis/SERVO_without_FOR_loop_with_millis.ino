void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

/*
 * NOTES ON USING SERVO WITHOUT FOR LOOP, USING MILLIS THE SAME AS BLINK WITHOUT DELAY
 * 
 * 
 * void loop()
{
  //the stepper motor part of the code
  //...

  //the servo part.
  //replace your for loop with this code:
  if ((millis() - lastServoMove) > 15)  //if more than 15ms passed since the last servo move
  {
    myservo.write(pos)

    lastServoMove = millis();    //reset the timer
    pos += 1;

    if (pos == 78)
      pos = 3;  //reset the servo position
  }
  //end of servo part

......................................

if(stepper.distanceToGo() == 0)
{
        delay(1000);
        stepper.moveTo(148);
        stepper.setMaxSpeed(80);
        stepper.setAcceleration(50);
}
while(stepper.run());  //while loop ends once the stepper has reached its target


 for(pos = 3; pos<78; pos+=1)     // goes from 180 degrees to 0 degrees
  {                            
   
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}



.......................................

You can also use

stepper.runToPosition();

instead of

while(stepper.run());

(its a bit clearer and saves a tiny bit of code)





}



 */
