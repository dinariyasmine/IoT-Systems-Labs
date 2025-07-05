void setup()
{
  pinMode(A1, INPUT); // Force sensor
  pinMode(8, OUTPUT); // LED output
  Serial.begin(9600); // Start serial communication
}

void loop()
{
  int forceSensor = analogRead(A1); // Read sensor value

  if (forceSensor > 100) {
    digitalWrite(8, HIGH); // Turn LED on
  } else {
    digitalWrite(8, LOW); // Turn LED off
  }

  Serial.print("force = ");
  Serial.println(forceSensor);
  delay(100);
}