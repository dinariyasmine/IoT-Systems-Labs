const int ledPin = 0; // PWM pin for LED
const int ldrPin = A1; // Analog pin for LDR

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
}

void loop() {
  int lightLevel = analogRead(ldrPin); // Read light level from LDR (0-1023)

  // Map light level to LED brightness (8-bit range)
  int brightness = map(lightLevel, 0, 1023, 0, 255);

  // Set LED brightness using PWM
  analogWrite(ledPin, brightness);

  delay(5); // Small delay for stability
}