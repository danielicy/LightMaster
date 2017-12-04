// Selector.h
#pragma once

#ifndef _SELECTOR_h
#define _SELECTOR_h



#define PROGRAMS_CNT 3

#endif
#ifndef Selector_h
#define Selector_h


#include "ColorManager.h"
#include "ActionManager.h"


class Selector
{
public:	
	Selector();
	~Selector();
	void ChangeSelection(int &index, int param);
	void SelectColors();
	void SelectProgram();
	
	
private:
	void LoadColors();
	void LoadProgram();

	int m_colorIndex = 0; //the currrent color combination
	int m_progIndex = 0;        //the current program selecte


	int brightness = 0;    // how bright the LED is
	
	//two dimmentional array holding the led pins and their respective brightness value
	int m_pinBuffer[20][2];  //m_pinBuffer[Color][brightness]

	int fadeAmount = 5;    // how many points to fade the LED by	 
	
	ColorManager* m_colorManager;
	ActionManager* m_actionManager;
};

#endif

