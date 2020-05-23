# Powerserv

This software lets you control some of the newer radio controlled
433MHZ power outlets like the Brennenstuhl RC CE1 4001 via a
ESP8266/ESP32 over MQTT. Those outlets do not have the DIP switches to
set the group they belong to. Instead they *learn* which group they
belong to and can listen to multiple command codes.

The following libraries are required: 
* rc-switch
* PubSubClient

To send commands to the power outlets you will need a superheterodyne
433MHz transmitter an a IO pin of the ESP. The pin can be specified
via the *SWITCH_PIN* constant in *switch.cpp*.

The rc-switch configuration for those kinds of remote controlled power
outlets was taken from this thread in a German forum:
https://forum.pimatic.org/topic/3337/433-mhz-funksteckdosen-lidl-silvercrest-rcr-dp3-3711-a-brennenstuhl-mit-homeduino/37

It would be better if you log and use the on/off codes from your
remote control instead of using the ones provided. If your outlets
start going on or off on their own, it might be time to change the
predefined codes.
