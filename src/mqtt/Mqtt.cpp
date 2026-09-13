#include "Arduino.h"
#include "mqtt/Mqtt.h"
#include "Preferences.h"
#include "ArduinoJson.h"

void Mqtt::configDevice(String message){
    Preferences preferences;
    JsonDocument json;
    DeserializationError error = deserializeJson(json, message);

    if (error) {
        Serial.print("Falha na desserialização: ");
        Serial.println(error.f_str());
        return;
    }

    String deviceId = json["deviceId"];
    String voltagePin = json["voltagePin"];
    String currentPin = json["currentPin"];
    String relePin = json["relayPin"];

    preferences.begin("devices",false);
    int amountDevices = preferences.getInt("devices_count", 0);
    
    String device_ = "device_";

    String _id = "_id";
    String deviceIdName = device_+amountDevices+_id;
    const char* deviceIdNameChar = deviceIdName.c_str();
    preferences.putString(deviceIdNameChar, deviceId);

    String _voltage_pin = "_v_pin";
    String voltagePinName = device_+amountDevices+_voltage_pin;
    const char* voltagePinNameChar = voltagePinName.c_str();
    preferences.putString(voltagePinNameChar, voltagePin);

    String _current_pin = "_c_pin";
    String currentPinName = device_+amountDevices+_current_pin;
    const char* currentPinNameChar = currentPinName.c_str();
    preferences.putString(currentPinNameChar, currentPin);

    String _relay_pin = "_r_pin";
    String relePinName = device_+amountDevices+_relay_pin;
    const char* relePinNameChar = relePinName.c_str();
    preferences.putString(relePinNameChar, relePin);

    preferences.putInt("devices_count", amountDevices+1);
    preferences.end();


    Serial.println("New Device added");
    Serial.println("Esp go restart in 10s");
    delay(10000);

    ESP.restart();
}

void Mqtt::configSmartmeter(String message){
    Preferences preferences;
    JsonDocument json;
    deserializeJson(json,message);

    String SmartmeterId = json["smartmeterId"];

    preferences.begin("smartmeter",false);
    preferences.putString("smartmeter_Id", SmartmeterId);
    preferences.end();
}

void Mqtt::setTopicSendMeasurements(String smartmeterId){
    this->topicSendMeasurements = "smartmeter/"+smartmeterId+"/measurements";
}

void Mqtt::setTopicConfigDevice(String smartmeterId){
    this->topicConfigDevice = "smartmeter/"+smartmeterId+"/measurements";
}
