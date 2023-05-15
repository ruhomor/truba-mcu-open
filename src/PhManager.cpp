#include <math.h>
#include <Arduino.h>

#include "defines.h"
#include "PhManager.h"

#ifdef ARDUINO_AVR_ATmega328PB
    #include "IskraNanoConfig.h"
#else
    #include "Esp8266Config.h"
#endif

Ph::Ph(uint8_t port)
    :_port(port)
{
    pinMode(_port, INPUT);
}


float Ph::GetValue(int measureCount) const
{
    int analogSumValue = 0;
    for(int i = 0; i < measureCount; ++i)
        analogSumValue += analogRead(_port);
    delay(30);

    constexpr float calibrationFactor = 34.4;
    float voltageSensor = (analogSumValue / measureCount) * OPERATING_VOLTAGE / 1023;
    float pHSensor = calibrationFactor - 22.4015 * log(voltageSensor + ZERO_SHIFT);

    return pHSensor;
}