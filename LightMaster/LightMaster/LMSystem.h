// LMSystem.h
#pragma once


#ifndef _LMSYSTEM_h
#define _LMSYSTEM_h

 
//#define D_0 16
//#define D_1 5 // I2C Bus SCL (clock)
//#define D_2 4 // I2C Bus SDA (data)
//#define D_3 0
//#define D_4 2 // Same as "LED_BUILTIN", but inverted logic
//#define D_5 14 // SPI Bus SCK (clock)
//#define D_6 12 // SPI Bus MISO
//#define D_7 13 // SPI Bus MOSI
//#define D_8 15 // SPI Bus SS (CS)
//#define D_9 3 // RX0 (Serial console)
//#define D_10 1 // TX0 (Serial console)
 

#define D_0 0
#define D_1 1 
#define D_2 4 
#define D_3 5
#define D_4 6 
#define D_5 7 
#define D_6 8 
#define D_7 9 
#define D_8 10 
#define D_9 11 
#define D_10 12 

// LM_System.h
#ifndef PRGBTN
#define PRGBTN 2//D_7
#define COLRBTN 3// D_8
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
#include "OutputManger.h"

class Selector;
class ActionManager;
class ColorManager;
class LampsManager;

class LMSystem
{
	 
public:
	LMSystem();	
	~LMSystem();
	bool IsBtnPressed(int btn);
	void DoWork(char c);
	

private:
	ActionManager* m_ActionManager;
	ColorManager* m_colorManager;
	LampsManager* m_lampsManager;
	COutputManger* m_outputManager;
	Selector* m_selector;
	

		 
	void DigitalWrite(int pins[], int value);
	
	// Variables will change:
	int ledState = LOW;         // the current state of the output pin
	int buttonState;             // the current reading from the input pin
	int lastButtonState = LOW;   // the previous reading from the input pin
	int lastcolorBtn = LOW;
	
};

