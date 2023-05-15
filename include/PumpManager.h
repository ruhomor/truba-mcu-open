#pragma once

#include <stdint.h>

class Pump
{
public:
    Pump(uint8_t, uint8_t); 

    void SetSpeed(float); // Устанавливает скорость вращения мотора числом [0; 165] (ниже 90 насос не качает, поэтому значения из [90; 255] смещены к нулю)
    
private:
    const uint8_t _PWMPort;
    const uint8_t _port;
};