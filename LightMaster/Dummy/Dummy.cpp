// Dummy.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include <vector>

#include "Selector.h"
#include "ColorManager.h"
#include "ProgramManager.h"


#define REDPIN  3
#define YELLOWPIN  4
#define GREENPIN  5

#define HIGH 0x1
#define LOW  0x0



int*  pointer ;
int *y =0;
int test;


int m_pinBuffer[20][2];

void ChangeSelection(int & index, int param,int * p1)
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





int*  SetRed()
{
	int color[] = { REDPIN };
	return color;
}

int* SetYellow()
{
	int color[] = { YELLOWPIN };
	return color;
}

int*  SetGreen()
{
	int color[] = { GREENPIN };
	return color;
}

int*  SetRedYellow()
{
	int color[] = { REDPIN, YELLOWPIN };
	return color;
}

int*  SetRedGreen()
{
	int color[] = { REDPIN, GREENPIN };
	return color;
}

int*  SetRedYellowGreen()
{
	int color[] = { REDPIN, YELLOWPIN   , GREENPIN };
	return color;
}


void SelectColors(int val)
{

	memset(m_pinBuffer, 0, sizeof(m_pinBuffer));
	//resets buffer
	/*for (int i = 0; i < sizeof(m_pinBuffer); i++)
	{
		m_pinBuffer[i][0] = NULL;
		m_pinBuffer[i][1] = NULL;
	}*/

	int *col = nullptr;
	switch (val)
	{
	case 1:
		col = SetRed();
		break;
	case 2:
		col = SetYellow();
		break;
	case 3:
		col = SetGreen();
		break;
	case 4:
		col = SetRedYellow();
		break;
	case 5:
		col = SetRedGreen();
		break;
	case 6:
		col = SetRedYellowGreen();
		break;

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

Selector* _selector = new Selector();

ProgramManager* m_ProgramManager;
 
int main()
{
	//m_lightMasterSystem = new LMSystem();

	/*while (true)
	{
		ChangeSelection(test, 10,y);
		 
		
	}*/
	//int m_pinBuffer[10][2];
	//int buff[10];

	for (int i = 1; i < 7; i++)
	{
		//ArrayParser(i);
		SelectColors(i);
		//Selct2(i);
	}
    return 0;
}

