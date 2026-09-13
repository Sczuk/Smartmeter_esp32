#pragma once

#include "Arduino.h"

class CalculatePower{

    public:
        static float calculate(float voltage, float current){
            double power = voltage * current;
            return power;
        }
        
};