
void setup()
{
  Serial.begin(9600);
  //pinMode(4, INPUT);
  pinMode(5, INPUT_PULLUP);
  //digitalWrite( 4, HIGH ) ;  // switch on pull up
 // digitalWrite( 5,) ;  // switch on pull up
}

void loop()
{
 // Serial.println(digitalRead(4));
  Serial.println(digitalRead(5));
  delay(50);
}
