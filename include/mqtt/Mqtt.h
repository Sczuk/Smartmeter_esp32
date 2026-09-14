#pragma once

#include "Arduino.h"

class Mqtt{

    private:
        String topicConfigSmartmeter = "smartmeter/config/smartmeter";
        String topicConfigDevice; //    smartmeter/{smartmeterid}/config/device
        String topicSendMeasurements;// smartmeter/{smartmeterId}/measurements

    public:
        Mqtt() = default;
        void configSmartmeter(String message);
        void configDevice(String message);

        String getTopicSendMeasurements();
        String getTopicConfigSmartmeter()  { return topicConfigSmartmeter; }
        String getTopicConfigDevice();

};

