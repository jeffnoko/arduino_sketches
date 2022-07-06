
unsigned int bitOut(void)//origanally port = 0
{
  static unsigned long firstTime=1, prev=0;
  unsigned long bit1=0, bit0=0, x=0, port=1, limit=99;
  if (firstTime)
  {
    firstTime=0;
    prev=analogRead(port);
  }
  while (limit--)
  {
    x=analogRead(port);
    bit1=(prev!=x?1:0);
    prev=x;
    x=analogRead(port);
    bit0=(prev!=x?1:0);
    prev=x;
    if (bit1!=bit0)
      break;
  }
  return bit1;
}
//------------------------------------------------------------------------------
unsigned long seedOut(unsigned int noOfBits)
{
  // return value with 'noOfBits' random bits set
  unsigned long seed=0;
  for (int i=0;i<noOfBits;++i)
    seed = (seed<<1) | bitOut();
  return seed;
}
void s1up(){
   stepper3.setMaxSpeed(800);
  stepper3.setAcceleration(800);
  stepper3.moveTo(300);
  stepper3.runToPosition();
  }
void s1down(){
  int S = analogRead(A13);
  int zHome = 0;
  S = map(S,0,1023,0,-200);
   //Serial.println(S);
   stepper3.setMaxSpeed(800);
  stepper3.setAcceleration(800);
   stepper3.moveTo(zHome + S);
  stepper3.runToPosition();
}



 /*
  button1Reading = digitalRead(A5);
  if (button1Reading == HIGH && button1Previous == LOW && millis() - time > debounce) {
    if (button1State == HIGH){
      button1State = LOW;
    }
    else
      button1State = HIGH;
    time = millis();    
  }

  button1Previous = button1Reading;

  if (button1State == HIGH ){      }
  
  */
  
