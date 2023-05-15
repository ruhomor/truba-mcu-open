#pragma once

#include <stdint.h>

class Pomp
{
public:
    Pomp(uint8_t port);

    void Execute(uint32_t restTime, uint32_t workTime); // time in seconds

private:
    uint8_t _port;
};