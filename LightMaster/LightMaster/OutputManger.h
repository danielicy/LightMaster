// OutputManger.h
#pragma once

#ifndef _OUTPUTMANGER_h
#define _OUTPUTMANGER_h



#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
    #include "stdint.h"	 
#endif

class COutputManger
{
 protected:


 public:
	void init();
	void DigitalWrite(int pin,int value);
	void Wait(int ticks);
	void Log(char *message);
};

extern COutputManger OutputManger;

#endif

