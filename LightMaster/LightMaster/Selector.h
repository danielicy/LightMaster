// Selector.h

#ifndef _SELECTOR_h
#define _SELECTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifndef REDPIN
#define REDPIN  3
#define YELLOWPIN  4
#define GREENPIN  5
#endif

#define PINCNT 20
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
	void RunProgram(int i);
	
private:
	
	void TurnOffPreviousPin();
	void Fade(int pin);
	void Fade(int pins[]);
	void DisolveTwo(int pin1, int pin2);
	void DisolveThree(int pin1, int pin2, int pin3);
	

	int m_colorIndex = 0; //the currrent color combination
	
	int brightness = 0;    // how bright the LED is
	
	//two dimmentional array holding the led pins and their respective brightness value
	int m_pinBuffer[PINCNT][2];  //m_pinBuffer[Color][brightness]
	int fadeAmount = 5;    // how many points to fade the LED by	 
	int previouspin = 0;
	ColorManager* m_colorManager;
};

#endif

