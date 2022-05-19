#include <Arduino.h>
#pragma once

enum batteryType {
    undef_type,
    li_ion,
    li_po,
    lead_acid,
    nimh,

};

enum states {
    undef_state,
    charging,
    discharging,
    disconnected,
    stabilizing,
    finished,
    error,
    idle,
};

enum programs {
    undef_prog,
    none,
    charge,
    discharge,
    full_cycle,
    storage,
};

class Battery {
    public:
        Battery(batteryType type,float rLoad);
        bool setMinimumVoltage(float voltage);
        bool setMaximumVoltage(float voltage);
        bool setMinCritVoltage(float voltage);
        bool setMaxCritVoltage(float voltage);
        bool setStorageVoltage(float voltage);
        bool setChargeCurrent(float current);
        bool setDischargeCurrent(float current);
        bool setResistiveLoad(float rLoad);
        bool setProgram(programs program);

        bool setAdcBits(uint8_t bits);
        bool setSupplyVoltage(float vSupply);

        void receiveADC(uint16_t value);

        float getVoltage();
        float getCurrent();
        float getIntResistance();
        float getCapacity();

        states getState();
        batteryType getBatteryType();
        programs getPrograms();

        uint8_t getChargeFetDuty();
        uint8_t getDischargeFetDuty();

    private:

        struct config {
            float vMin,vMax,vMinCritical,vMaxCritical,vStorage,iCharge,iDischage,rLoad,vSupply;
            uint8_t bits;
        } cfg;

        struct parameters {
            float vBat,iBat,rBat,capacity;
        } para;

        uint32_t prev_time;

        batteryType type = undef_type;
        programs prog = undef_prog;
        states state = undef_state;
};