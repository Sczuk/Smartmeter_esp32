#pragma once

#include "WiFi.h"
#include "PubSubClient.h"

class CheckConnections{

public:

    void checkWifi();
    void checkMqtt(PubSubClient& client);
};


