// Dummy.cpp : Defines the entry point for the console application.
//


#define REDPIN  3
#define YELLOWPIN  4
#define GREENPIN  5



#include "stdafx.h"
#include <iostream>
#include <vector>

int*  pointer ;
int *y =0;
int test;

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


void SelectColors(int value)
{
	 


	std::vector<int> col;

	switch (value)
	{
	case 1:
		col= { REDPIN };
		break;
	case 2:
		col= { YELLOWPIN };
		break;
	case 3:
		col= { GREENPIN };
		break;
	case 4:
		col= { REDPIN , YELLOWPIN };
		break;
	case 5:
		col= { REDPIN , GREENPIN };
		break;
	case 6:
		col= { REDPIN , YELLOWPIN , GREENPIN };
		break;
		/*case 7:
		m_pinBuffer[0][0] = REDPIN;
		m_pinBuffer[0][1] = LOW;
		break;
		case 8:
		m_pinBuffer[0][0] = REDPIN;
		m_pinBuffer[0][1] = LOW;
		break;
		case 9:
		m_pinBuffer[0][0] = REDPIN;
		m_pinBuffer[0][1] = LOW;
		break;
		case 10:
		m_pinBuffer[0][0] = REDPIN;
		m_pinBuffer[0][1] = LOW;
		break;*/
	default:
		break;
	}

	std::cout << value;
	 
}

int main()
{
	//m_lightMasterSystem = new LMSystem();

	/*while (true)
	{
		ChangeSelection(test, 10,y);
		 
		
	}*/

	for (int i = 0; i < 7; i++)
	{
		SelectColors(i);
	}
    return 0;
}

