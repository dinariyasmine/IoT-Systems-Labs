void setup() {
  Serial.begin(9600);
  Serial.println("Arduino Serial Communication Demo");
  Serial.println("Sending test data...");
}

void loop() {
  Serial.print("Value: ");
  Serial.println(25);
  delay(2000);
}