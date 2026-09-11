#pragma once

#include "WebServer.h"
#include "config/mqtt/MqttView.h"
#include "PubSubClient.h"

class MqttConfig{

    private:
        WebServer& server;
        MqttView& view;
        PubSubClient& client;

    public:
        MqttConfig(WebServer& server, MqttView& view, PubSubClient& client);
        void apBroker();
        void connectBroker();
        boolean initBroker(const char* ip);

        MqttView& getView() {return view;}
        PubSubClient& getClient(){return client;}

};