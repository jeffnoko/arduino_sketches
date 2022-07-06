










/*
//#include <Rotary.h>

// Rotary encoder is wired with the common to ground and the two
// outputs to pins 2 and 3.
Rotary rotary = Rotary(2, 3);

// Counter that will be incremented or decremented by rotation.
int counter = 0;
int button1 = 4;
int buttonState;

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, rotate, CHANGE);
  attachInterrupt(1, rotate, CHANGE);
  pinMode(button1,INPUT_PULLUP);
}

void loop() {
  //Serial.println("Hello");delay(300);
  buttonState = digitalRead(button1);
  if(buttonState2 == LOW){
    counter2 = 0;
    
  }
}

// rotate is called anytime the rotary inputs change state.
*/


void rotate() {
  unsigned char result = rotary.process();
  if (result == DIR_CW) {
    counter2++;
    //Serial.println(counter2);
  } else if (result == DIR_CCW) {
    counter2--;
    //Serial.println(counter2);
  }
}
