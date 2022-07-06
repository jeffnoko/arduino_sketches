

#define outputA 6
 #define outputB 7

 int counter = 0; 
 int State1,State2;
 int LastState;  

 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   LastState = digitalRead(outputA);   
 } 

 void loop() { 
   State1 = digitalRead(outputB); // Reads the "current" state of the outputA
  // State2 = digitalRead(outputA);
   //Serial.print("State1 ="); Serial.println(State1);
   // Serial.print("State2 ="); Serial.println(State2);
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (State1 != LastState){  
    Serial.println("hello");   
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != State1) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
   } 
   LastState = State1; // Updates the previous state of the outputA with the current state
 }
