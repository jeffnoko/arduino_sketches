/*
 * make a way to work in modes.
 * switching between modes
 * 
 * had jitter problems when the pump button was pressed. The servos word jump to max position.
 * after trying some things, decided to put the pump back on a separate arduino and adafruit motorshield
 * instaed of the L293D. For now. 
 * 
 *  void zLift(){
  if (stepper1.isRunning()==0 && stepper2.isRunning()==0){
   //zCurrentPos = stepper3.currentPosition();
 // stepper3.moveTo( -100);
  stepper3.runToNewPosition(-150);}
  else{
  //stepper3.moveTo(0);
  stepper3.runToNewPosition(0);
  }
  }

  //====================================
  Wants:

  When motors are stopped lift Z.
  When motors are moving Z down.
  When motors are moving Z up. to go to a new position without a line.
  When motors aren't moving Z down to use only sero panTilt.
  Control 0 with encoder.
  XY speed control on a pot
  mode: panTiltZoom controlled (mapped to) XY joystick.
 */
