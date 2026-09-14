#include "Preferences.h"
#include "PubSubClient.h"
#include "WebServer.h"
#include "WiFi.h"
#include "config/mqtt/MqttView.h"
#include "config/mqtt/MqttConfig.h"
#include "mqtt/Mqtt.h"
#include "env.h"
#include "model/Smartmeter.h"


Mqtt mqtt;

MqttConfig::MqttConfig(WebServer& server, MqttView& view, PubSubClient& client)
    : server(server), view(view), client(client)
{
}

void callback(char* topic, byte* payload, int length){
  mqtt.setTopicConfigDevice(Smartmeter::getId());

  Serial.print("message of topic: ");
  Serial.println(topic);

  String t = String(topic);
  String message;

  for(int i = 0; i<length; i++){
    message += (char)payload[i];
  }

  if(t == mqtt.getTopicConfigDevice()){
    mqtt.configDevice(message);
  }
  if(t == mqtt.getTopicConfigSmartmeter()){
    mqtt.configSmartmeter(message);
  }
  
}

void MqttConfig::apBroker(){

  const char* ap_ssid = "Smartmeter_Broker_Config";
  Serial.println("Connect your device on Smartmeter_Broker_Config");
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ap_ssid,"");

  Serial.println("Web server init. access: http://192.168.4.1");

  server.on("/", [this]() {
    getView().handleBrokerRoot();
    });

  server.on("/saveBroker", HTTP_POST, [this]() {
    getView().handleSaveBroker();
    });

  server.begin();

  while(!client.connected()){
    server.handleClient();
    delay(10);
  }

}

void MqttConfig::connectBroker(){
  Preferences preferences;
  preferences.begin("mqtt", false);
  const String ip = preferences.getString("ip", "");
  const char* ipChar = ip.c_str();
  
  if(ip == ""){
    preferences.end();
    Serial.println("ip not configured");
    apBroker();
    return;
  }

  boolean isBrokerConnected = initBroker(ipChar);
  
  if(!isBrokerConnected){
    preferences.end();
    Serial.println("Retry connect");
    Serial.print("Ip: ");
    Serial.println(ip);
    Serial.println("Not possible to connect");
    apBroker();
    return;
  }

  preferences.end();
  Serial.println("Broker connected!!!");
  Serial.println();
}

boolean MqttConfig::initBroker(const char* ip){
  int seconds = 0;
  client.setServer(ip, 1883);
  client.setCallback(callback);

  Serial.println("Connecting in Broker...");
  while(!client.connected() && seconds < 15){
    client.connect("esp32client", USER_BROKER, PASSWORD_BROKER);
    seconds++;
    Serial.println(".");
    delay(1000);
  }

  if(!client.connected()){
    return false;
  }

  client.subscribe("test/connection");
  client.subscribe(mqtt.getTopicConfigDevice().c_str());
  client.subscribe(mqtt.getTopicConfigSmartmeter().c_str());

  return true;
}