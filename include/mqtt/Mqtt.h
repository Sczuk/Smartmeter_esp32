#pragma once

#include "Arduino.h"

class Mqtt{

    private:
        String topicConfigSmartmeter = "smartmeter/config/smartmeter";
        String topicConfigDevice; //    smartmeter/{smartmeterid}/config/device
        String topicSendMeasurements;// smartmeter/{smartmeterId}/measurements
        String topicCommandRelay;//     smartmeter/{smartmeterId}/device/command

    public:
        Mqtt() = default;
        void configSmartmeter(String message);
        void configDevice(String message);
        void turnOnOffRelay(String message);

        String getTopicCommandRelay();
        String getTopicSendMeasurements();
        String getTopicConfigSmartmeter(){ return topicConfigSmartmeter; }
        String getTopicConfigDevice();

};

