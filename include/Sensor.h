#pragma once

#include <stdint.h>
#include <Arduino.h>

class Sensor
{
public:
    virtual const String getName() const noexcept = 0;
    virtual float GetValue(int measureCount = 1) const = 0;

    virtual ~Sensor() {};

private:
    uint8_t _port;
};