#pragma once

#include "Device.h"

class Smartmeter{
    
    private:
        String id;
        Device* devices;
    
    public:
        Smartmeter(String id, Device* devices);
        static String getId();

};