#include "Preferences.h"
#include "config/mqtt/MqttFlashMemory.h"

void MqttFlashMemory::saveBroker(String mqttIp){
    Preferences preferences;
    Serial.println("Saving the server mqtt ip....");
    preferences.begin("mqtt", false);
    preferences.putString("ip",mqttIp);
    preferences.end();
    Serial.println("Ip saved");
}
