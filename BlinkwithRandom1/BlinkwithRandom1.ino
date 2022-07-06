int a;
void setup() {
Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  a = random(1,100);
  Serial.println(a);
  delay(500);
}
 
