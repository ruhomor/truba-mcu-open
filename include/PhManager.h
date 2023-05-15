#pragma once

#include <stdint.h>
#include <Arduino.h>

#include "Sensor.h"

class Ph : public Sensor
{
public:
  explicit Ph(uint8_t port);

  const String getName() const noexcept { return "Ph"; };
  float GetValue(int measureCount = 1) const;

private:
  uint8_t _port;
};