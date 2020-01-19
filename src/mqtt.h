
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFiClient.h>




WiFiClient espClient;
PubSubClient client(espClient);

StaticJsonDocument<256> doc;
char mqttFeedWithId[100];
char deviceIdChar[8];
char mqttWillTopic[100];
char mqttCmdTopic[100];

#ifdef Esp01_Relay
  #include <Esp01_Relay.h>
#endif

#ifdef Esp01_RGB_LED
  #include <Esp01_RGB_LED.h>
#endif


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println("Message arrived:");
  Serial.print("\tjson string:\t");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println("");

  // JSON parser
  deserializeJson(doc, payload, length);
  //JsonObject obj = doc.as<JsonObject>();
#ifdef Esp01_RGB_LED
  ledCallback();
#endif
#ifdef Esp01_Relay
  relayCallback();
#endif
}

void setupMqtt() {
  sprintf(deviceIdChar, "%lu", deviceId);
  snprintf(mqttFeedWithId, sizeof(mqttFeedWithId), mqttFeed, deviceIdChar);
  sprintf(mqttWillTopic,"%s%s", mqttFeedWithId, "lwt");
  sprintf(mqttCmdTopic,"%s%s", mqttFeedWithId, "cmd");
  // Connection
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

#ifdef Esp01_Relay
  setupRelay();
#endif

#ifdef Esp01_RGB_LED
  setupRGBLED();
#endif
}

void loopMqtt() {
  if (!client.connected()) {
    Serial.println(F("\n▶ MQTT"));
    // Connecting
    Serial.print(F("Connecting to \""));
    Serial.print(mqttServer);
    Serial.print(F("\"\t"));
  
    while (!client.connected()) {
      if (client.connect(deviceIdChar, mqttUsername, mqttPassword, mqttWillTopic, mqttQos, mqttRetain, "Offline")) {
        Serial.print("\nStatus:\t\tMQTT connected. State ");
        Serial.println(client.state());
        client.publish(mqttWillTopic, "Online", true);
        client.subscribe(mqttCmdTopic);
 #ifdef Esp01_RGB_LED
  ledSendState();
#endif
#ifdef Esp01_Relay
  relaySendState();
#endif

      } else {
        Serial.print(F("."));
        delay(1000);
      }
    }
  }
  client.loop();
#ifdef Esp01_RGB_LED
  loopRGBLED();
#endif
}
