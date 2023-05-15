#include "Pomp.h"
#include <Arduino.h>

Pomp::Pomp(uint8_t port) : 
    _port(port)
{
    pinMode(port, OUTPUT);
}

void Pomp::Execute(uint32_t restTime, uint32_t workTime)
{
    digitalWrite(2, LOW);
    delay(workTime * 1000);
    digitalWrite(2, HIGH);
    delay(restTime * 1000);
}