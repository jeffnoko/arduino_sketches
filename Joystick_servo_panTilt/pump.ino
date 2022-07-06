/*
 * connect dc motor to #3 and #6 on chip
 * connect #4 to ground and ground to arduino
 * connect +5v to #8 on chip
 
 int speed1;
int speedPin = 2;//enable pin  #1 on l293d chip
int direction1 = 3;// #2 on chip
int direction2 = 4; // #7 on chip
int button1 = 36;
int potentiometer = A6;
*/

void pump(){
  button1 = digitalRead(36);
if(button1 == 0){
    speed1 = analogRead(potentiometer) / 4;
 // boolean reverse = digitalRead(button);
  //setMotor(speed, reverse);
  
  digitalWrite(direction1,HIGH);
  digitalWrite(direction2,LOW);
  analogWrite(speedPin,speed1);
//Serial.println("hello");

}

else{
  speed1 = 0;
  analogWrite(speedPin,speed1);
}
}
