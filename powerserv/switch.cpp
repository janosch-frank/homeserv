#ifdef ESP8266
	#include <ESP8266WiFi.h>
#else
	#include <WiFi.h>
#endif
#include <RCSwitch.h>

#define SWITCH_PIN 2
#define SWITCH_PROTO 4
#define SWITCH_PULSE 384

RCSwitch mySwitch = RCSwitch();

unsigned long channel_off[] = {
			       12494204,
			       11742165,
			       11940014,
			       11559223,
};

unsigned long channel_on[] = {
			      11940012,
			      11704053,
			      12494206,
			      11742167,
};

void switch_off(int num)
{
	mySwitch.send(channel_off[num], 24);
}

void switch_on(int num)
{
	mySwitch.send(channel_on[num], 24);
}

void setup_switch(void)
{
	mySwitch.enableTransmit(SWITCH_PIN);
  	mySwitch.setProtocol(SWITCH_PROTO);
	mySwitch.setPulseLength(SWITCH_PULSE);
} 
