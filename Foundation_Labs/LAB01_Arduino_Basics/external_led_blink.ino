#define EXTERNAL_LED 12 // Define the external LED pin

void setup() {
  pinMode(EXTERNAL_LED, OUTPUT); // Set the external LED as an output
}

void loop() {
  digitalWrite(EXTERNAL_LED, HIGH); // Turn on the external LED
  delay(2000); // Wait for 2 seconds
  digitalWrite(EXTERNAL_LED, LOW); // Turn off the external LED
  delay(2000); // Wait for 2 seconds
}