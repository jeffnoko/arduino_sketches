// MultiStepper.pde
// -*- mode: C++ -*-
//
// Shows how to multiple simultaneous steppers
// Runs one stepper forwards and backwards, accelerating and decelerating
// at the limits. Runs other steppers at the same time
//
// Copyright (C) 2009 Mike McCauley
// $Id: MultiStepper.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>

// Define some steppers and the pins the will use
AccelStepper stepper1(1,2,5); // X
AccelStepper stepper2(1,3,6); // Y
AccelStepper stepper3(1,4,7); // Z

void setup()
{  
    stepper1.setMaxSpeed(200);
    stepper1.setAcceleration(1000);
    stepper1.moveTo(200);
    
    stepper2.setMaxSpeed(200);
    stepper2.setAcceleration(1000);
    stepper2.moveTo(600);
    
    stepper3.setMaxSpeed(300);
    stepper3.setAcceleration(1000);
    stepper3.moveTo(100); 
}

void loop()
{
    
    if (stepper1.distanceToGo() == 0)
	stepper1.moveTo(-stepper1.currentPosition());
  
  if (stepper2.distanceToGo() == 0)
 stepper2.moveTo(-stepper2.currentPosition());
  
  if (stepper3.distanceToGo() == 0)
 stepper3.moveTo(-stepper3.currentPosition());
 
    stepper1.run();
    stepper2.run();
    stepper3.run();
}
