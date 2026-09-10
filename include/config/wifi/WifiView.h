#pragma once

#include "WebServer.h"

class WifiView{

    private:
        WebServer& server;

    public:
        WifiView(WebServer& server);
        void handleWifiRoot();
        void handleSaveWifi();
        
        WebServer& getServer()  { return server; }
};