#pragma once

#include "Mux.h"


class VoltageSensor{

    private:
        int pin;
        float voltage;

    public:
        VoltageSensor() = default;
        VoltageSensor(int pin);
        static float voltageRead(int pin, admux::Mux& mux);

        void setVoltage(float newVoltage){
            voltage = newVoltage;
        }

        float getVoltage() { return voltage; }
        int getPin() { return pin; }
        
};