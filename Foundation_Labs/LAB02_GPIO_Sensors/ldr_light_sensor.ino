const int LDR_pin = A0;
int lightVal;

void setup() {
  Serial.begin(9600);
}

void loop() {
  lightVal = analogRead(LDR_pin);
  Serial.print("Light value is: ");
  Serial.println(lightVal);
  delay(1000);
}