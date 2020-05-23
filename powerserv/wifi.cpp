#ifdef ESP8266
	#include <ESP8266WiFi.h>
#else
	#include <WiFi.h>
#endif

#include "credentials.h"
#include "wifi.h"

IPAddress staticIP(192, 168, 0, 42);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(192, 168, 0, 1);

const char *hname = "powerserv";

void setup_wifi(void)
{
	int tries = 0;
  
	delay(10);
	Serial.println();
	Serial.print("Connecting to ");
	Serial.println(wifi_ssid);

	if (!WiFi.config(staticIP, gateway, subnet)) {
		Serial.println("STA Failed to configure");
	}

#ifdef ESP8266
	WiFi.hostname(hname);
#else
	WiFi.setHostname(hname);
#endif

	WiFi.mode(WIFI_STA);
	WiFi.begin(wifi_ssid, wifi_password);

	while (WiFi.status() != WL_CONNECTED && tries < 50) {
		delay(500);
		Serial.println(".");
		tries++;
	}

	Serial.println("");
	Serial.println("WiFi connected");
	Serial.println("IP address: ");
	Serial.println(WiFi.localIP());
}
