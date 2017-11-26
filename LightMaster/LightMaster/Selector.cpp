// 
// 
// 
//#include<stdio.h>

 
//#include <stdio.h>
//#include "stdafx.h"
//#include <iostream>
//using namespace std;

#include "ColorManager.h"
#include "Selector.h"




Selector::Selector()
{
	m_colorManager = new ColorManager();
}

Selector::~Selector()
{
}

void Selector::ChangeSelection(int & index, int param)
{
	TurnOffPreviousPin();

	if (index < param)
	{
		index++;
	}
	else
	{
		index = 1;
	}
	Serial.println("Selection changed:" + index);

	delay(1000);
}
  

//loads selected color in buffer
void Selector::SelectColors()
{
	ChangeSelection(m_colorIndex, PROGRAMS_CNT);
		
	//resets buffer
	memset(m_pinBuffer, 0, sizeof(m_pinBuffer));

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


void Selector::TurnOffPreviousPin()
{
	//turns off previouspin
	analogWrite(previouspin, LOW);
}



 