#include <math.h>
#include <Arduino.h>

#include "TdsManager.h"

Tds::Tds(uint8_t port):
    _port(port)
{
    pinMode(_port, INPUT);
}

float Tds::GetValue(int measureCount) const
{
    int valueSensor = analogRead(_port);
	float voltageSensor = valueSensor * 5 / 1024.0;
	float tdsSensor = (133.42 * pow(voltageSensor, 3) - 255.86 * pow(voltageSensor, 2) + 857.39 * voltageSensor) * 0.5;

    return tdsSensor;
}
