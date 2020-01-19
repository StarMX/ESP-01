#include <Arduino.h>
#include <config.h>
#include <wifi.h>
#include <mqtt.h>



void setup() {
  Serial.begin(115200);
	// Serial.setDebugOutput(true);
  setupWifi();
  setupMqtt();
}

void loop() {
  loopWifi();
  loopMqtt();
}