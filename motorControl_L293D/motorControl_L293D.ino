
/*
 * connect dc motor to #3 and #6 on chip
 * connect #4 to ground and ground to arduino
 * connect +5v to #8 on chip
 */
int speedPin = 5;//enable pin  #1 on l293d chip
int direction1 = 4;// #2 on chip
int direction2 = 3; // #7 on chip
int motorSpeed = 100;
int button = 7;
int potentiometer = A0;

void setup() {
  pinMode(speedPin, OUTPUT);
  pinMode(direction1,OUTPUT);
  pinMode(direction2,OUTPUT);
  pinMode(speedPin, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  

}

void loop() {

   int speed = analogRead(potentiometer) / 4;
  boolean reverse = digitalRead(button);
  setMotor(speed, reverse);
  
  //digitalWrite(direction1,HIGH);
  //digitalWrite(direction2,LOW);
 // analogWrite(speedPin,motorSpeed);

}

void setMotor(int speed, boolean reverse)
{
  analogWrite(speedPin, speed);
  digitalWrite(direction1, ! reverse);
  digitalWrite(direction2, reverse);
}
