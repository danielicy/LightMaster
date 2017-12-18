
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

 
#include <stdio.h>
#include <string.h>
//#include "stdafx.h"
//#include <iostream>
//using namespace std;

#define HIGH 0x1
#define LOW  0x0

#include "ColorManager.h"
#include "Selector.h"
#include "ActionManager.h"





Selector::Selector()
{
	m_colorManager = new ColorManager();
}

Selector::Selector(ColorManager* colorManager, ActionManager* actionManager)
{
	m_colorManager = colorManager;
	m_actionManager = actionManager;
}

Selector::~Selector()
{
}

void Selector::ChangeSelection(int & index, int param)
{
	 
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
	ChangeSelection(m_colorIndex, PROGRAMS_CNT);
		
	//TO DO Reset Lamps
	 

	LoadColors();
}


void Selector::SelectProgram()
{
	ChangeSelection(m_progIndex, PROGRAMS_CNT);

	LoadProgram();
}

void Selector::LoadColors()
{
	int  size;
	int *col = nullptr;
	int i = 0;
	switch (m_colorIndex)
	{
	case 1:
		col = m_colorManager->SetRed(size);
		break;
	case 2:
		col = m_colorManager->SetYellow();
		break;
	case 3:
		col = m_colorManager->SetGreen();
		break;
	case 4:
		col = m_colorManager->SetRedYellow();
		break;
	case 5:
		col = m_colorManager->SetRedGreen();
		break;
	case 6:
		col = m_colorManager->SetYellowGreen();
		break;
	case 7:
		col = m_colorManager->SetRedYellowGreen();
	default:
		break;
	}
	
	while (col[i] >= 0)
	{

			Lamp* lamp = new Lamp();
			lamp->LampName = col[i];
			lamp->State = LOW;
 

		m_actionManager->AddLamp(&lamp);

		i++;
	}
	
}

void Selector::LoadProgram()
{
	m_actionManager->LoadAction(m_progIndex);
}


 