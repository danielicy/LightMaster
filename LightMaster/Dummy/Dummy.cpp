// Dummy.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include <vector>

#include "Selector.h"
#include "ColorManager.h"
#include "ActionManager.h"


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



  

Selector* _selector = new Selector();

ActionManager* m_ActionManager;
ColorManager* m_ColorManager;

int main()
{
	 

	for (int i = 1; i < 7; i++)
	{
		 
	}
    return 0;
}

