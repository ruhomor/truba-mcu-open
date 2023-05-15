#include "PID.h"

#include <Arduino.h>

void PID::PIDSetup(float coeff)
{
    _coeff = coeff;
}

void PID::PIDLoop(float value, float target, float eps)
{
    (value > target - eps && value < target + eps) ? 
        _derive = 0 : _derive = value - target;

    float speed = _coeff * _derive;
    if (speed > 0)
    {
        _saltPump.SetSpeed(0);
        _freshPump.SetSpeed(speed);
    }
    else
    {
        _saltPump.SetSpeed(speed);
        _freshPump.SetSpeed(0);
    }

    Serial.print("speed = ");
    Serial.print(speed);
    Serial.print(" Tds = ");
    Serial.println(value);
}