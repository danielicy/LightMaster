

//http://tronixstuff.com/2013/10/21/tutorial-arduino-tlc5940-led-driver-ic/
//https://code.google.com/archive/p/tlc5940arduino/

#include <Tlc5940.h>
#include <tlc_animations.h>
#include <tlc_config.h>
#include <tlc_fades.h>
#include <tlc_progmem_utils.h>
#include <tlc_servos.h>
#include <tlc_shifts.h>
 
#include "Tlc5940.h"
void setup()
{
  Tlc.init(0); // initialise TLC5940 and set all channels off
}

void loop()
{
  for (int i = 0; i < 16; i++)
  {
    Tlc.set(i, 1023);
  }
  Tlc.update();
  delay(1000);
  for (int i = 0; i < 16; i++)
  {
    Tlc.set(i, 2046);
  }
  Tlc.update();
  delay(1000);
  for (int i = 0; i < 16; i++)
  {
    Tlc.set(i, 3069);
  }
  Tlc.update();
  delay(1000);
  for (int i = 0; i < 16; i++)
  {
    Tlc.set(i, 4095);
  }
  Tlc.update();
  delay(1000);
}

