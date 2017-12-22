
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
	m_colorManager = new ColorManager();
}

Selector::Selector(ColorManager* colorManager, ActionManager* actionManager , LampsManager* lampsManager)
{
	m_actionManager = actionManager;
	m_colorManager = colorManager;	
	m_lampsManager = lampsManager;
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
	int* buffer = new int[20];

	
	switch (m_colorIndex)
	{
	case 1:
		col = m_colorManager->SetRed(size);
		break;
	case 2:
		col = m_colorManager->SetYellow(size);
		break;
	case 3:
		col = m_colorManager->SetGreen(size);
		break;
	case 4:
		col = m_colorManager->SetRedYellow(size);
		break;
	case 5:
		col = m_colorManager->SetRedGreen(size);
		break;
	case 6:
		col = m_colorManager->SetYellowGreen(size);
		break;
	case 7:
		col = m_colorManager->SetRedYellowGreen(size);
	default:
		break;
	}

	memcpy(buffer, col, size * sizeof(int));
	m_lampsManager->SetLamps(buffer, size);	
	free( buffer);
	
}



void Selector::LoadProgram()
{
	m_actionManager->LoadAction(m_progIndex);
}


 