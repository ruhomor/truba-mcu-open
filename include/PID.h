#include "PumpManager.h"

struct PID
{
    Pump _saltPump;
    Pump _freshPump;

    PID(Pump pump1, Pump pump2) : _saltPump(pump1),
                                  _freshPump(pump2){};

    float _coeff = 1.0;
    float _derive = 0.0;

    void PIDSetup(float coeff = 1);

    void PIDLoop(float value, float target, float eps);
};