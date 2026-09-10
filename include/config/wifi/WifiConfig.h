#pragma once

#include "config/wifi/WifiView.h"
#include "WebServer.h"

class WifiConfig{

    private:
        WebServer& server;
        WifiView& view;

    public:
        WifiConfig(WebServer& server, WifiView& view);
        boolean initWifi(String ssid, String password);
        void apWifi();
        void connectWifi();
        
        WifiView& getView(){ return view; }
};