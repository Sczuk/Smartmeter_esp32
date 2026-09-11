#pragma once

#include "Mux.h"

class CurrentSensor{

    private:
        int pin;
        float current;
        
    public:
        CurrentSensor() = default;
        CurrentSensor(int pin);
        static float currentRead(int pin, admux::Mux& mux);

        void setCurrent(float newCurrent) {
            current = newCurrent;
        }

        float getCurrent() { return current; }
        int getPin() { return pin; }
};