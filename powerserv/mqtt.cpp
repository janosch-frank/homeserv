#ifdef ESP8266
	#include <ESP8266WiFi.h>
#else
	#include <WiFi.h>
#endif
#define MQTT_SOCKET_TIMEOUT 10
#include <PubSubClient.h>
#include <string.h>

#include "credentials.h"
#include "switch.h"

WiFiClient espClient;
PubSubClient client(espClient);

#define mqtt_server "192.168.178.111"
#define mqtt_client_id "powerserv"

static void callback(char *topic, byte *payload, unsigned int length) {
	int strln = strlen(topic);
	int sw = atoi(&topic[strln - 1]);
	
	/*
	 * Yes this a incredibly crude way to find out if we want to
	 * switch on or off.
	 */
	if (payload[1] == 'N') {
		switch_on(sw);
	} else {
		switch_off(sw);
	}
}

static void reconnect() {
	while (!client.connected()) {
		Serial.print("Attempting MQTT connection...");

		if (client.connect(mqtt_client_id, mqtt_user, mqtt_password)) {
			Serial.println("connected");
			client.subscribe("home/switch/#");
		} else {
			Serial.print("failed, rc=");
			Serial.print(client.state());
			Serial.println(" try again in 5 seconds");
			// Wait 5 seconds before retrying
			delay(5000);
		}
	}
}

void mqtt_loop(void)
{
	if (!client.connected()) {
		reconnect();
	} else {
		client.loop();
	}  
}

void setup_mqtt(void)
{
	client.setServer(mqtt_server, 1883);
	client.setCallback(callback);
	reconnect();
}

void teardown_mqtt(void)
{
	client.loop();
	client.disconnect();
}

void mqtt_publish(char *topic, String val)
{
	client.publish(topic, val.c_str(), true);
	delay(1000);
}
