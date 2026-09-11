#pragma once

#include "WebServer.h"

class MqttView{
    private:
        WebServer& server;

    public:
        MqttView(WebServer& server);
        void handleBrokerRoot();
        void handleSaveBroker();

        WebServer& getServer()  { return server; }
};