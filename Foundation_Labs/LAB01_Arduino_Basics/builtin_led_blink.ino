// setup(): function runs once when the arduino starts
void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Set the built-in LED as an output
}

// loop(): Repeats indefinitely after setup() has finished executing
void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // Turn on the LED
  delay(2000); // Wait for 2 second
  digitalWrite(LED_BUILTIN, LOW); // Turn off the LED
  delay(2000); // Wait for 2 second
}