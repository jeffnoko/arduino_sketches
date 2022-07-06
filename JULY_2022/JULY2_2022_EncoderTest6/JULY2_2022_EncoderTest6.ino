
#define phaseA 2 // Pins for the encoder
#define phaseB 4

volatile int position;
volatile bool lastPhaseA, lastPhaseB;

void setup() {
  Serial.begin(9600);
  lastPhaseA =digitalRead(phaseA); // initial values
  lastPhaseB = digitalRead(phaseB);
  // Initialize interrupt
  // Configure OC0A for an interrupt
  OCR0A = 128; // Interrupt occurs midway between Arduino time interrupts
  TIMSK0 |= 1 << OCIE0A; // Enable the interrupt

}

void loop() {
  static int oldPosition;
  int pos;
  cli();
  pos = position; // atomic reference
  sei();
  if (pos != oldPosition) {
    oldPosition = pos;
    Serial.println(pos);
  }
}

ISR(TIMER0_COMPA_vect) {
  // Check to see if a pin has changed
  static uint8_t cnt; // check every 10 interrupts
  if (cnt-- == 0) {
    bool a = digitalRead(phaseA);
    bool b = digitalRead(phaseB);
    cnt = 10;
    if (lastPhaseA != a) {
      position += (a == b) ? -1 : 1;
      lastPhaseA = a;
    }
    if (lastPhaseB != b) {
      position += (a == b) ? 1 : -1;
      lastPhaseB = b;
    }
  }
}
