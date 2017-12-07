// Dummy.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include <vector>

#include "../LightMaster/LMSystem.h"

 

LMSystem* p_lmSystem;

 

#include <conio.h>

using namespace std;

int main()
{
	p_lmSystem = new LMSystem();

	cout << "Press press c to change color" << endl;
	cout << "p to change program" << endl;
	cout << "or x to exit" << endl;
	while (1)
	{
		unsigned char x = _getch();
		if ('x' != x)
		{ 
			p_lmSystem->DoWork(x);
		}
		printf("key = %02x\n", x);
		if (x == 4) break;
	}
	return 0;
}

