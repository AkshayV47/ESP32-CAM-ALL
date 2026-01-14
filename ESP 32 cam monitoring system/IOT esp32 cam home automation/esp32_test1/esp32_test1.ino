#include "esp_camera.h"
#include <WiFi.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Pin definition for ESP32-CAM
#define LED_PIN 4

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Example fingerUp array for testing
  int fingerUp[5] = {0, 1, 1, 0, 0};
  led(fingerUp);
  delay(1000);
}

void led(int fingerUp[5]) {
  if (fingerUp[0] == 0 && fingerUp[1] == 0 && fingerUp[2] == 0 && fingerUp[3] == 0 && fingerUp[4] == 0) {
    digitalWrite(LED_PIN, LOW);
  } else if (fingerUp[0] == 0 && fingerUp[1] == 1 && fingerUp[2] == 0 && fingerUp[3] == 0 && fingerUp[4] == 0) {
    digitalWrite(LED_PIN, HIGH);
  } else if (fingerUp[0] == 0 && fingerUp[1] == 1 && fingerUp[2] == 1 && fingerUp[3] == 0 && fingerUp[4] == 0) {
    digitalWrite(LED_PIN, HIGH);
  } else if (fingerUp[0] == 0 && fingerUp[1] == 1 && fingerUp[2] == 1 && fingerUp[3] == 1 && fingerUp[4] == 0) {
    digitalWrite(LED_PIN, HIGH);
  } else if (fingerUp[0] == 0 && fingerUp[1] == 1 && fingerUp[2] == 1 && fingerUp[3] == 1 && fingerUp[4] == 1) {
    digitalWrite(LED_PIN, HIGH);
  } else if (fingerUp[0] == 1 && fingerUp[1] == 1 && fingerUp[2] == 1 && fingerUp[3] == 1 && fingerUp[4] == 1) {
    digitalWrite(LED_PIN, HIGH);
  }
}
