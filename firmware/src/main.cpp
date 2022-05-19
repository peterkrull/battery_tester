#include <Arduino.h>
#include "battery.h"

#define NUM_BATTERIES
#define TYPE_BATTERY li_ion

Battery bat[NUM_BATTERIES] = {Battery(TYPE_BATTERY,4)};

void setup() {

}

void loop() {
    // put your main code here, to run repeatedly:
}