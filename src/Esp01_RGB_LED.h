#ifdef Esp01_RGB_LED

#include <WS2812FX.h>

WS2812FX ws2812fx = WS2812FX(Esp01_Led_Count, Esp01_Pin, NEO_GRB + NEO_KHZ800);

byte red = 0;
byte green = 123;
byte blue = 255;
byte white = 255;
char mqttStateTopic[200];


uint32_t getColorInt()
{
  return ((uint32_t)white << 24) | ((uint32_t)green << 16) | ((uint32_t)red << 8) | blue;
}

int effectNumber(String effect)
{
  String effects[MODE_COUNT];
  for (uint8_t i = 0; i < ws2812fx.getModeCount(); i++)
  {
    effects[i] = ws2812fx.getModeName(i);
  }
  int effectNo = -1;
  for (int i = 0; i < MODE_COUNT; i++)
  {
    if (effect == effects[i])
    {
      effectNo = i;
      break;
    }
  }
  return effectNo;
}

void setupRGBLED() {
  ws2812fx.init();
  ws2812fx.setBrightness(255);
  //ws2812fx.setSpeed(1000);
  ws2812fx.setColor(getColorInt());
  ws2812fx.setMode(FX_MODE_STATIC);//(FX_MODE_RAINBOW_CYCLE);
  ws2812fx.start();
}

void ledSendState(){
  DynamicJsonDocument root(100);
  root["state"] = (ws2812fx.isRunning()) ? "ON" : "OFF";
  if (ws2812fx.isRunning())
  {
    root["white_value"] = white;
    root["brightness"] = ws2812fx.getBrightness();
    root["effect"] = String(ws2812fx.getModeName(ws2812fx.getMode()));
    root["speed"] = ws2812fx.getSpeed();
    root["color"]["r"] = red;
    root["color"]["g"] = green;
    root["color"]["b"] = blue;
  }
  String json;
  serializeJson(root, json);
  root.clear();
  sprintf(mqttStateTopic,"%s%s", mqttFeedWithId, "state");
  client.publish(mqttStateTopic, json.c_str());
}



void ledCallback() {
  JsonObject root = doc.as<JsonObject>();
  if (root.isNull() == false) {
    if (root.containsKey("state"))
    {
      if (strcmp(root["state"], "ON") == 0)
      {
        ws2812fx.start();
      }
      else if (strcmp(root["state"], "OFF") == 0)
      {
        ws2812fx.stop();
      }
    }
    if (root.containsKey("effect"))
      {
        ws2812fx.setMode(effectNumber(root["effect"]));
      }
    
      if (root.containsKey("color"))
      {
        red = root["color"]["r"];
        green = root["color"]["g"];
        blue = root["color"]["b"];
        ws2812fx.setColor(red, green,blue);
        //ws2812fx.setColor(getColorInt());
      }
    
      if (root.containsKey("white_value"))
      {
        white = root["white_value"];
        ws2812fx.setColor(getColorInt());
      }
    
      if (root.containsKey("brightness"))
      {
        ws2812fx.setBrightness(root["brightness"]);
      }
    
      if (root.containsKey("speed"))
      {
        ws2812fx.setSpeed(root["speed"]);
      }
    // Clear the document
    ledSendState();
  }
}




void loopRGBLED() {
  ws2812fx.service();
}
#endif