#include "Arduino.h"
#include "model/Rele.h"

Rele::Rele(int pin){
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void Rele::turnOffRele(){
    digitalWrite(this->pin, LOW);
    this->state = RELE_STATE_OFF;
}

void Rele::turnOnRele(){
    digitalWrite(this->pin, HIGH);
    this->state = RELE_STATE_ON;
}

void Rele::setState(){
    int state = digitalRead(this->pin);
    if(state == 1) this->state = RELE_STATE_ON;
    if(state == 0) this->state =  RELE_STATE_OFF;
}