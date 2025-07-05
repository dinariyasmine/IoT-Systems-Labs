const int forceSensorInput = A1; // Force sensor (analog)
const int pushbutton = 2; // Pushbutton (digital, interrupt)
const int ledBlue = 8; // LED1
const int ledYellow = 7; // LED2

int lastButtonState = HIGH; // Previous button state

void setup() {
  Serial.begin(9600);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(pushbutton, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(pushbutton), handleButtonPress, CHANGE);
}

void loop() {
  int buttonState = digitalRead(pushbutton);
  int forceSensor = analogRead(forceSensorInput);

  Serial.print("Force Sensor Value: ");
  Serial.print(forceSensor);
  Serial.print(" | Button State: ");
  Serial.println(buttonState == HIGH ? "HIGH" : "LOW");

  // Control the blue LED based on the force sensor value
  digitalWrite(ledBlue, forceSensor > 50 ? HIGH : LOW);

  // Toggle yellow LED on button release
  if (buttonState == HIGH && lastButtonState == LOW) {
    digitalWrite(ledYellow, !digitalRead(ledYellow));
  }

  lastButtonState = buttonState; // Save state for next loop
  delay(100); // Short delay for stability
}

void handleButtonPress() {
  Serial.println("Interrupt Triggered!");
  delay(100); // Small debounce delay
}