#pragma once

#include <vector>
#include "model/Device.h"

class Json
{
public:
    static String serializationMeasurements(String smartmeterId, std::vector<Device> devices);
    
};
