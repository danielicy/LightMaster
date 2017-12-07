// Dummy.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include <vector>
#include "../LightMaster/LMSystem.h"

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

 

#include <conio.h>

using namespace std;

int main()
{
	p_lmSystem = new LMSystem();

	cout << "Press any key! CTRL-D to end" << endl;
	while (1)
	{
		unsigned char x = _getch();
		if ('0' == x)
		{
			printf("Function key!\n");
			x = _getch();

			p_lmSystem->DoWork(x);
		}
		printf("key = %02x\n", x);
		if (x == 4) break;
	}
	return 0;
}

