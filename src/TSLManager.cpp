#include <TSLManager.h>

TSL::TSL(size_t id) 
{
    _tsl = Adafruit_TSL2591(id);
} 

bool TSL::Init()
{
  Serial.println("Starting Adafruit TSL2591 Test!");
  
  if (_tsl.begin()) 
  {
    messageOk();
    DisplaySensorDetails();
    ConfigureSensor(TSL2591_GAIN_MED, TSL2591_INTEGRATIONTIME_100MS);

    return true;
  } 

  messageError();
  return false;
}

bool TSL::Begin()
{
  if (_tsl.begin()) 
    return true;

  messageError();
  return false;
}

void TSL::DisplaySensorDetails()
{
  sensor_t sensor;
  _tsl.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" lux");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" lux");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" lux");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(1000);
}

void TSL::ConfigureSensor(tsl2591Gain_t gain, 
    tsl2591IntegrationTime_t integrationTime)
{
  // You can change the gain on the fly, to adapt to brighter/dimmer light situations
  _tsl.setGain(gain);      // 25x gain

  // Changing the integration time gives you a longer time over which to sense light
  // longer timelines are slower, but are good in very low light situtations!
  _tsl.setTiming(integrationTime);  // shortest integration time (bright light)
 
  Serial.println("------------------------------------");
  Serial.print  ("Gain:         ");
  switch(gain)
  {
    case TSL2591_GAIN_LOW:
      Serial.println("1x (Low)");
      break;
    case TSL2591_GAIN_MED:
      Serial.println("25x (Medium)");
      break;
    case TSL2591_GAIN_HIGH:
      Serial.println("428x (High)");
      break;
    case TSL2591_GAIN_MAX:
      Serial.println("9876x (Max)");
      break;
  }
  Serial.print  ("Timing:       ");
  Serial.print((_tsl.getTiming() + 1) * 100, DEC); 
  Serial.println(" ms");
  Serial.println("------------------------------------");
  Serial.println("");
}

void TSL::SimpleRead(uint8_t mode)
{
  uint16_t x = _tsl.getLuminosity(mode);

  Serial.print("[ "); Serial.print(millis()); Serial.print(" ms ] ");
  Serial.print("Luminosity: ");
  Serial.println(x, DEC);
}

void TSL::AdvancedRead()
{
  // More advanced data read example. Read 32 bits with top 16 bits IR, bottom 16 bits full spectrum
  // That way you can do whatever math and comparisons you want!
  uint32_t lum = _tsl.getFullLuminosity();
  uint16_t ir, full;
  ir = lum >> 16;
  full = lum & 0xFFFF;
  Serial.print("[ "); Serial.print(millis()); Serial.print(" ms ] ");
  Serial.print("IR: "); Serial.print(ir);  Serial.print("  ");
  Serial.print("Full: "); Serial.print(full); Serial.print("  ");
  Serial.print("Visible: "); Serial.print(full - ir); Serial.print("  ");
  Serial.print("Lux: "); Serial.println(_tsl.calculateLux(full, ir));
}


void TSL::UnifiedSensorAPIRead()
{ 
  sensors_event_t event;
  _tsl.getEvent(&event);
 
  Serial.print("[ "); Serial.print(event.timestamp); Serial.print(" ms ] ");
  if ((event.light == 0) |
      (event.light > 4294966000.0) | 
      (event.light <-4294966000.0))
  {

    Serial.println("Invalid data (adjust gain or timing)");
  }
  else
  {
    Serial.print(event.light); Serial.println(" lux");
  }
}

void TSL::messageOk() noexcept
{
  Serial.println("Found a TSL2591 sensor");
}

void TSL::messageError() noexcept
{
  Serial.println("No sensor found ... check your wiring?");
}



