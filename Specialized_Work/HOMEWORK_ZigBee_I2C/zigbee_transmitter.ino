/* Transmitter.ino file for ZigBee communication
 * Created: sam. mai 3 2025
 * Processor: Arduino Uno
 * Compiler: Arduino AVR (Proteus)
 */

#pragma GCC push_options
#pragma GCC optimize("O1")

// Define pin for pushbutton
const int buttonPin = 2; // Pushbutton connected to pin 2

// Variables
int buttonState = 0;     // Current state of the button
int lastButtonState = 0; // Previous state of the button

void setup() {
  // Initialize serial communications at 9600 bps
  Serial.begin(9600);
  
  // Initialize the pushbutton pin as input with pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Print startup message
  Serial.println("ZigBee Transmitter Ready");
  Serial.println("Button on pin 2, using INPUT_PULLUP mode");
}

void loop() {
  // Read the state of the pushbutton (inverted due to pull-up)
  buttonState = !digitalRead(buttonPin);
  
  // Check if button state has changed
  if (buttonState != lastButtonState) {
    // If button is pressed (HIGH)
    if (buttonState == HIGH) {
      Serial.println("Button pressed - sending ON command");
      Serial.write('1'); // Send '1' character to turn LED ON
    } else {
      Serial.println("Button released - sending OFF command");
      Serial.write('0'); // Send '0' character to turn LED OFF
    }
    
    // Update the last button state
    lastButtonState = buttonState;
    
    // Small delay to prevent bouncing
    delay(50);
  }
}

#pragma GCC pop_options