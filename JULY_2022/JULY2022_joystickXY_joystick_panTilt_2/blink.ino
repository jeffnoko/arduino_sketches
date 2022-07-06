void blink1(){
int blinkRate = analogRead(pot2);
int brightness = analogRead(pot1);
  blinkRate = map(blinkRate,0,1023, 0,1000);
  brightness = map(brightness,0,1023,0,255);
  interval = blinkRate;
   unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;

    
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    if(ledState == HIGH){
      analogWrite(ledPin,brightness);
    }
    else{
    digitalWrite(ledPin, LOW);
    }
  }
}

//========================

void blinkRate(){
  
  int blinkRate = analogRead(pot2);
  blinkRate = map(blinkRate,0,1023, 0,100);
  
 }

 void RGBBlink(){
  
for (int x=0; x<3; x++) {
INC[x] = (RGB1[x] - RGB2[x]) / 256; }
for (int x=0; x<256; x++) {
red = int(RGB1[0]);
green = int(RGB1[1]);
blue = int(RGB1[2]);
//analogWrite (RedPin, red);
//analogWrite (GreenPin, green);
//analogWrite (BluePin, blue);
blink2();
delay(2);
RGB1[0] -= INC[0];
RGB1[1] -= INC[1];
RGB1[2] -= INC[2];
}
for (int x=0; x<3; x++) {
RGB2[x] = random(556)-300;
RGB2[x] = constrain(RGB2[x], 1, 255);//0,255
//delay(1000);
//speed1 = analogRead(pot1);
//Serial.println(speed1);
delay(speed1);
}
speed1 = analogRead(pot1);
//Serial.println("hello");
//}
 }


 void blink2(){
int blinkRate = analogRead(pot2);
int brightness = analogRead(pot1);
  blinkRate = map(blinkRate,0,1023, 0,10000);
  brightness = map(brightness,0,1023,0,10);
  interval = blinkRate;
   unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;

    
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    if(ledState == HIGH){
     // red = red/brightness;
      // blue = blue/brightness;
       //.,/;;;;;;;;;;;;;;;;;;;;;;' green = green/brightness;
      analogWrite(RedPin,red);//brightness
      analogWrite(BluePin,green);//brightness
      analogWrite(GreenPin,blue);//brightness
     // Serial.print(red);
     // Serial.print(",");
      //Serial.print(blue);
     // Serial.print(",");
      //Serial.println(green);
       
       //Serial.println(red);
       //Serial.println("hello");
      
    }
    else{
    analogWrite(RedPin, LOW);
    analogWrite(BluePin, LOW);
    analogWrite(GreenPin, LOW);
    }
  }
}
