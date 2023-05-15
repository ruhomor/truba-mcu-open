#include "Photodiode.h"

Photodiode::Photodiode(uint8_t port) : 
    _port(port)
{
    pinMode(_port, INPUT);
}

float Photodiode::GetValue(int measureCount) const
{
    return analogRead(_port);;
}