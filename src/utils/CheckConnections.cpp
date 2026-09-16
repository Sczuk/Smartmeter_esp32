#include "utils/CheckConnections.h"
#include "WiFi.h"
#include "config/mqtt/MqttConfig.h"
#include "env.h"
#include "Preferences.h"
#include "PubSubClient.h"

void CheckConnections::checkWifi(){
    while(WiFi.status() != WL_CONNECTED){ // 3 = connected, 6 = disconnected
        Serial.println("WiFi connetion lost, trying connect...");
        WiFi.reconnect();
        Serial.print("Wifi status: "); Serial.println(WiFi.status()); Serial.println();
        delay(1000);
    }
}

void CheckConnections::checkMqtt(MqttConfig& mqttConfig, PubSubClient& client){
    while(!client.connected()){
        Preferences preferences;
        preferences.begin("mqtt", false);
        const String ip = preferences.getString("ip", "");
        const char* ipChar = ip.c_str();
        preferences.end();

        Serial.println("Broker connetion lost, trying connect...");
        Serial.print("Broker status: "); Serial.println(client.state()); Serial.println();
        mqttConfig.initBroker(ipChar);

        if(client.connected()){
            Serial.println("Broker reconnected!!!");
        }
    }
    
}