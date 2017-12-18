
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
	int *col = new int[20];
	Lamp* lBuffer = (Lamp*)malloc(sizeof(Lamp)*20);// new Lamp[size];
	Lamp* lamps = lBuffer;// new Lamp[size];


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
	

	for (int i = 0; i < size; i++)
	{
		lamps[i].LampName = col[i];
		lamps[i].State = LOW;
	}

	m_actionManager->AddLamp(&lamps);
	
}

void resize(int size,Lamp arr[]) {
	size_t newSize = size * 2;
	Lamp* newArr = new Lamp[newSize];

	memcpy(newArr, arr, size * sizeof(int));

	size = newSize;
	delete[] arr;
	arr = newArr;
}

void Selector::LoadProgram()
{
	m_actionManager->LoadAction(m_progIndex);
}


 