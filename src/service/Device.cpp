#include "model/Device.h"
#include <vector>
#include "Preferences.h"

Device::Device(String id, CurrentSensor currentSensor, Relay relay, VoltageSensor voltageSensor)
    : id(id), currentSensor(currentSensor), relay(relay), voltageSensor(voltageSensor)
{
}

Device::Device(String id, CurrentSensor currentSensor, Relay relay, VoltageSensor voltageSensor, float power)
    : id(id), currentSensor(currentSensor), relay(relay), voltageSensor(voltageSensor), power(power)
{
}

std::vector<Device> Device::getListDevices(){
    Preferences preferences;

    preferences.begin("devices", false);
    int amountDevices = preferences.getInt("devices_count", 0);

    std::vector<Device> devices;

    if(amountDevices == 0){
        preferences.end();
        return devices;
    }
    
    String device_ = "device_";
    String _id = "_id";
    String _voltage_pin = "_v_pin";
    String _current_pin = "_c_pin";
    String _relay_pin = "_r_pin";

    for(int i = 0; i < amountDevices; i++){
        String deviceIdName = device_+i+_id;
        const char* deviceIdNameChar = deviceIdName.c_str();
        String deviceId = preferences.getString(deviceIdNameChar, "0");

        String voltagePinName = device_+i+_voltage_pin;
        const char* voltagePinNameChar = voltagePinName.c_str();
        int voltagePin = preferences.getString(voltagePinNameChar, "0").toInt();

        String currentPinName = device_+i+_current_pin;
        const char* currentPinNameChar = currentPinName.c_str();
        int currentPin = preferences.getString(currentPinNameChar, "0").toInt();

        String relePinName = device_+i+_relay_pin;
        const char* relePinNameChar = relePinName.c_str();
        int relePin = preferences.getString(relePinNameChar, "0").toInt();

        
        devices.push_back(Device(deviceId, CurrentSensor(currentPin) , Relay(relePin), VoltageSensor(voltagePin)));
    }
    preferences.end();
    return devices;
}