#include "utils/CheckConnections.h"
#include "WiFi.h"
#include "PubSubClient.h"

void CheckConnections::checkWifi(){
    while(WiFi.status() != WL_CONNECTED){ // 3 = connected, 6 = disconnected
        Serial.println("WiFi connetion lost, trying connect...");
        WiFi.reconnect();
        Serial.print("Wifi status: "); Serial.println(WiFi.status()); Serial.println();
        delay(1000);
    }
}

void CheckConnections::checkMqtt(PubSubClient& client){
    while(!client.connected()){
        Serial.println("Broker connetion lost, trying connect...");
        client.connect("esp32client", "user1", "12345");
        Serial.print("Broker status: "); Serial.println(client.state()); Serial.println();
    } 
}