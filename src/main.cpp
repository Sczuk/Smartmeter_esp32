#include <Arduino.h>
#include "PubSubClient.h"
#include "WebServer.h"
#include "Mux.h"
#include <vector>

#include "utils/CalculatePower.h"
#include "utils/Json.h"
#include "utils/CheckConnections.h"

#include "model/Smartmeter.h"
#include "model/Device.h"

#include "mqtt/Mqtt.h"

#include "config/mqtt/MqttConfig.h"
#include "config/mqtt/MqttView.h"
#include "config/wifi/WifiConfig.h"
#include "config/wifi/WifiView.h"

WebServer server(80);
WiFiClient espClient;
PubSubClient client(espClient);

CheckConnections checkConnections;

WifiView wifiView(server);
WifiConfig wifiConfig(server, wifiView);

MqttView mqttView(server);
MqttConfig mqttConfig(server, mqttView, client);


std::vector<Device> devices;
String smartmeterId;

//pin(pino z, tipo, tipo::enum), pinset(s0, s1, s2)
using namespace admux;
Mux mux(Pin(32, OUTPUT, PinType::Analog), Pinset(21, 22, 23));

unsigned long lastPublish = 0;
const unsigned long publishInterval = 60000;
const unsigned long configDeviceInterval = 120000;


void setup() {
    Serial.begin(115200);
    Serial.println("ESP iniciou!");

    wifiConfig.connectWifi();
    mqttConfig.connectBroker();

    devices = Device::getListDevices();
    smartmeterId = Smartmeter::getId();

    if(devices.size() == 0){
        Serial.println("This Smartmeter, dont have Devices.");
        Serial.println("Please configure new Devices, to do this Smartmeter work");
        Serial.println();
        Serial.println("Smartmeter going restart in 2 minutes...");
        Serial.println("Config new Devices to this Smartmeter work!!!");
    }
}

void loop() {
    checkConnections.checkMqtt(client);
    checkConnections.checkWifi();

    client.loop();
    server.handleClient();
    
    if(devices.size() == 0){
        if (millis() >= configDeviceInterval) {
            ESP.restart();
        }
    }

    Mqtt mqtt;

    if (millis() - lastPublish >= publishInterval) {
        lastPublish = millis();

        for(int i = 0; i < devices.size(); i++){
            devices[i].getRele().setState();

            if(devices[i].getRele().getState() == RELE_STATE_OFF){
                devices[i].getCurrentSensor().setCurrent(0);
                devices[i].getVoltageSensor().setVoltage(0);
                devices[i].setPower(0);
            }

            float current = CurrentSensor::currentRead(devices[i].getCurrentSensor().getPin(), mux);
            devices[i].getCurrentSensor().setCurrent(current);

            float voltage = VoltageSensor::voltageRead(devices[i].getVoltageSensor().getPin(), mux);
            devices[i].getVoltageSensor().setVoltage(voltage);

            devices[i].setPower(CalculatePower::calculate(voltage, current));

            
        }

        mqtt.setTopicSendMeasurements(smartmeterId);

        String topicString = mqtt.getTopicSendMeasurements();
        String messageString = Json::serializationMeasurements(smartmeterId, devices);

        const char* topic = topicString.c_str();
        const char* message = messageString.c_str();

        if(!client.publish(topic, message)){
            Serial.println("error to publish the message: "); 
            Serial.print("Code of Broker state: ");Serial.println(client.state());
        }
    }

}