const int ledPin = 0; // PWM pin
int brightness = 0; // brightness

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  analogWriteResolution(12); // Set PWM resolution to 12-bit (0-4095)
}

void loop() {
  // Increase brightness
  for (int i = 0; i <= 255; i++) {
    brightness = map(i, 0, 255, 0, 4095); // Convert 8-bit to 12-bit
    analogWrite(ledPin, brightness); // Set brightness
    delay(20); // transition
  }

  // Decrease brightness
  for (int i = 255; i >= 0; i--) {
    brightness = map(i, 0, 255, 0, 4095); // Convert 8-bit to 12-bit
    analogWrite(ledPin, brightness); // Set brightness
    delay(20);
  }
}