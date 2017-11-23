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
#define PRGCNT 3

#endif
#ifndef Selector_h
#define Selector_h

#include "Arduino.h"

class Selector
{
public:
	Selector(int pin);
	Selector();
	~Selector();
	void Select();
	void RunProgram();
	
private:
	void TurnOffPreviousPin();
	void Fade(int pin);
	void Fade(int pins[]);
	void DisolveTwo(int pin1, int pin2);
	void DisolveThree(int pin1, int pin2, int pin3);
	

	int m_prgidx = 0;
	int brightness = 0;    // how bright the LED is
	
	//two dimmentional array holding the led pins and their respective brightness value
	int pinArray[PINCNT][2];
	int fadeAmount = 5;    // how many points to fade the LED by	 
	int previouspin = 0;
};

#endif

