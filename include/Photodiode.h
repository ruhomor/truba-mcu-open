#pragma once

#include <stdint.h>
#include <Arduino.h>

#include "Sensor.h"

class Photodiode : public Sensor
{
public:
    explicit Photodiode(uint8_t port);

    const String getName() const noexcept { return "Photodiode"; };
    float GetValue(int measureCount = 1) const;

private:
    uint8_t _port;
};