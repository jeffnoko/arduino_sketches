void joystick() {
  unsigned long current_time = millis();
  if (current_time - last_input_time > INPUT_READ_INTERVAL)
  {
    int joystick_in1 = analogRead(JOYSTICK_PIN1);
    int joystick_in2 = analogRead(JOYSTICK_PIN2);

     joystick_in1 = map(joystick_in1, 0, 1023, 180, 120);//motor 2
     joystick_in2 = map(joystick_in2, 0, 1023, 20, 70);//motor 3

     servo1Pos = map(joystick_in1, 0,180,-joystick_in1,joystick_in1);
//Serial.print("servo1Pos = ");Serial.println(servo1Pos);
    servo1.write(servo1Pos);
    servo2.write(joystick_in1);
    servo3.write(joystick_in2);

   

    last_input_time = current_time;

  }
}
