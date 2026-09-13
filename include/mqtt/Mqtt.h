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

        void setTopicSendMeasurements(String smartmeterId);
        void setTopicConfigDevice(String smartmeterId);

        String getTopicSendMeasurements() { return topicSendMeasurements; }
        String getTopicConfigSmartmeter()  { return topicConfigSmartmeter; }
        String getTopicConfigDevice()  { return topicConfigDevice; }

};

