


/*
void test(){

if (currentMillis1 - previousServo1Millis >= servo1Interval) {

if(servo1Pos < servo1MaxDegrees){
  previousServo1Millis += servo1Interval;
  servo1Pos = servo1Pos + servo1Degrees;
  
  if(servo1Pos <= minDegrees){
    servo1Pos = - servo1Pos;
  }
}

if(servo1Pos >= servo1MaxDegrees){
  previousServo1Millis += servo1Interval;
  
  if(currentMillis1 - previousMillis1 >= servoInterval2){
    servo1Degrees = -servo1Degrees;
    servo1Pos = servo1Pos + servo1Degrees;
  }
}

Serial.println(servo1Pos);

}

}

*/

/*
  
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
    servo1.write(servo1Pos);
  }

  */

  void test1(){// uses pot1 to control jitter speed of servo1, joystick and z control on encoder.
   currentMillis1 = millis();
   currentMillis2 = millis();
    minDegrees = analogRead(pot1);
maxDegrees = analogRead(pot2);
slowInterval = analogRead(pot3);

minDegrees = map(minDegrees,0,1023,0,90);
maxDegrees = map(maxDegrees,0,1023,90,180);
slowInterval = map(slowInterval,0,1023,5,500);

//Serial.print("servo1MinDegrees = ");Serial.println(servo1MinDegrees);
//Serial.print("servo1MaxDegrees = ");Serial.println(servo1MaxDegrees);

int servo1Interval2 = 2000;
if (currentMillis1 - previousServo1Millis >= servo1Interval) {
   long time1 = currentMillis1 - previousServo1Millis;
   // Serial.print("currentMillis1 = ");Serial.println(currentMillis1);

// Serial.print("previousServo1Millis = ");Serial.println(previousServo1Millis);

   // Serial.print("currentMillis1 - previousServo1Millis = ");Serial.println(time1);

if(servo1Pos < servo1MaxDegrees){
  //Serial.println("1");

  previousServo1Millis += servo1Interval;
  servo1Pos = servo1Pos + servo1Degrees;
   if(servo1Pos <= minDegrees){
   // Serial.println("2");
    servo1Degrees = - servo1Degrees;
  }
  
 
}

if(servo1Pos >= servo1MaxDegrees){
  //Serial.println("3");
  previousServo1Millis += servo1Interval;
  
  if(currentMillis1 - previousServo1Millis >= servo1Interval2){
    //int time1 = currentMillis1 - previousServo1Millis;
    //Serial.print("time1 = ");Serial.println(time1);
    //Serial.println("  4   Interval2");
    servo1Degrees = -servo1Degrees;
    servo1Pos = servo1Pos + servo1Degrees;
  }
}

// if(servo1Pos <= minDegrees){
  //  Serial.println("2");
   // servo1Degrees = - servo1Degrees;
 // }
//Serial.print("5  end  servo1Pos = ");
//Serial.println(servo1Pos);
servo1.write(servo1Pos);
}

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

}

//=================================================================================
void test2(){
   currentMillis1 = millis();
   currentMillis2 = millis();
    minDegrees = analogRead(pot1);
maxDegrees = analogRead(pot2);
slowInterval = analogRead(pot3);

minDegrees = map(minDegrees,0,1023,0,90);
maxDegrees = map(maxDegrees,0,1023,90,180);
slowInterval = map(slowInterval,0,1023,5,500);

//Serial.print("servo1MinDegrees = ");Serial.println(servo1MinDegrees);
//Serial.print("maxDegrees = ");Serial.println(maxDegrees);

int servo1Interval2 = 2000;
if (currentMillis1 - previousServo1Millis >= servo1Interval) {
   long time1 = currentMillis1 - previousServo1Millis;
   // Serial.print("currentMillis1 = ");Serial.println(currentMillis1);

// Serial.print("previousServo1Millis = ");Serial.println(previousServo1Millis);

   // Serial.print("currentMillis1 - previousServo1Millis = ");Serial.println(time1);

if(servo1Pos < servo1MaxDegrees){
  //Serial.println("1");

  previousServo1Millis += servo1Interval;
  servo1Pos = servo1Pos + servo1Degrees;
   if(servo1Pos <= minDegrees){
   // Serial.println("2");
    servo1Degrees = - servo1Degrees;
  }
  
 
}

if(servo1Pos >= servo1MaxDegrees){
  //Serial.println("3");
  previousServo1Millis += servo1Interval;
  
  if(currentMillis1 - previousServo1Millis >= servo1Interval2){
    //int time1 = currentMillis1 - previousServo1Millis;
    //Serial.print("time1 = ");Serial.println(time1);
    //Serial.println("  4   Interval2");
    servo1Degrees = -servo1Degrees;
    servo1Pos = servo1Pos + servo1Degrees;
  }
}

// if(servo1Pos <= minDegrees){
  //  Serial.println("2");
   // servo1Degrees = - servo1Degrees;
 // }
//Serial.print("5  end  servo1Pos = ");
//Serial.println(servo1Pos);
servo1.write(servo1Pos);
}

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

}

//******************************************************************************
//******************************************************************************
void test3(){
   currentMillis1 = millis();
   currentMillis2 = millis();
    currentMillis3 = millis();
    minDegrees = analogRead(pot1);
maxDegrees = analogRead(pot2);
slowInterval = analogRead(pot3);

minDegrees = map(minDegrees,0,1023,0,90);
maxDegrees = map(maxDegrees,0,1023,90,180);
slowInterval = map(slowInterval,0,1023,5,500);

//Serial.print("servo1MinDegrees = ");Serial.println(servo1MinDegrees);
//Serial.print("maxDegrees = ");Serial.println(maxDegrees);

int servo1Interval2 = 2000;
if (currentMillis1 - previousServo1Millis >= servo1Interval) {
   long time1 = currentMillis1 - previousServo1Millis;
   // Serial.print("currentMillis1 = ");Serial.println(currentMillis1);

// Serial.print("previousServo1Millis = ");Serial.println(previousServo1Millis);

   // Serial.print("currentMillis1 - previousServo1Millis = ");Serial.println(time1);

if(servo1Pos < servo1MaxDegrees){
  //Serial.println("1");

  previousServo1Millis += servo1Interval;
  servo1Pos = servo1Pos + servo1Degrees;
   if(servo1Pos <= minDegrees){
   // Serial.println("2");
    servo1Degrees = - servo1Degrees;
  }
  
 
}

if(servo1Pos >= servo1MaxDegrees){
  //Serial.println("3");
  previousServo1Millis += servo1Interval;
  
  if(currentMillis1 - previousServo1Millis >= servo1Interval2){
    //int time1 = currentMillis1 - previousServo1Millis;
    //Serial.print("time1 = ");Serial.println(time1);
    //Serial.println("  4   Interval2");
    servo1Degrees = -servo1Degrees;
    servo1Pos = servo1Pos + servo1Degrees;
  }
}

// if(servo1Pos <= minDegrees){
  //  Serial.println("2");
   // servo1Degrees = - servo1Degrees;
 // }
//Serial.print("5  end  servo1Pos = ");
//Serial.println(servo1Pos);
servo1.write(servo1Pos);
}

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

//******************************************************************************
void test4(){
   currentMillis1 = millis();
   currentMillis2 = millis();
    currentMillis3 = millis();
    minDegrees = analogRead(pot1);
maxDegrees = analogRead(pot2);
slowInterval = analogRead(pot3);

minDegrees = map(minDegrees,0,1023,0,90);
maxDegrees = map(maxDegrees,0,1023,90,180);
slowInterval = map(slowInterval,0,1023,5,500);

//Serial.print("servo1MinDegrees = ");Serial.println(servo1MinDegrees);
//Serial.print("maxDegrees = ");Serial.println(maxDegrees);

int servo1Interval2 = 2000;
if (currentMillis1 - previousServo1Millis >= servo1Interval) {
   long time1 = currentMillis1 - previousServo1Millis;
   // Serial.print("currentMillis1 = ");Serial.println(currentMillis1);

// Serial.print("previousServo1Millis = ");Serial.println(previousServo1Millis);

   // Serial.print("currentMillis1 - previousServo1Millis = ");Serial.println(time1);

if(servo1Pos < servo1MaxDegrees){
  //Serial.println("1");

  previousServo1Millis += servo1Interval;
  servo1Pos = servo1Pos + servo1Degrees;
   if(servo1Pos <= minDegrees){
   // Serial.println("2");
    servo1Degrees = - servo1Degrees;
  }
  
 
}

if(servo1Pos >= servo1MaxDegrees){
  //Serial.println("3");
  previousServo1Millis += servo1Interval;
  
  if(currentMillis1 - previousServo1Millis >= servo1Interval2){
    //int time1 = currentMillis1 - previousServo1Millis;
    //Serial.print("time1 = ");Serial.println(time1);
    //Serial.println("  4   Interval2");
    servo1Degrees = -servo1Degrees;
    servo1Pos = servo1Pos + servo1Degrees;
  }
}

// if(servo1Pos <= minDegrees){
  //  Serial.println("2");
   // servo1Degrees = - servo1Degrees;
 // }
//Serial.print("5  end  servo1Pos = ");
//Serial.println(servo1Pos);
servo1.write(servo1Pos);
}

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
