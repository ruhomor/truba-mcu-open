#include "TdsManager.h"
#include "TSLManager.h"
#include "I2c.h"
#include "Pomp.h"
#include "PumpManager.h"
#include "PhManager.h"
#include "Sensor.h"
#include "Photodiode.h"

Tds tds(TDS_PORT);
Ph ph(PH_PORT); 
Photodiode Photodiode(PHOTODIODE_PORT);
Pump pump(SALT_PUMP_PWM_PORT, SALT_PUMP_PORT);

void printData()
{
    Serial.print(tds.getName() + ": ");
    Serial.print(tds.GetValue());
    Serial.print(" | ");

    Serial.print(ph.getName() + ": ");
    Serial.print(ph.GetValue());
    Serial.print(" | ");

    Serial.print(Photodiode.getName() + ": ");
    Serial.println(Photodiode.GetValue());
}

void setup()
{
  Serial.begin(BAUDRATE);
}

void loop() {

  pump.SetSpeed(165);
  // printData();
  delay(1000);
}