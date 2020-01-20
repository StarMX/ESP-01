# ESP-01 模块

使用方式 重命名 config.h.example 为 config.h 修改内部代码 

以下两个模块如果使用那个则注释掉外的模块 例如要使用 RBG_LED
```
// #define Esp01_Relay
#define Esp01_RGB_LED
#define Esp01_Led_Count 24 //这里的24修改为你灯带LED的数量

```
要使用Relay模块则注释 
```
#define Esp01_Relay
// #define Esp01_RGB_LED
#define Esp01_Led_Count 24
```

***其他*** 

app_name ap_password 为入网使用 可不修改 连入AP后自动进入配网页面

mqtt信息按需要修改


> RGB LED

示例图片

![image](/Doc/Images/RGB_LED.jpg )

### Home Assistant 配置文件
```
light:
  - platform: mqtt
    schema: json
    name: "led ??????"
    state_topic: "home/StarZ_??????/state"
    command_topic: "home/StarZ_??????/cmd"
    availability_topic: "home/StarZ_??????/lwt"
    payload_available: "Online"
    payload_not_available: "Offline"
    brightness: true
    rgb: true
    white_value: true
    effect: true
    effect_list:
    - Static
    - Blink
    - Breath
    - Color Wipe
    - Color Wipe Inverse
    - Color Wipe Reverse
    - Color Wipe Reverse Inverse
    - Color Wipe Random
    - Random Color
    - Single Dynamic
    - Multi Dynamic
    - Rainbow
    - Rainbow Cycle
    - Scan
    - Dual Scan
    - Fade
    - Theater Chase
    - Theater Chase Rainbow
    - Running Lights
    - Twinkle
    - Twinkle Random
    - Twinkle Fade
    - Twinkle Fade Random
    - Sparkle
    - Flash Sparkle
    - Hyper Sparkle
    - Strobe
    - Strobe Rainbow
    - Multi Strobe
    - Blink Rainbow
    - Chase White
    - Chase Color
    - Chase Random
    - Chase Rainbow
    - Chase Flash
    - Chase Flash Random
    - Chase Rainbow White
    - Chase Blackout
    - Chase Blackout Rainbow
    - Color Sweep Random
    - Running Color
    - Running Red Blue
    - Running Random
    - Larson Scanner
    - Comet
    - Fireworks
    - Fireworks Random
    - Merry Christmas
    - Fire Flicker
    - Fire Flicker (soft)
    - Fire Flicker (intense)
    - Circus Combustus
    - Halloween
    - Bicolor Chase
    - Tricolor Chase
    - ICU
    optimistic: false
    qos: 0
```


> Relay

示例图片
![image](/Doc/Images/Relay.jpg)