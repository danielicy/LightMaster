// Selector.h

#ifndef _SELECTOR_h
#define _SELECTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
//#include "WProgram.h"
#endif


#define PROGRAMS_CNT 3

#endif
#ifndef Selector_h
#define Selector_h

#include "Arduino.h"
#include "ColorManager.h"



class Selector
{
public:	
	Selector();
	~Selector();
	void ChangeSelection(int &index, int param);
	void SelectColors();
	
	
private:
	
	void TurnOffPreviousPin();
	
	

	int m_colorIndex = 0; //the currrent color combination
	
	int brightness = 0;    // how bright the LED is
	
	//two dimmentional array holding the led pins and their respective brightness value
	int m_pinBuffer[20][2];  //m_pinBuffer[Color][brightness]

	int fadeAmount = 5;    // how many points to fade the LED by	 
	int previouspin = 0;
	ColorManager* m_colorManager;
};

#endif

