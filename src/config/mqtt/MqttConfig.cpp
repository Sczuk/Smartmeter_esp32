#include "PubSubClient.h"
#include "WebServer.h"
#include "WiFi.h"
#include "config/mqtt/MqttConfig.h"
#include "mqtt/Mqtt.h"
#include "env.h"
#include "model/Smartmeter.h"


Mqtt mqtt;

MqttConfig::MqttConfig(WebServer& server, PubSubClient& client)
    : server(server), client(client)
{
}

void callback(char* topic, byte* payload, int length){
  mqtt.getTopicConfigDevice();

  Serial.print("message of topic: ");
  Serial.println(topic);

  String t = String(topic);
  String message;

  for(int i = 0; i<length; i++){
    message += (char)payload[i];
  }

  message.trim();

  if(t == mqtt.getTopicConfigDevice()){
    mqtt.configDevice(message);
  }
  if(t == mqtt.getTopicConfigSmartmeter()){
    mqtt.configSmartmeter(message);
  }
  if(t == mqtt.getTopicCommandRelay()){
    mqtt.turnOnOffRelay(message);
  }
  
}

void MqttConfig::connectBroker(){
  if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Wi-Fi not connected.");
      return;
  }

  boolean isBrokerConnected = initBroker(MQTT_BROKER_HOST, MQTT_BROKER_PORT);
  
  if(!isBrokerConnected){
    Serial.println("Not possible to connect, check the broker configuration and try again!!!");
    return;
  }

  Serial.println("Broker connected!!!");
  Serial.println();
}

boolean MqttConfig::initBroker(const char* ip, uint16_t port){
  String macAddress = WiFi.macAddress();
  String smartmeterMacAddress = "smartmeter-" + macAddress;
  int attempts = 0;
  client.setServer(ip, port);
  client.setBufferSize(1024);
  client.setCallback(callback);

  Serial.println("Connecting in Broker...");

  while(!client.connected() && attempts < 15){

    if (client.connect(smartmeterMacAddress.c_str(), USER_BROKER, PASSWORD_BROKER)) {
      break;
    }
    Serial.print("error to connect in broker, error code: ");
    Serial.println(client.state());
    attempts++;
    delay(1000);
  }

  if(!client.connected()){
    return false;
  }

  client.subscribe("test/connection");
  client.subscribe(mqtt.getTopicConfigSmartmeter().c_str());

  if(Smartmeter::getId() != ""){
    client.subscribe(mqtt.getTopicConfigDevice().c_str());

    if(!Device::getListDevices().empty()){
      client.subscribe(mqtt.getTopicCommandRelay().c_str());
    }

  }

  return true;
}