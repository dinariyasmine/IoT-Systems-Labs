const int ledPin = 6; // LED pin
const int interruptPin = 0; // Interrupt pin
volatile int state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), LED, CHANGE);
}

void loop() {
  digitalWrite(ledPin, state);
  delay(1000); // Simulate other tasks
}

void LED() {
  state = !state;
}