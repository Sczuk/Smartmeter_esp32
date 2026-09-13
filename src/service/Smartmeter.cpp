#include "model/Smartmeter.h"
#include "model/Device.h"
#include "Preferences.h"

Smartmeter::Smartmeter(String id, Device* devices){
    this->id = id;
    this->devices = devices;
}

String Smartmeter::getId(){
    Preferences preferences;
    preferences.begin("smartmeter",false);
    String smartmeterId = preferences.getString("smartmeter_Id", "0");
    preferences.end();

    if(smartmeterId == "0"){
        Serial.println("Smartmeter not configured"); 
        return "";
    }
    return smartmeterId;
}