void setup() {
  pinMode(8, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(8);
  Serial.println(value);
  
  if (value == 0) {
    Serial.println("pressed");
  } else {
    Serial.println("released");
  }
  
  delay(100);
  digitalWrite(13, value);
}