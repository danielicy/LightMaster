// 
// 
// 

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


COutputManger  OutputManger;

