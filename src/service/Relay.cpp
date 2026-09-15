#include "Arduino.h"
#include "model/Relay.h"

Relay::Relay(int pin){
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void Relay::turnOffRelay(){
    digitalWrite(this->pin, LOW);
    this->state = RELAY_STATE_OFF;
}

void Relay::turnOnRelay(){
    digitalWrite(this->pin, HIGH);
    this->state = RELAY_STATE_ON;
}

String Relay::getState(){
    int state = digitalRead(this->pin);
    
    if(state == 1) this->state = RELAY_STATE_ON;
    if(state == 0) this->state = RELAY_STATE_OFF;

    return this->state;
}

void Relay::setState(int state){

    if(state == 1){
        digitalWrite(this->pin, HIGH);
        this->state = RELAY_STATE_ON;
    }

    if(state == 0){
        digitalWrite(this->pin, LOW);
        this->state =  RELAY_STATE_OFF;
    } 

}