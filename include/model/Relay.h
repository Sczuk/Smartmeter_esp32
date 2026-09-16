#pragma once

#define RELAY_STATE_OFF "OFFLINE"
#define RELAY_STATE_ON "ONLINE"

class Relay{

    private:
        int pin;
        String state;

    public:
        Relay() = default;
        Relay(int pin);
        void turnOnRelay();
        void turnOffRelay();
        static void turnOnAllRelays();

        String getState();
        void setState(int state);
        int getPin() { return pin; }
        
};