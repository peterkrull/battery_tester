#include "battery.h"

Battery::Battery(batteryType type,float rLoad){
    switch ( type ) {
        case li_ion: {
            cfg.vMin = 3.0;
            cfg.vMax = 4.2;
            cfg.vMinCritical = 1.5;
            cfg.vMaxCritical = 4.25;
            cfg.vStorage = 3.7;
            cfg.iCharge = 1;
            cfg.iDischage = 1; 
            cfg.rLoad = rLoad;
        }
        case lead_acid: {

        }


    }
}

// Read battery voltage
void Battery::receiveADC(uint16_t value){
    // Take n-bit adc reading, and calculate voltage level
    para.vBat = value*cfg.vSupply/pow(2.0, cfg.bits);
}

// Return battery information
float Battery::getVoltage(){
    return para.vBat;
}
float Battery::getCurrent(){
    return para.iBat;
}
float Battery::getIntResistance(){
    return para.rBat;
}
float Battery::getCapacity(){
    return para.capacity;
}
states Battery::getState(){
    return state;
}
batteryType Battery::getBatteryType(){
    return type;
}
programs Battery::getPrograms(){
    return prog;
}