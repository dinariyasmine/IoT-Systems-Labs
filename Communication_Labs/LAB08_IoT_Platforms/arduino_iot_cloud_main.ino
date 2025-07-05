#include "thingProperties.h"
const int ledPin = 7;

void setup() {
    Serial.begin(9600);
    delay(1500);
    pinMode(ledPin, OUTPUT);
    initProperties();
    ArduinoCloud.begin(ArduinoIoTPreferredConnection);
    setDebugMessageLevel(2);
    ArduinoCloud.printDebugInfo();
}

void loop() {
    ArduinoCloud.update();
}

// This function is called when 'orange_led_light' changes in the cloud
void onOrangeLedLightChange() {
    Serial.print("LED state changed to: ");
    Serial.println(orange_led_light);
    if (orange_led_light) {
        digitalWrite(ledPin, HIGH);  // LED ON
        Serial.println("LED is ON");
    } else {
        digitalWrite(ledPin, LOW);   // LED OFF
        Serial.println("LED is OFF");
    }
}