

const int pot1 = A0;//R
const int pot2 = A1;//G
const int pot3 = A2;//B
const int LED1 = 3;
const int LED2 = 5;
const int LED3 = 6;
int inputVal1 = 0;
int inputVal2 = 0;
int inputVal3 = 0;

void setup() {
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
   pinMode (LED3, OUTPUT);

}

void loop() {
  inputVal1 = analogRead(pot1);
  inputVal2 = analogRead(pot2);
  inputVal3 = analogRead(pot3);
  analogWrite (LED1, inputVal1/4);
  analogWrite (LED2, inputVal2/4);
  analogWrite (LED3, inputVal3/4);
  delay(10);
}
