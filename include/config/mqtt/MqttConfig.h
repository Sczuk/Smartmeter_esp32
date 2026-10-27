#pragma once

#include "WebServer.h"
#include "PubSubClient.h"

class MqttConfig{

    private:
        WebServer& server;
        PubSubClient& client;

    public:
        MqttConfig(WebServer& server, PubSubClient& client);
        void connectBroker();
        boolean initBroker(const char* ip, uint16_t port);

        PubSubClient& getClient(){return client;}

};