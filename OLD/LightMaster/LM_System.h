#include "Arduino.h"

// LM_System.h
#define BUTTONPIN 2
#define REDPIN  3
#define YELLOWPIN  4
#define GREENPIN  5

 
#ifndef _LM_SYSTEM_h
#define _LM_SYSTEM_h
class LMSystem
{
	 
public:
	LMSystem();
	~LMSystem();
	void DoWork();

private:
	// Variables will change:
	int ledState = HIGH;         // the current state of the output pin
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
};
#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


#endif
 
