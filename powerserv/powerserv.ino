#include "wifi.h"
#include "mqtt.h"
#include "switch.h"

void setup(void) {
     Serial.begin(9600);
     setup_wifi();
     setup_mqtt();
     setup_switch();
}

void loop() {
	mqtt_loop();
}
