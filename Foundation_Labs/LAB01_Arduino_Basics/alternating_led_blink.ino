#define EXTERNAL_LED 12 // Define the external LED pin

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Set the built-in LED as an output
  pinMode(EXTERNAL_LED, OUTPUT); // Set the external LED as an output
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // Turn ON built-in LED
  digitalWrite(EXTERNAL_LED, LOW); // Turn OFF external LED
  delay(1000); // Wait for 1 second
  
  digitalWrite(LED_BUILTIN, LOW); // Turn OFF built-in LED
  digitalWrite(EXTERNAL_LED, HIGH); // Turn ON external LED
  delay(1000); // Wait for 1 second
}