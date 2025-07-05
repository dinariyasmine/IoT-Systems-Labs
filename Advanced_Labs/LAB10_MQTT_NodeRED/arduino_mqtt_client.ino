#include <WiFi.h>        // For Wi-Fi connectivity
#include <PubSubClient.h> // For MQTT functionality

// Wi-Fi credentials
char ssid[] = "Loading...";   // Wi-Fi name (SSID)
char pass[] = "helloworld";   // Wi-Fi password

// MQTT information
const char* mqttServer = "test.mosquitto.org";  // MQTT broker address
const int mqttPort = 1883;                      // MQTT port
const char* mqttTopicForce = "arduino/force";   // Topic for force sensor
const char* mqttTopicLDR = "arduino/ldr";       // Topic for light sensor

WiFiClient wifiClient;              // Wi-Fi client
PubSubClient client(wifiClient);    // MQTT client

void setup() {
    Serial.begin(115200);           // Initialize serial port
    WiFi.begin(ssid, pass);         // Connect to Wi-Fi
    
    // Wait for Wi-Fi connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to Wi-Fi...");
    }
    Serial.println("Wi-Fi connected!");
    
    // Set up MQTT client
    client.setServer(mqttServer, mqttPort);
    
    // Connect to MQTT broker
    while (!client.connected()) {
        Serial.println("Connecting to MQTT broker...");
        if (client.connect("ArduinoClient")) {
            Serial.println("Connected to broker!");
        } else {
            Serial.print("Failed to connect, rc=");
            Serial.print(client.state());
            delay(2000);
        }
    }
}

void loop() {
    // Read sensor data
    int forceSensorValue = analogRead(A1);  // Force sensor value
    int lightSensorValue = analogRead(A2);  // Light sensor value
    
    // Publish force sensor data
    char forceMessage[20];  // Buffer for message
    snprintf(forceMessage, sizeof(forceMessage), "%d", forceSensorValue);
    client.publish(mqttTopicForce, forceMessage);
    Serial.print("Force: ");
    Serial.println(forceMessage);
    
    // Publish light sensor data
    char lightMessage[20];  // Buffer for message
    snprintf(lightMessage, sizeof(lightMessage), "%d", lightSensorValue);
    client.publish(mqttTopicLDR, lightMessage);
    Serial.print("Light: ");
    Serial.println(lightMessage);
    
    delay(2000);  // Wait 2 seconds before next reading
}