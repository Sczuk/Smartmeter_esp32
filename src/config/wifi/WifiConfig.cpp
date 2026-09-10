#include "WiFi.h"
#include "WebServer.h"
#include "Preferences.h"
#include "config/wifi/WifiConfig.h"
#include "config/wifi/WifiView.h"

WifiConfig::WifiConfig(WebServer& server, WifiView& view)
    : server(server), view(view)
{
}

boolean WifiConfig::initWifi(String ssid, String password){
  int seconds = 0;
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");

  while(WiFi.status() != WL_CONNECTED && seconds < 15){
    seconds++;
    Serial.println(".");
    delay(1000);
  }

  if(WiFi.status() != WL_CONNECTED){
    Serial.println("not possible connect esp to wifi...");
    Serial.println("please verify the credentials");
    Serial.print("ssid: "); Serial.println(ssid);
    Serial.print("password: "); Serial.println(password);
    return false;
  }
  
  return true;
}

void WifiConfig::apWifi(){
  const char* ap_ssid = "Smartmeter_WiFi_Config";
  Serial.println("Connect your device on Smartmeter_WiFi_Config");
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ap_ssid,"");

  Serial.println("Web server init. access: http://192.168.4.1");

  server.on("/",[this]{
    getView().handleWifiRoot();
  });

  server.on("/saveWifi", HTTP_POST, [this]{
    getView().handleSaveWifi();
  });
  server.begin();
}

void WifiConfig::connectWifi(){
  Preferences preferences;
  preferences.begin("wifiConfigs", false);
  String ssid = preferences.getString("ssid", "");
  String password = preferences.getString("password", "");

  if(ssid == "" || password == ""){
    preferences.end();
    Serial.println("wifi not configured");
    apWifi();
    return;
  }

  boolean isWifiConnected = initWifi(ssid, password);
  
  if(!isWifiConnected){
    preferences.end();
    Serial.println("Retry connect");
    apWifi();
    return;
  }

  preferences.end();
  Serial.println("Wifi connected!!!");
}