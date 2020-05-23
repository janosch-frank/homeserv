#ifndef __MQTT__
#define __MQTT__
void setup_mqtt(void);
void teardown_mqtt(void);
void mqtt_loop(void);
void mqtt_publish(char *topic, String val);
#endif
