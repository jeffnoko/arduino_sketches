

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
