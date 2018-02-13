
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#include <stdlib.h>
#endif

 
#include <stdio.h>
#include <string.h>
//#include "stdafx.h"
//#include <iostream>
//using namespace std;

#define HIGH 0x1
#define LOW  0x0

#include "ColorManager.h"
#include "LampsManager.h"
#include "Selector.h"
#include "ActionManager.h"





Selector::Selector()
{
	//m_colorManager = new ColorManager();
}

Selector::Selector(ActionManager* actionManager , LampsManager* lampsManager)
{
	m_actionManager = actionManager;
	
	m_lampsManager = lampsManager;
	m_colorIndex = 0;
	m_progIndex = 0;
}

Selector::~Selector()
{
}


void Selector::ChangeSelection(int & index, int param)
{
	Serial.print("--------------------");
	Serial.print("--------------------");
	 
	if (index < param)
	{
		index++;
	}
	else
	{
		index = 1;
	}
	
}
  

//loads selected color in buffer
void Selector::SelectColors()
{
	ChangeSelection(m_colorIndex, COLORS_CNT);
		
	//TO DO Reset Lamps
#if defined(ARDUINO) && ARDUINO >= 100
	Serial.println("color index changed");
	Serial.print(m_colorIndex);
#endif
	m_lampsManager->SetLamps(m_colorIndex);
	 
}


void Selector::SelectProgram()
{
	ChangeSelection(m_progIndex, PROGRAMS_CNT);


#if defined(ARDUINO) && ARDUINO >= 100
	
	Serial.print("Loading Program: #");
	Serial.print(m_progIndex);
	delay(3500);
#endif
	m_actionManager->LoadAction(m_progIndex);
}

 

 
 