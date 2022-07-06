
/*
 * LIMIT SWITCHES X Y Z
 */
const int buttonPin1 = 9;
const int buttonPin2 = 10;
const int buttonPin3 = 11;
const int ledPin =  13;      


int buttonState1 = 0;
int buttonState2 = 0;       
int buttonState3 = 0;       

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);

  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
}

void loop() {
  
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  //Serial.println(buttonState);
  
  if (buttonState1 == HIGH) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }

  if (buttonState2 == HIGH) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }

  if (buttonState3 == HIGH) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
