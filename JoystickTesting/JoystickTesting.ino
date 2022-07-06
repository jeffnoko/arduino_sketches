
#define JOYSTICK_PIN1 A4 

void setup() {
  Serial.begin(9600);
  }

void loop() {
  int val = analogRead(JOYSTICK_PIN1);
  Serial.print("val1 before map =");Serial.println(val);
  val = map(val, 0, 1023, -2000,2000);
 // if (val > -100 && val < 100){
   // val = 0;
 // }
  delay(100);
   Serial.print("val2 after map =");Serial.println(val);
}
