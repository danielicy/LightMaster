#include "stdafx.h"
 
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
		
	//resets buffer
	memset(m_pinBuffer, 0, sizeof(m_pinBuffer));

	LoadColors();
}


void Selector::SelectProgram()
{
	ChangeSelection(m_progIndex, PROGRAMS_CNT);

	LoadProgram();
}

void Selector::LoadColors()
{
	int *col = nullptr;
	switch (m_colorIndex)
	{
	case 1:
		col = m_colorManager->SetRed();
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

	int i = 0;
	while (col[i] >= 0)
	{

		m_pinBuffer[i][0] = col[i];
		m_pinBuffer[i][1] = LOW;

		i++;
	}
}

void Selector::LoadProgram()
{
	m_actionManager->LoadAction(m_progIndex);
}


 