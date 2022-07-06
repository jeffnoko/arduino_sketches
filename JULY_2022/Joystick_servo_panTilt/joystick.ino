
void joystickPanTilt() {
  unsigned long current_time = millis();
  if (current_time - last_input_time > INPUT_READ_INTERVAL)
  {
    int joystick_in1 = analogRead(JOYSTICK_PIN1);
    int joystick_in2 = analogRead(JOYSTICK_PIN2);

    int pan = map(joystick_in1, 0, 1023, 180 , 100); //motor #2 range of motion 180,100 original
    int tilt = map(joystick_in2, 0, 1023, 0, 80 ); //motor #3   range of motion 0,80 original
    //int brushTipTilt = map( tilt,0,80,-180,180);  //motor #1
   // int brushTipPan = map( pan,180,100,-180,180);  //motor #1

    int brushTipTilt = map( tilt,0,80,180,-120);  //motor #1 180,-180 original
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
//Serial.print("brushTip = "); Serial.println(brushTip);



    last_input_time = current_time;

  }
}
