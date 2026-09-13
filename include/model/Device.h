#pragma once

#include "Arduino.h"
#include <vector>
#include "model/Rele.h"
#include "model/CurrentSensor.h"
#include "model/VoltageSensor.h"

class Device{

    private:
        String id;
        CurrentSensor currentSensor;
        Rele rele;
        VoltageSensor voltageSensor;
        float power;

    public:
        Device() = default;
        Device(String id, CurrentSensor currentSensor, Rele rele, VoltageSensor voltageSensor);
        Device(String id, CurrentSensor currentSensor, Rele rele, VoltageSensor voltageSensor, float power);
        
        static std::vector<Device> getListDevices(); 

        String getId() { return id; }
        CurrentSensor& getCurrentSensor() { return currentSensor; }
        Rele& getRele() { return rele; }
        VoltageSensor& getVoltageSensor() { return voltageSensor; }
        float getPower(){ return power; }

        void setPower(float newPower){
            power = newPower;
        }
        
};