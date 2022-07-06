
// EasyDriver connections
#define step_pin1 9  // Pin 9 connected to Steps pin on EasyDriver
#define dir_pin1 8   // Pin 8 connected to Direction pin
#define step_pin2 7  // Pin 9 connected to Steps pin on EasyDriver
#define dir_pin2 6   // Pin 8 connected to Direction pin
//#define MS1 10       // Pin 10 connected to MS1 pin
//#define MS2 11      // Pin 11 connected to MS2 pin
#define SLEEP 12     // Pin 12 connected to SLEEP pin
                    
volatile boolean TurnDetected1;  // need volatile for Interrupts
volatile boolean rotationdirection1;  // CW or CCW rotation
volatile boolean TurnDetected2;  // need volatile for Interrupts
volatile boolean rotationdirection2;  // CW or CCW rotation

// Rotary Encoder Module connections
const int PinCLK1=2;   // Generating interrupts using CLK signal
const int PinDT1=11;    // Reading DT signal
const int PinSW1=4;    // Reading Push Button switch
const int PinCLK2=3;   // Generating interrupts using CLK signal
const int PinDT2=10;    // Reading DT signal
const int PinSW2=12;    // Reading Push Button switch


int StepperPosition1=0;    // To store Stepper Motor Position
int StepsToTake=1;      // Controls the speed of the Stepper per Rotary click

int direction;   // Variable to set Rotation (CW-CCW) of stepper


// Interrupt routine runs if CLK goes from HIGH to LOW
void rotarydetect1 ()  {
delay(4);  // delay for Debouncing
if (digitalRead(PinCLK1))
rotationdirection1= digitalRead(PinDT1);
else
rotationdirection1= !digitalRead(PinDT1);
TurnDetected1 = true;
}
void rotarydetect2 ()  {
delay(4);  // delay for Debouncing
if (digitalRead(PinCLK2))
rotationdirection2= digitalRead(PinDT2);
else
rotationdirection2= !digitalRead(PinDT2);
TurnDetected2 = true;
}


void setup ()  {
Serial.begin(9600);
  // pinMode(MS1, OUTPUT);
  // pinMode(MS2, OUTPUT);
   pinMode(dir_pin1, OUTPUT);
   pinMode(step_pin1, OUTPUT);
    pinMode(dir_pin2, OUTPUT);
   pinMode(step_pin2, OUTPUT);
   //pinMode(SLEEP, OUTPUT);   
   //digitalWrite(SLEEP, HIGH);  // Wake up EasyDriver
   delay(5);  // Wait for EasyDriver wake up
   
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
   
  pinMode(PinCLK1,INPUT);  // Set Pin to Input
  pinMode(PinDT1,INPUT);  
  pinMode(PinSW1,INPUT);
   pinMode(PinCLK2,INPUT);  // Set Pin to Input
  pinMode(PinDT2,INPUT);  
  pinMode(PinSW2,INPUT);
  digitalWrite(PinSW1, HIGH); // Pull-Up resistor for switch1
  digitalWrite(PinSW2, HIGH); // Pull-Up resistor for switch2
  attachInterrupt (0,rotarydetect1,FALLING); // interrupt 0 always connected to pin 2 on Arduino UNO
  attachInterrupt (1,rotarydetect2,FALLING); // interrupt 1 always connected to pin 3 on Arduino UNO
}


void loop ()  {

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
  }

// Runs if rotation was detected
  if (TurnDetected1)  {
     Serial.println("Turn detected 1");
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
        }
        
  }
  Serial.print("StepperPosition1 = ");Serial.println(StepperPosition1);
}
//}
