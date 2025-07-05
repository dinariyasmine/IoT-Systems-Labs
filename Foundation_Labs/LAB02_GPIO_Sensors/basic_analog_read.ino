const int pin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lightVal = analogRead(pin);
  Serial.print("Analog value: ");
  Serial.println(lightVal);
  delay(500);
}