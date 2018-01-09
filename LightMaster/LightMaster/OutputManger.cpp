// 
// 
// 

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else

#include <windows.h>
#endif

#include "OutputManger.h"


 
void COutputManger::init()
{


}

void COutputManger::DigitalWrite(uint8_t pin, int value)
{
#if defined(ARDUINO) && ARDUINO >= 100
	analogWrite(pin, value);
#else

#endif
}

void COutputManger::Wait(int ticks)
{
#if defined(ARDUINO) && ARDUINO >= 100
	delay(ticks);
#else
	Sleep(ticks * 100);
#endif
}
 


COutputManger  OutputManger;

