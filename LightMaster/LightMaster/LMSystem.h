// LMSystem.h

#include "ActionManager.h"
#include "Selector.h"

#ifndef _LMSYSTEM_h
#define _LMSYSTEM_h




// LM_System.h
#ifndef PRGBTN
#define PRGBTN 2
#define COLRBTN 6
#endif

#define PINCNT 20

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
/*#else
	#include "WProgram.h"*/
#endif


#endif

class LMSystem
{
	 
public:
	LMSystem();	
	~LMSystem();
	void DoWork();
	void RunProgram(int i);
	void TurnOffPreviousPin();
 

private:

	Selector* m_selector;

	ActionManager* m_ActionManager;

	// Variables will change:
	int ledState = LOW;         // the current state of the output pin
	int buttonState;             // the current reading from the input pin
	int lastButtonState = LOW;   // the previous reading from the input pin
	int lastcolorBtn = LOW;
	
		
	int previouspin = 0;

	// the following variables are unsigned longs because the time, measured in
	// milliseconds, will quickly become a bigger number than can be stored in an int.
	unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
	unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
											 // the PWM pin the LED is attached to
	int brightness = 0;    // how bright the LED is
	int fadeAmount = 1;    // how many points to fade the LED by
		 
	void DigitalWrite(int pins[], int value);
	bool IsBtnPressed(int btn);

	//two dimmentional array holding the led pins and their respective brightness value
	int m_pinBuffer[PINCNT][2];  //m_pinBuffer[Color][brightness]
	
};

