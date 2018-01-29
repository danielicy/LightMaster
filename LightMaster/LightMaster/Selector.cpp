
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

Selector::Selector(  ActionManager* actionManager , LampsManager* lampsManager)
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
#if defined(ARDUINO) && ARDUINO >= 100
	Serial.println("color index changed");
	Serial.print(m_colorIndex);
#endif
	LoadColors();
}


void Selector::SelectProgram()
{
	ChangeSelection(m_progIndex, PROGRAMS_CNT);

	LoadProgram();
}

void Selector::LoadColors()
{
	/*int  size;
	int *col = nullptr;
	int* buffer = new int[20];*/

	
	/*switch (m_colorIndex)
	{
	case 1:
		col = m_colorManager->SetRed(size);
		break;		
	case 2:
		col = m_colorManager->SetOrange(size);
		break;
	case 3:
		col = m_colorManager->SetYellow(size);
		break;
	case 4:
		col = m_colorManager->SetGreen(size);
		break;
	case 5:
		col = m_colorManager->SetRedYellow(size);
		break;
	case 6:
		col = m_colorManager->SetRedGreen(size);
		break;
	case 7:
		col = m_colorManager->SetYellowGreen(size);
		break;

	case 8:
		col = m_colorManager->SetOrangeYellow(size);
		break;
	case 9:
		col = m_colorManager->SetOrangeGreen(size);
		break;
	case 10:
		col = m_colorManager->SetOrangeRed(size);
		break;
	case 11:
		col = m_colorManager->SetOrangeRedYellowGreen(size);
		break;
	case 12:
		col = m_colorManager->SetRedYellowGreen(size);
	default:
		break;
	}
	Serial.println(*col);*/
	
	//memcpy(buffer, col, size * sizeof(int));

	/*Serial.print("col: ");
	Serial.print(col[0]);
	Serial.print("buff: ");
	Serial.println(buffer[0]);*/


#if defined(ARDUINO) && ARDUINO >= 100
	Serial.print(m_colorIndex);
#endif


	m_lampsManager->SetLamps(m_colorIndex);
	//free( buffer);
	
}



void Selector::LoadProgram()
{
	m_actionManager->LoadAction(m_progIndex);
}


 