#pragma once

#include "PumpManager.h"
#include "defines.h"
#include "PID.h"
#include "Sensor.h"

#ifdef ARDUINO_AVR_ATmega328PB
    #include "IskraNanoConfig.h"
#else
    #include "Esp8266Config.h"
#endif

class Tds : public Sensor
{
public:
    explicit Tds(uint8_t port);

    const String getName() const noexcept { return "Tds"; };
    float GetValue(int measureCount = 1) const; 

private:
    PID _pid = { Pump(SALT_PUMP_PWM_PORT, SALT_PUMP_PORT), Pump(FRESH_PUMP_PWM_PORT, FRESH_PUMP_PORT) };
    
    const uint8_t _port;
};
