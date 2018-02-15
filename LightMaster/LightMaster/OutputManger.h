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
	 COutputManger();
	 ~COutputManger();	


	void AnaloglWrite(int pin,int value);
	void Wait(int ticks);
	void Log(char *message);
	void Log(char * title, char * message);
	void Log(char * title, int message);
};

//extern COutputManger OutputManger;

#endif

