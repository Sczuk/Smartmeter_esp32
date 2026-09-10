#include "config/wifi/WifiFlashMemory.h"
#include "Preferences.h"

void WifiFlashMemory::saveWifi(String ssid, String password){
    Preferences preferences;
    Serial.println("Saving the wifi cretentials in esp memory...");
    preferences.begin("wifiConfigs", false);
    preferences.putString("ssid", ssid);
    preferences.putString("password", password);
    preferences.end();
    Serial.println("Credential saved");
}
