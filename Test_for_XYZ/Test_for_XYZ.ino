int enable1 = 8;

#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper(1,24,30); // X
//AccelStepper stepper(1,25,31); // Y
//AccelStepper stepper(1,26,32); // Z

//AccelStepper stepper1(1,2,5); // X
//AccelStepper stepper1(1,3,6); // Y
//AccelStepper stepper1(1,4,7); // Z

void setup()
{  
  pinMode(enable1,OUTPUT);
  // X settings
  //stepper.setMaxSpeed(400);
  //stepper.setAcceleration(1000);
  //stepper.moveTo(500);
// Y
 // stepper.setMaxSpeed(400);
  //stepper.setAcceleration(1000);
  //stepper.moveTo(500);

  // Z
  stepper.setMaxSpeed(400);
  stepper.setAcceleration(1000);
  stepper.moveTo(500);
}

void loop()
{
    enable1 = HIGH;
    // If at the end of travel go to the other end
    if (stepper.distanceToGo() == 0)
      stepper.moveTo(-stepper.currentPosition());

    stepper.run();
}
