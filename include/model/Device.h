#pragma once

#include "Arduino.h"
#include <vector>
#include "model/Relay.h"
#include "model/CurrentSensor.h"
#include "model/VoltageSensor.h"

class Device{

    private:
        String id;
        CurrentSensor currentSensor;
        Relay relay;
        VoltageSensor voltageSensor;
        float power;

    public:
        Device() = default;
        Device(String id, CurrentSensor currentSensor, Relay relay, VoltageSensor voltageSensor);
        Device(String id, CurrentSensor currentSensor, Relay relay, VoltageSensor voltageSensor, float power);
        
        static std::vector<Device> getListDevices(); 

        String getId() { return id; }
        CurrentSensor& getCurrentSensor() { return currentSensor; }
        Relay& getRelay() { return relay; }
        VoltageSensor& getVoltageSensor() { return voltageSensor; }
        float getPower(){ return power; }

        void setPower(float newPower){
            power = newPower;
        }
        
};