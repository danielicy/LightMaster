// Dummy.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include <vector>
#include "LMSystem.h"

#define REDPIN  3
#define YELLOWPIN  4
#define GREENPIN  5

#define HIGH 0x1
#define LOW  0x0



int*  pointer ;
int *y =0;
int test;


int m_pinBuffer[20][2];



LMSystem* p_lmSystem;


int main()
{
	p_lmSystem = new LMSystem();

	for (int i = 1; i < 7; i++)
	{
		p_lmSystem->DoWork();
	}
    return 0;
}

