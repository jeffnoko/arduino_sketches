
//========================================START
void servoSweep() {
 currentMillis1 = millis();
  currentMillis2 = millis();
  currentMillis3 = millis();

  //==================================START SERVO1 IF STATEMENTS
  if (currentMillis1 - previousServo1Millis >= servo1Interval) {
    previousServo1Millis += servo1Interval;
    servo1Pos = servo1Pos + servo1Degrees;
    if (servo1Pos <= servo1MinDegrees) {
      if (servo1Interval == servo1SlowInterval) {
        servo1Interval = servo1FastInterval;
      }
      else {
        servo1Interval = servo1SlowInterval;
      }
    }
    if ((servo1Pos >= servo1MaxDegrees) || (servo1Pos <= servo1MinDegrees))  {
      servo1Degrees = - servo1Degrees; // reverse direction
      servo1Pos = servo1Pos + servo1Degrees;
    }
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

  //=========================================END SERVO3 IF STATEMENTS

}

//========================================END
