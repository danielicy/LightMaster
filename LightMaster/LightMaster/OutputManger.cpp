// 
// 
// 

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include <iostream>

#include <windows.h>
#endif

#include "OutputManger.h"

using namespace std;
 
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

void COutputManger::Log(char *message)
{
#if defined(ARDUINO) && ARDUINO >= 100
	Serial.println(message);
	delay(1000);
#else
	cout << message << endl;
#endif
}
 


COutputManger  OutputManger;

