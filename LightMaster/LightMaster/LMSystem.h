// LMSystem.h

#ifndef _LMSYSTEM_h
#define _LMSYSTEM_h



// LM_System.h
#ifndef BUTTONPIN
#define BUTTONPIN 2
#endif

#ifndef REDPIN
#define REDPIN  3
#define YELLOWPIN  4
#define GREENPIN  5
#endif



#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class LMSystem
{

public:
	LMSystem();

	
	
	~LMSystem();
	void DoWork();

private:
	// Variables will change:
	int ledState = LOW;         // the current state of the output pin
	int buttonState;             // the current reading from the input pin
	int lastButtonState = LOW;   // the previous reading from the input pin

	int index = 0;

	// the following variables are unsigned longs because the time, measured in
	// milliseconds, will quickly become a bigger number than can be stored in an int.
	unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
	unsigned long debounceDelay = 10;    // the debounce time; increase if the output flickers


										 // the PWM pin the LED is attached to
	int brightness = 0;    // how bright the LED is
	int fadeAmount = 1;    // how many points to fade the LED by

	void SetIndex();
	void DigitalWrite(int pins[], int value);
};

