#pragma once

#define RELE_STATE_OFF "OFFLINE"
#define RELE_STATE_ON "ONLINE"

class Rele{

    private:
        int pin;
        String state;

    public:
        Rele() = default;
        Rele(int pin);
        void turnOnRele();
        void turnOffRele();
        void setState();

        String getState(){ return state; }
        int getPin() { return pin; }
        
};