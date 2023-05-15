#include "PumpManager.h"
#include <Arduino.h>

Pump::Pump(uint8_t PWMPort, uint8_t port) :
    _PWMPort(PWMPort),
    _port(port)
{
    pinMode(_PWMPort, OUTPUT);
	pinMode(_port, OUTPUT);
	SetSpeed(0);
}

void Pump::SetSpeed(float val)
{
	if (val > 0)
		val += 90;
	if (val > 255)
		val = 255;

	analogWrite(_PWMPort, val);
}

