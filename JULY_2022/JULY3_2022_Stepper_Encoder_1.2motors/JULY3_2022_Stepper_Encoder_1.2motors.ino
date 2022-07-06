//OLED screen
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     1// Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// EasyDriver connections
#define step_pin1 7 // Pin 9 connected to Steps pin on EasyDriver
#define dir_pin1 6   // Pin 8 connected to Direction pin
#define step_pin2 9  // Pin 9 connected to Steps pin on EasyDriver
#define dir_pin2 8   // Pin 8 connected to Direction pin
//#define MS1 10       // Pin 10 connected to MS1 pin
//#define MS2 11      // Pin 11 connected to MS2 pin
#define SLEEP 12     // Pin 12 connected to SLEEP pin

volatile boolean TurnDetected1;  // need volatile for Interrupts
volatile boolean rotationdirection1;  // CW or CCW rotation
volatile boolean TurnDetected2;  // need volatile for Interrupts
volatile boolean rotationdirection2;  // CW or CCW rotation

// Rotary Encoder Module connections
const int PinCLK1 = 2; // Generating interrupts using CLK signal
const int PinDT1 = 11;  // Reading DT signal
const int PinSW1 = 4;  // Reading Push Button switch #1
const int PinCLK2 = 3; // Generating interrupts using CLK signal
const int PinDT2 = 10;  // Reading DT signal
const int PinSW2 = 12;  // Reading Push Button switch #2
//******************
const int beam1 = A0;
const int beam2 = 5;
//******************
int newZeroX;
int newZeroY;
int buttonState = 0;
const int button1 = A1;
int counter = 0;
int pos1,pos2,pos3,pos4;


int StepperPosition1 = 0;  // To store Stepper Motor Position1
int StepperPosition2 = 0;  // To store Stepper Motor Position2
int StepsToTake = 1;    // Controls the speed of the Stepper per Rotary click

int direction;   // Variable to set Rotation (CW-CCW) of stepper
int beam1State;
int beam2State;
bool mode1 = true;
bool mode2 = false;
bool beam1RoutineFinished = false;
bool beam2RoutineFinished = false;

 

// Interrupt routine runs if CLK goes from HIGH to LOW
void rotarydetect1 ()  {
  delay(4);  // delay for Debouncing
  if (digitalRead(PinCLK1))
    rotationdirection1 = digitalRead(PinDT1);
  else
    rotationdirection1 = !digitalRead(PinDT1);
  TurnDetected1 = true;
}
void rotarydetect2 ()  {
  delay(4);  // delay for Debouncing
  if (digitalRead(PinCLK2))
    rotationdirection2 = digitalRead(PinDT2);
  else
    rotationdirection2 = !digitalRead(PinDT2);
  TurnDetected2 = true;
}


void setup ()  {
  Serial.begin(9600);
   if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
    }
  // pinMode(MS1, OUTPUT);
  // pinMode(MS2, OUTPUT);
  pinMode(dir_pin1, OUTPUT);
  pinMode(step_pin1, OUTPUT);
  pinMode(dir_pin2, OUTPUT);
  pinMode(step_pin2, OUTPUT);
  //*******************
  pinMode(beam1, INPUT_PULLUP);
  pinMode(beam2, INPUT_PULLUP);
  //*********************
  pinMode(button1, INPUT_PULLUP); 
  //pinMode(SLEEP, OUTPUT);
  //digitalWrite(SLEEP, HIGH);  // Wake up EasyDriver
  delay(5);  // Wait for EasyDriver wake up

   newZeroX = StepperPosition1 + 20;
  newZeroY = StepperPosition2 + 20;

  /* Configure type of Steps on EasyDriver:
    // MS1 MS2
    //
    // LOW LOW = Full Step //
    // HIGH LOW = Half Step //
    // LOW HIGH = A quarter of Step //
    // HIGH HIGH = An eighth of Step //
  */
  //digitalWrite(MS1, LOW);      // Configures to Full Steps
  //digitalWrite(MS2, LOW);    // Configures to Full Steps

  pinMode(PinCLK1, INPUT); // Set Pin to Input
  pinMode(PinDT1, INPUT);
  pinMode(PinSW1, INPUT);
  pinMode(PinCLK2, INPUT); // Set Pin to Input
  pinMode(PinDT2, INPUT);
  pinMode(PinSW2, INPUT);
  digitalWrite(PinSW1, HIGH); // Pull-Up resistor for switch1
  digitalWrite(PinSW2, HIGH); // Pull-Up resistor for switch2
  attachInterrupt (0, rotarydetect1, FALLING); // interrupt 0 always connected to pin 2 on Arduino UNO
  attachInterrupt (1, rotarydetect2, FALLING); // interrupt 1 always connected to pin 3 on Arduino UNO
}


void loop ()  {
 // Button();
 buttonState = digitalRead(button1);
  if (buttonState == HIGH) {
    // turn LED on:
    //digitalWrite(ledPin, HIGH);
    Serial.println("hello");
    delay(100);
  } else {
    // turn LED off:
    //digitalWrite(ledPin, LOW);
    Serial.println("goodbye");
    delay(100);
  }
  //Serial.print("button1 = ");Serial.println(button1);
  //delay(500);
  /*
  while (mode1 == true) {
startup();
}

 
 displayText();
 //delay(100);
 //Serial.println("hello3");
  //Serial.println("hello2");
   buttonResetMotor1();
   turnDetected1();
  buttonResetMotor2();
  turnDetected2();

  */
 // newZero();
 // breakBeam();
  /*
    if (!(digitalRead(PinSW1))) {
      Serial.println("Button1 Pressed");// check if button is pressed
    if (StepperPosition1 == 0) {  // check if button was already pressed
    } else {
        if (StepperPosition1 > 0) {  // Stepper was moved CW
          while (StepperPosition1 != 0){  //  Do until Motor position is back to ZERO
            digitalWrite(dir_pin1, HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
            for (int x = 0; x < StepsToTake; x++) {
                digitalWrite(step_pin1, HIGH);
                delay(1);
                digitalWrite(step_pin1, LOW);
                delay(1);
              }
              StepperPosition1=StepperPosition1-StepsToTake;
          }
        }
        else {
          while (StepperPosition1 != 0){
            digitalWrite(dir_pin1, LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
                for (int x = 0; x < StepsToTake; x++) {
                digitalWrite(step_pin1, HIGH);
                delay(1);
                digitalWrite(step_pin1, LOW);
                delay(1);
              }
             StepperPosition1=StepperPosition1+StepsToTake;
          }
        }
        StepperPosition1=0; // Reset position to ZERO after moving motor back
      }
      delay(200);
      Serial.print("StepperPosition1 = ");Serial.println(StepperPosition1);
    }
  */
  // Runs if rotation was detected
  /*
    if (TurnDetected1)  {
      // Serial.println("Turn detected 1");
          TurnDetected1 = false;  // do NOT repeat IF loop until new rotation detected

    // Which direction to move Stepper motor
          if (rotationdirection1) { // Move motor CCW
              digitalWrite(dir_pin1, HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
              for (int x = 0; x < StepsToTake; x++) {
                digitalWrite(step_pin1, HIGH);
                delay(1);
                digitalWrite(step_pin1, LOW);
                delay(1);
              }
              StepperPosition1=StepperPosition1-StepsToTake;
              Serial.print("StepperPosition1 = ");Serial.println(StepperPosition1);
          }

          if (!rotationdirection1) { // Move motor CW
              digitalWrite(dir_pin1, LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
              for (int x = 0; x < StepsToTake; x++) {
                digitalWrite(step_pin1, HIGH);
                delay(1);
                digitalWrite(step_pin1, LOW);
                delay(1);
              }
              StepperPosition1=StepperPosition1+StepsToTake;
              Serial.print("StepperPosition1 = ");Serial.println(StepperPosition1);

          }
         //Serial.print("StepperPosition1 = ");Serial.println(StepperPosition1);
    }
  */
}
//Serial.print("StepperPosition1 = ");Serial.println(StepperPosition1);
//}
//}
