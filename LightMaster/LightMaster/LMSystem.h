// LMSystem.h
#pragma once


#ifndef _LMSYSTEM_h
#define _LMSYSTEM_h

 
#define D_0 16
#define D_1 5 // I2C Bus SCL (clock)
#define D_2 4 // I2C Bus SDA (data)
#define D_3 0
#define D_4 2 // Same as "LED_BUILTIN", but inverted logic
#define D_5 14 // SPI Bus SCK (clock)
#define D_6 12 // SPI Bus MISO
#define D_7 13 // SPI Bus MOSI
#define D_8 15 // SPI Bus SS (CS)
#define D_9 3 // RX0 (Serial console)
#define D_10 1 // TX0 (Serial console)
 


// LM_System.h
#ifndef PRGBTN
#define PRGBTN D_7
#define COLRBTN D_8
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
	void DoWork(char c);	
	

private:
	ActionManager* m_ActionManager;
	ColorManager* m_colorManager;
	LampsManager* m_lampsManager;
	COutputManger* m_outputManager;
	Selector* m_selector;
	

		 
	void DigitalWrite(int pins[], int value);
	
		
	
};

