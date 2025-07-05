/* Receiver.ino file for ZigBee communication
 * Created: sam. mai 3 2025
 * Processor: Arduino Uno
 * Compiler: Arduino AVR (Proteus)
 */

#pragma GCC push_options
#pragma GCC optimize("O1")

// Define pin for LED
const int ledPin = 12; // LED connected to pin 12

void setup() {
  // Initialize serial communications at 9600 bps
  Serial.begin(9600);
  
  // Initialize the LED pin as output
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Initially turn off the LED
  
  // Print startup message
  Serial.println("ZigBee Receiver Ready");
  Serial.println("LED connected to pin 12");
  
  // Test LED at startup
  Serial.println("Testing LED...");
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  Serial.println("LED test complete");
}

void loop() {
  // Check if data is available from serial (XBee)
  if (Serial.available() > 0) {
    // Read the incoming byte
    char command = Serial.read();
    
    // Process the command
    if (command == '1') {
      Serial.println("Received ON command - Turning LED ON");
      digitalWrite(ledPin, HIGH); // Turn LED ON
    }
    else if (command == '0') {
      Serial.println("Received OFF command - Turning LED OFF");
      digitalWrite(ledPin, LOW); // Turn LED OFF
    }
  }
}

#pragma GCC pop_options