#include <I2c.h>
#include <Wire.h>
#include <Arduino.h>

void recieveEvent(int amount)
{
    while (Wire.available())
    {
        char c = Wire.read();
        Serial.println(c);
    }
}

void I2CSetup()
{
    Wire.begin(0X8);
    Wire.onReceive(recieveEvent);

    Serial.begin(9600);
}