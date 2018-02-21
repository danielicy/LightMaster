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
 
COutputManger::COutputManger()
{

}
COutputManger::~COutputManger()
{
}



void COutputManger::AnaloglWrite(int pin, int value)
{
#if defined(ARDUINO) && ARDUINO >= 100
	Serial.print("writing: ");
	Serial.print(pin);
	Serial.print('#');
	Serial.println(value);

	analogWrite(pin, value);

	Serial.print("wrote lamp: ");
	Serial.print(pin);
	Serial.print("# Val: ");
	Serial.println(value);
	
	//delay(1000);
#else

#endif
}

void COutputManger::Wait(int ticks)
{
#if defined(ARDUINO) && ARDUINO >= 100
	delay(ticks);

#else
	Sleep(ticks/1000);
#endif
}

void COutputManger::Log(char *message)
{
#if defined(ARDUINO) && ARDUINO >= 100
	Serial.println(message);
//	delay(1000);
#else
	cout << message << endl;
#endif
}
 
void COutputManger::Log(char *title,char *message)
{
#if defined(ARDUINO) && ARDUINO >= 100
	Serial.print(title);
	Serial.println(message);
	//	delay(1000);
#else
	cout << message << endl;
#endif
}

void COutputManger::Log(char *title, int message)
{
#if defined(ARDUINO) && ARDUINO >= 100
	Serial.print(title);
	Serial.println(message);
		//delay(1000);
#else
	cout << title << message  << endl;
	//cout << message << endl;
	Sleep(1000);
#endif
}


COutputManger  OutputManger;

