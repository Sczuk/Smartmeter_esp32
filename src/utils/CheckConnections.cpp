#include "utils/CheckConnections.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include "config/mqtt/MqttConfig.h"
#include "env.h"

void CheckConnections::checkWifi() {
    static unsigned long lastAttempt = 0;
    const unsigned long retryInterval = 5000;

    if (WiFi.status() == WL_CONNECTED) {
        return;
    }

    if (millis() - lastAttempt >= retryInterval) {
        lastAttempt = millis();

        Serial.println("Wi-Fi desconectado. Tentando reconectar...");
        WiFi.reconnect();
    }
}

void CheckConnections::checkMqtt(MqttConfig& mqttConfig, PubSubClient& client) {
    static unsigned long lastAttempt = 0;
    const unsigned long retryInterval = 5000;

    if (WiFi.status() != WL_CONNECTED || client.connected()) {
        return;
    }

    if (millis() - lastAttempt >= retryInterval) {
        lastAttempt = millis();

        Serial.println("MQTT desconectado. Tentando reconectar...");

        if (mqttConfig.initBroker(MQTT_BROKER_HOST, MQTT_BROKER_PORT)) {
            Serial.println("Broker reconectado!");
        }
    }
}