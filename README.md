# ESP-01 

> RGB LED

![](/Doc/Images/RGB_LED.jpg )

Home Assistant
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

![](/Doc/Images/Relay.jpg)