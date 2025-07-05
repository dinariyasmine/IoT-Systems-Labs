const int LDR_pin = A0;
const int button_pin = 8;
const int LED_pin = 13;

void setup() {
  pinMode(button_pin, INPUT);
  pinMode(LED_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightVal = analogRead(LDR_pin);
  int buttonState = digitalRead(button_pin);
  
  Serial.print("Light value: ");
  Serial.println(lightVal);
  
  if (buttonState == LOW && lightVal < 500) {
    digitalWrite(LED_pin, HIGH); // Turn on LED if button is pressed and light is dim
    Serial.println("LED ON");
  } else {
    digitalWrite(LED_pin, LOW); // Turn off LED otherwise
    Serial.println("LED OFF");
  }
  
  delay(100);
}