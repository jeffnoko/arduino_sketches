#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int PinCLK1 = 18; // Generating interrupts using CLK signal
const int PinDT1 = A2;  // Reading DT signal
const int PinSW1 = A3;  // Reading Push Button switch #1
volatile boolean TurnDetected1;
volatile boolean rotationdirection1;  // CW or CCW rotation
int StepperPosition1 = 0;  // To store Stepper Motor Position1
int StepsToTake = 1;

void rotarydetect1 ()  {
  delay(4);  // delay for Debouncing
  if (digitalRead(PinCLK1))
    rotationdirection1 = digitalRead(PinDT1);
  else
    rotationdirection1 = !digitalRead(PinDT1);
  TurnDetected1 = true;
}


void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  pinMode(PinCLK1, INPUT);
  pinMode(PinSW1, INPUT);
  pinMode(PinDT1, INPUT);
  digitalWrite(PinSW1, HIGH); // Pull-Up resistor for switch1
  attachInterrupt (5, rotarydetect1, FALLING);
}

void loop() {
  turnDetected1();
  displayText();
}

void displayText(void) {
  display.clearDisplay();

  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0, 0); // Start at top-left corner
  //display.println(StepperPosition1);
  display.println(F("X = "));
  display.setCursor(50, 0);            // Start at top-left corner
  display.println(StepperPosition1);
  // display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
  // display.println(3.141592);

  //display.setTextSize(8);             // Draw 2X-scale text
  // display.setTextColor(SSD1306_WHITE);
  // display.print(F("0x")); display.println(0xDEADBEEF, HEX);

  display.display();
  //delay(8000);
}

void turnDetected1() { //Serial.print("StepperPosition1 = ");Serial.println(StepperPosition1);
  if (TurnDetected1)  {
    // Serial.println("Turn detected 1");
    TurnDetected1 = false;  // do NOT repeat IF loop until new rotation detected

    // Which direction to move Stepper motor
    if (rotationdirection1) { // Move motor CCW  if(rotationdirection1 !=0)
      // digitalWrite(dir_pin1, HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
      for (int x = 0; x < StepsToTake; x++) {
        //digitalWrite(step_pin1, HIGH);
        delay(1);
        //digitalWrite(step_pin1, LOW);
        delay(1);
      }
      StepperPosition1 = StepperPosition1 - StepsToTake;
      Serial.print("StepperPosition1 = "); Serial.println(StepperPosition1);
    }

    if (!rotationdirection1) { // Move motor CW
      //digitalWrite(dir_pin1, LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
      for (int x = 0; x < StepsToTake; x++) {
        // digitalWrite(step_pin1, HIGH);
        delay(1);
        // digitalWrite(step_pin1, LOW);
        delay(1);
      }
      StepperPosition1 = StepperPosition1 + StepsToTake;
      Serial.print("StepperPosition1 = "); Serial.println(StepperPosition1);

    }
    //Serial.print("StepperPosition1 = ");Serial.println(StepperPosition1);
  }
}
