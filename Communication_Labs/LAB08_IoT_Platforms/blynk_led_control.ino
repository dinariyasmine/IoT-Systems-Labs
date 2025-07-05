#define BLYNK_TEMPLATE_ID "TMPL2uux9Izrm"
#define BLYNK_TEMPLATE_NAME "LAB8"
#define BLYNK_AUTH_TOKEN "pXOmrytxE94touimZWz-41lvP-zfkW1c"

// Include required libraries for Blynk and WiFi
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>

// Wi-Fi credentials (change these to match your local network)
char ssid[] = "ALHN-A013";  // Wi-Fi name (SSID)
char pass[] = "9999999";    // Wi-Fi password

void setup() {
    Serial.begin(115200);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    pinMode(7, OUTPUT);  // Set digital pin 7 as an output (connected to LED)
}

BLYNK_WRITE(V0) {
    int ledState = param.asInt();  // Read value from Blynk (0 or 1)
    digitalWrite(7, ledState);     // Turn LED ON if 1, OFF if 0
}

void loop() {
    Blynk.run();
}