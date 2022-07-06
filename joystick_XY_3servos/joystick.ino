
void joystick() {
  unsigned long current_time = millis();
  if (current_time - last_input_time > INPUT_READ_INTERVAL)
  {
    int joystick_in1 = analogRead(JOYSTICK_PIN1);
    int joystick_in2 = analogRead(JOYSTICK_PIN2);

    int desired_speed1 = map(joystick_in1, 0, 900, -MAX_SPEED, MAX_SPEED);
    int desired_speed2 = map(joystick_in2, 0, 900, -MAX_SPEED, MAX_SPEED);

    if (desired_speed1 > -100 && desired_speed1 < 100) {
      desired_speed1 = 0;
    }
    if (desired_speed2 > -100 && desired_speed2 < 100) {
      desired_speed2 = 0;
    }


    stepper1.setMaxSpeed(abs(desired_speed1));
    stepper2.setMaxSpeed(abs(desired_speed2));


    if (desired_speed1 == 0 && stepper1.speed() == 0)
    {
      // Prevent running off the end of the position range
      stepper1.setCurrentPosition(0);
    }
    else if (desired_speed1 < 0)
    {
      stepper1.moveTo(-1000000000);
    }
    else if (desired_speed1 > 0)
    {
      stepper1.moveTo(1000000000);
    }


    if (desired_speed2 == 0 && stepper2.speed() == 0)
    {
      // Prevent running off the end of the position range
      stepper2.setCurrentPosition(0);
    }
    else if (desired_speed2 < 0)
    {
      stepper2.moveTo(-1000000000);
    }
    else if (desired_speed2 > 0)
    {
      stepper2.moveTo(1000000000);
    }


    last_input_time = current_time;

  }
}
