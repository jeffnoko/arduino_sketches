

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
      
    }
    else{
    analogWrite(RedPin, LOW);
    analogWrite(BluePin, LOW);
    analogWrite(GreenPin, LOW);
    }
  }
}
