// Dummy.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Dummy.h"


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
	int color[] = {  REDPIN, YELLOWPIN   , GREENPIN  };
	return color;
}

void SelectColors(int value)
{
	int *o = nullptr;

	  

	switch (value)
	{
	case 1:
		o = SetRed();
		break;
	case 2:
		
		break;
	case 3:
		//m_pinBuffer = { GREENPIN };
		break;
	case 4:
		//pow[1][2] = { REDPIN , YELLOWPIN };
		break;
	case 5:
	//	*y = { REDPIN , GREENPIN };
		break;
	case 6:
		
		 
		break;
		
	default:
		break;
	}
	int i = 0;
	
	while (o[i] >=0)
	{
		
		m_pinBuffer[i][0] = o[i];
		m_pinBuffer[i][1] = LOW;
		
		i++;
	}
	
}



void ArrayParser(int val)
{
	
	
	//resets buffer
	/*for (int i = 0; i < sizeof(m_pinBuffer); i++)
	{
		m_pinBuffer[i][0] = NULL;
		m_pinBuffer[i][1] = NULL;
	}

	int *col = nullptr;


	switch (val)
	{
	case 1:
		col = new int[1]{ REDPIN };
		break;
	case 2:
		col = new int[1]{ YELLOWPIN };
		break;
	case 3:
		col = new int[1]{ GREENPIN };
		break;
	case 4:
		col = new int[2]{ REDPIN , YELLOWPIN };
		break;
	case 5:
		col = new int[2]{ REDPIN , GREENPIN };
		break;
	case 6:
		col = new int[3]{ REDPIN , YELLOWPIN , GREENPIN };
		break;

	default:
		break;
	}
	
	for (int i = 0; i < sizeof(col); i++)
	{
		m_pinBuffer[i][0] = col[i];
		m_pinBuffer[i][1] = LOW;
	}
	col++;*/

}


void Selct2(int val)
{
	int *col;
	int *m_pinBuffer = nullptr;

	switch (val)
	{
	case 1:
		col = new int[1]{ 1 };
		break;
	case 2:
		col = new int[1]{ 2 };
		break;
	case 3:
		col = new int[1]{ 3 };
		break;
	case 4:
		col = new int[2]{ 1 , 2 };
		break;
	case 5:
		col = new int[2]{ 1 , 3 };
		break;
	case 6:
		col = new int[3]{ 1 , 2 , 3 };
		break;

	default:
		break;
	}

	for (int i = 0; i < sizeof(col); i++)
	{
		
	}

}
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
		SelectColors(1);
		//Selct2(i);
	}
    return 0;
}

