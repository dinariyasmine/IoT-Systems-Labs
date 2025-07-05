#include <WiFiNINA.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect
  }
  
  // Initialize WiFi module
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (true);
  }
  
  scan_networks();
}

void loop() {
  // Main loop can be empty or add periodic scanning
}

void scan_networks() {
  Serial.println("Scanning for available networks...");
  int numNetworks = WiFi.scanNetworks();
  
  for (int i = 0; i < numNetworks; i++) {
    Serial.print("Network ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(WiFi.SSID(i)); // Get network name
    Serial.print(" (Signal Strength: ");
    Serial.print(WiFi.RSSI(i)); // Get signal strength
    Serial.println(" dBm)");
  }
}