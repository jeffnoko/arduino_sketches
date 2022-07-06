void displayText(void) {
  display.clearDisplay();

  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);// Start at top-left corner
  //display.println(StepperPosition1);
  display.println(F("X = "));
  display.setCursor(50,0);             // Start at top-left corner
  display.println(StepperPosition1);
  
  display.setCursor(0,18);             // Start at top-left corner
  display.println(F("Y = "));
  display.setCursor(50,18);             // Start at top-left corner
  display.println(StepperPosition2);
 // display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
 // display.println(3.141592);

  //display.setTextSize(8);             // Draw 2X-scale text
 // display.setTextColor(SSD1306_WHITE);
 // display.print(F("0x")); display.println(0xDEADBEEF, HEX);

  display.display();
  //delay(8000);
}
