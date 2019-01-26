# demo-esp8266
ESP8266 related sample codes

## [ESP8266-Tone-Starwars-Switch-dio](https://github.com/diobertdioneo/demo-esp8266/tree/master/ESP8266-Tone-Starwars-Switch-dio)
  This is a demo on how to output signal to GPIO pins by using LED and a passive buzzer. This demo also illustrates on how an input signal can be used to trigger and play a tune.
### How it works
  The device will wait until the push button switch is pressed and then the Starwars Imperial March tune will be played by the passive buzzer. There is a short count down before the tune is played. The built in LED in the ESP8266 will blink according the beat of the tune. The external green LED serves as an indicator if the song is being played.
### Bill of Materials
1. 1x ESP8266 NodeMCU LUA CP2102 ESP-12E
2. 1x Green LED
3. 1x Passive Buzzer
4. 1x Mini push button switch
5. 1x 100 ohm resistor
6. 1x breadboard
7. jumper wires
### Circuit diagram
![alt text](https://github.com/diobertdioneo/demo-esp8266/blob/master/common/images/ESP8266-Tone-Starwars-Switch-dio-design.png "Starwars Imperial March - Switch Triggered")

## [ESP8266-DHT-I2C-LCD-dio](https://github.com/diobertdioneo/demo-esp8266/tree/master/ESP8266-DHT-I2C-LCD-dio)
  This is a demo on how to interface with DHT11 Temperature and Humidity Module sensor and display the output to an LCD1602 Module via I2C.
### How it works
  The device will read the temperature and humidity from the DHT11 at an interval of 2 seconds or 2000 milliseconds, clear the display and then display the temperature in degree celcius and humidity.
### Bill of Materials
1. 1x ESP8266 NodeMCU LUA CP2102 ESP-12E
2. DHT11 Temperature and Humidity Module sensor
3. LCD1602 Display Module with I2C
4. jumper wires
### Circuit diagram
Have Fun!
