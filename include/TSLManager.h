#pragma once

#include <Adafruit_TSL2591.h>
#include <SPI.h>
#include "Sensor.h"

class TSL : public Sensor
{
public:
    explicit TSL(size_t id);

    const String getName() const noexcept { return "TSL"; };

    float GetValue(int measureCount = 1) const {};

    bool Init();
    bool Begin();

    void DisplaySensorDetails();
    void ConfigureSensor(tsl2591Gain_t gain, 
        tsl2591IntegrationTime_t integrationTime);

    void SimpleRead(uint8_t mode);
    void AdvancedRead();
    void UnifiedSensorAPIRead();

private:
    void messageOk() noexcept;
    void messageError() noexcept;

private:
    Adafruit_TSL2591 _tsl;
};




