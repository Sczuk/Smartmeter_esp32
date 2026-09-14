#include "utils/Json.h"
#include <vector>
#include "model/Device.h"
#include "ArduinoJson.h"


String Json::serializationMeasurements(String smartmeterId, std::vector<Device> devices){
    JsonDocument json;
    json.clear();

    json["smartmeterId"] = smartmeterId;
    JsonArray listDevices = json["devices"].to<JsonArray>();

    for(size_t i = 0; i < devices.size(); i++){
        JsonObject deviceJson = listDevices.add<JsonObject>();
        deviceJson["deviceId"] = devices[i].getId();
        deviceJson["current_a"] = devices[i].getCurrentSensor().getCurrent();
        deviceJson["voltage_v"] = devices[i].getVoltageSensor().getVoltage();
        deviceJson["releState"] = devices[i].getRele().getState();
        deviceJson["power_w"] = devices[i].getPower();
    }

    String output;
    serializeJson(json, output);
    return output;
}
