#pragma once

#include "WiFi.h"
#include "config/mqtt/MqttConfig.h"
#include "PubSubClient.h"

class CheckConnections{

public:

    void checkWifi();
    void checkMqtt(MqttConfig& mqttConfig, PubSubClient& client);
};


