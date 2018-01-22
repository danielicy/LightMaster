// LMSystem.h
#pragma once


#ifndef _LMSYSTEM_h
#define _LMSYSTEM_h

/*
#define D0 16
#define D1 5 // I2C Bus SCL (clock)
#define D2 4 // I2C Bus SDA (data)
#define D3 0
#define D4 2 // Same as "LED_BUILTIN", but inverted logic
#define D5 14 // SPI Bus SCK (clock)
#define D6 12 // SPI Bus MISO
#define D7 13 // SPI Bus MOSI
#define D8 15 // SPI Bus SS (CS)
#define D9 3 // RX0 (Serial console)
#define D10 1 // TX0 (Serial console)
*/


// LM_System.h
#ifndef PRGBTN
#define PRGBTN 12 //D6
#define COLRBTN 13 //D7
#endif

#define PINCNT 20

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
#define LOW 0
#endif


#endif

#include "ActionManager.h"


#include "Selector.h"


#include "ColorManager.h"

#include "LampsManager.h"


#include "Lamp.h"

class Selector;
class ActionManager;
class ColorManager;
class LampsManager;

class LMSystem
{
	 
public:
	LMSystem();	
	~LMSystem();
	void DoWork(char c);	
	void TurnOffPreviousPin(); 

private:
	ActionManager* m_ActionManager;
	ColorManager* m_colorManager;
	LampsManager* m_lampsManager;
	Selector* m_selector;
	
	
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

	 
	
	
};

