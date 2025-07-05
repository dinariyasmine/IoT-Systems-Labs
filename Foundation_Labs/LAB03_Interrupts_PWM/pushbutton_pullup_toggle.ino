const int forceSensorInput = A1; // Analog pin for force sensor
const int pushbutton = 2; // Digital pin for pushbutton
const int ledBlue = 8; // LED controlled by force sensor
const int ledYellow = 7; // LED controlled by pushbutton

bool pushButtonState = HIGH;
bool lastStatePushButton = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(pushbutton, INPUT_PULLUP); // Enable internal pull-up resistor for button
}

void loop() {
  int forceSensor = analogRead(forceSensorInput); // Read force sensor value
  pushButtonState = digitalRead(pushbutton); // Read button state

  Serial.print("Force: ");
  Serial.println(forceSensor);

  // Turn on LED1 if force sensor detects pressure
  digitalWrite(ledBlue, forceSensor > 50 ? HIGH : LOW);

  // Detect button press and release to toggle LED2
  if (pushButtonState == LOW && lastStatePushButton == HIGH) {
    Serial.println("Button Pressed");
  }
  else if (pushButtonState == HIGH && lastStatePushButton == LOW) {
    Serial.println("Button Released");
    digitalWrite(ledYellow, !digitalRead(ledYellow)); // Toggle LED2 state
  }

  lastStatePushButton = pushButtonState;
  delay(400); // Small delay to prevent rapid toggling
}