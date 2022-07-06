

void joystickPanTilt() {
  unsigned long current_time = millis();
  if (current_time - last_input_time > INPUT_READ_INTERVAL)
  {
    int joystick_in1 = analogRead(JOYSTICK_PIN3);
    int joystick_in2 = analogRead(JOYSTICK_PIN4);
  // int pan = joystick_in1;
  //int tilt = joystick_in2;

    int pan = map(joystick_in1, 30, 880, 115 , 180); //motor #2 range of motion 180,100 original
    //pan 100,180    . tilt 80,0 is for coordinating with the direction on the steppers
    int tilt = map(joystick_in2, 8, 880, 80, 30 ); //motor #3   range of motion 0,80 original
    //int brushTipTilt = map( tilt,0,80,-180,180);  //motor #1
   // int brushTipPan = map( pan,180,100,-180,180);  //motor #1


   

    int brushTipTilt = map( tilt,0,80,180,120);  //motor #1   tilt,0,80,180,-120 original
    int brushTipPan = map( pan,180,100,180,-180);  //motor #1 180,-180

    brushTipTilt = abs(brushTipTilt);
    brushTipPan = abs(brushTipPan);

int brushTip = (brushTipPan + brushTipTilt) ;
brushTip = map(brushTip,0,200,150,0);//14,280,180,0
   
    brushTip = abs(brushTip);
    //servo1.write(brushTip);
     servo1.write(brushTip);
    servo2.write(pan);
    servo3.write(tilt);
//Serial.print("tilt = "); Serial.println(tilt);



    last_input_time = current_time;

  }
}


//================================================

void joystickPanTilt2() {
  unsigned long current_time = millis();
  if (current_time - last_input_time > INPUT_READ_INTERVAL)
  {
    int joystick_in3 = analogRead(JOYSTICK_PIN3);
    int joystick_in4 = analogRead(JOYSTICK_PIN4);
  // int pan = joystick_in1;
  //int tilt = joystick_in2;

    int pan = map(joystick_in3, 30, 880, 115 , 180); //motor #2 range of motion 180,100 original
    //pan 100,180    . tilt 80,0 is for coordinating with the direction on the steppers
    int tilt = map(joystick_in4, 8, 880, 80, 30 ); //motor #3   range of motion 0,80 original
    //int brushTipTilt = map( tilt,0,80,-180,180);  //motor #1
   // int brushTipPan = map( pan,180,100,-180,180);  //motor #1


   

    int brushTipTilt = map( tilt,0,80,180,120);  //motor #1   tilt,0,80,180,-120 original
    int brushTipPan = map( pan,180,100,180,-180);  //motor #1 180,-180

    brushTipTilt = abs(brushTipTilt);
    brushTipPan = abs(brushTipPan);

int brushTip = (brushTipPan + brushTipTilt) ;
brushTip = map(brushTip,0,200,150,0);//14,280,180,0
   
    brushTip = abs(brushTip);
    //servo1.write(brushTip);
     servo1.write(brushTip);
    servo2.write(pan);
    servo3.write(tilt);
//Serial.print("tilt = "); Serial.println(tilt);



    last_input_time = current_time;

  }
}

//=============================================================
//servoSweep

void servoSweep1() {
 currentMillis1 = millis();
  currentMillis2 = millis();
  currentMillis3 = millis();

  minDegrees = analogRead(pot1);
maxDegrees = analogRead(pot2);
slowInterval = analogRead(pot3);
fastInterval = analogRead(pot4);

minDegrees = map(minDegrees,0,1023,0,90);
maxDegrees = map(maxDegrees,0,1023,90,180);
slowInterval = map(slowInterval,0,1023,5,500);
fastInterval = map(fastInterval,0,1023,5,500);


  //==================================START SERVO1 IF STATEMENTS
  if (currentMillis1 - previousServo1Millis >= servo1Interval) {
    previousServo1Millis += servo1Interval;
    servo1Pos = servo1Pos + servo1Degrees;
    if (servo1Pos <= minDegrees) {
      if (servo1Interval == slowInterval) {
        servo1Interval = fastInterval;
      }
      else {
        servo1Interval = slowInterval;
      }
    }
    if ((servo1Pos >= maxDegrees) || (servo1Pos <= minDegrees))  {
      servo1Degrees = - servo1Degrees; // reverse direction
      servo1Pos = servo1Pos + servo1Degrees;
    }
    Serial.print("servo1Pos = ");Serial.println(servo1Pos);
    servo1.write(servo1Pos);
  }

  //=========================================END SERVO1 IF STATEMENTS
  //==================================START SERVO2 IF STATEMENTS
  if (currentMillis2 - previousServo2Millis >= servo2Interval) {
    previousServo2Millis += servo2Interval;
    servo2Pos = servo2Pos + servo2Degrees;
    if (servo2Pos <= servo2MinDegrees) {
      if (servo2Interval == servo2SlowInterval) {
        servo2Interval = servo2FastInterval;
      }
      else {
        servo2Interval = servo2SlowInterval;
      }
    }
    if ((servo2Pos >= servo2MaxDegrees) || (servo2Pos <= servo2MinDegrees))  {
      servo2Degrees = - servo2Degrees; // reverse direction
      servo2Pos = servo2Pos + servo2Degrees;
    }
    servo2.write(servo2Pos);
  }

  //=========================================END SERVO2 IF STATEMENTS
  //==================================START SERVO3 IF STATEMENTS
  if (currentMillis3 - previousServo3Millis >= servo3Interval) {
    previousServo3Millis += servo3Interval;
    servo3Pos = servo3Pos + servo3Degrees;
    if (servo3Pos <= servo3MinDegrees) {
      if (servo3Interval == servo3SlowInterval) {
        servo3Interval = servo3FastInterval;
      }
      else {
        servo3Interval = servo3SlowInterval;
      }
    }
    if ((servo3Pos >= servo3MaxDegrees) || (servo3Pos <= servo3MinDegrees))  {
      servo3Degrees = - servo3Degrees; // reverse direction
      servo3Pos = servo3Pos + servo3Degrees;
    }
    servo3.write(servo3Pos);
  }
}

//====================================================**************
void servoSweep2() {
 currentMillis1 = millis();
  currentMillis2 = millis();
  currentMillis3 = millis();

  minDegrees = analogRead(pot1);
maxDegrees = analogRead(pot2);
slowInterval = analogRead(pot3);
fastInterval = analogRead(pot4);

minDegrees = map(minDegrees,0,1023,0,90);
maxDegrees = map(maxDegrees,0,1023,90,180);
//servo1Interval = map(slowInterval,0,1023,5,500);
fastInterval = map(fastInterval,0,1023,5,500);
int servo1Interval2 = 2000;

//int servo1Stop = servo1Interval + 2000;


  //==================================START SERVO1 IF STATEMENTS
  if (currentMillis1 - previousServo1Millis >= servo1Interval) {//when it gets to max position stop for 1 second
    previousServo1Millis += servo1Interval;
    servo1Pos = servo1Pos + servo1Degrees;
   // if (servo1Pos <= minDegrees) {
     // if (servo1Interval == slowInterval) {
      //  servo1Interval = fastInterval;
     // }
     // else {
      //  servo1Interval = slowInterval;
      //}
   // }
    if ((servo1Pos >= maxDegrees) || (servo1Pos <= minDegrees))  {
      servo1Degrees = - servo1Degrees; // reverse direction
      //servo1Pos = servo1Pos + servo1Degrees;
       if (servo1Pos <= minDegrees){
        servo1Interval = servo1Stop;
        //Serial.println("Hello2");
       }
       //servo1Degrees = - servo1Degrees; 
      //servo1Interval -= 500;
      }
     // Serial.println("Hello1");
    servo1.write(servo1Pos);
  }

  //=========================================END SERVO1 IF STATEMENTS
  //==================================START SERVO2 IF STATEMENTS
  if (currentMillis2 - previousServo2Millis >= servo2Interval) {
    previousServo2Millis += servo2Interval;
    servo2Pos = servo2Pos + servo2Degrees;
   // if (servo2Pos <= servo2MinDegrees) {
     // if (servo2Interval == servo2SlowInterval) {
       // servo2Interval = servo2FastInterval;
     // }
      //else {
       // servo2Interval = servo2SlowInterval;
      //}
    //}
    if ((servo2Pos >= servo2MaxDegrees) || (servo2Pos <= servo2MinDegrees))  {
      servo2Degrees = - servo2Degrees; // reverse direction
      servo2Pos = servo2Pos + servo2Degrees;
    }
    servo2.write(servo2Pos);
  }

  //=========================================END SERVO2 IF STATEMENTS
  //==================================START SERVO3 IF STATEMENTS
  if (currentMillis3 - previousServo3Millis >= servo3Interval) {
    previousServo3Millis += servo3Interval;
    servo3Pos = servo3Pos + servo3Degrees;
   // if (servo3Pos <= servo3MinDegrees) {
    //  if (servo3Interval == servo3SlowInterval) {
       // servo3Interval = servo3FastInterval;
      //}
     // else {
       // servo3Interval = servo3SlowInterval;
      //}
   // }
    if ((servo3Pos >= servo3MaxDegrees) || (servo3Pos <= servo3MinDegrees))  {
      servo3Degrees = - servo3Degrees; // reverse direction
      servo3Pos = servo3Pos + servo3Degrees;
    }
    //servo3.write(servo3Pos);
    servo3.write(40);
  }
}

//=================================test
/*
 if (currentMillis1 - previousServo1Millis >= servo1Interval) {//when it gets to max position stop for 1 second
    if(servo1Pos < maxDegrees){
      servo1Pos = servo1Pos + servo1Degrees;
    }
    if(servo1Pos >= maxDegrees){
      
    }
 previousServo1Millis += servo1Interval;

  
   // previousServo1Millis += servo1Interval;
    //servo1Pos = servo1Pos + servo1Degrees;
   // if (servo1Pos <= minDegrees) {
     // if (servo1Interval == slowInterval) {
      //  servo1Interval = fastInterval;
     // }
     // else {
      //  servo1Interval = slowInterval;
      //}
   // }
    if ((servo1Pos >= maxDegrees) || (servo1Pos <= minDegrees))  {
      servo1Degrees = - servo1Degrees; // reverse direction
      //servo1Pos = servo1Pos + servo1Degrees;
       //if (servo1Pos <= minDegrees){
       // servo1Interval = servo1Stop;
        //Serial.println("Hello2");
       //}
       //servo1Degrees = - servo1Degrees; 
      //servo1Interval -= 500;
      }
     // Serial.println("Hello1");
    servo1.write(servo1Pos);
  }
*/
  
