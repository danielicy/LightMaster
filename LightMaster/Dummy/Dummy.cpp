// Dummy.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include <vector>
#include "DummySystem.h"


DummySystem* p_dummySystem;


 

#include <conio.h>

using namespace std;

int main()
{
	p_dummySystem = new DummySystem();

	cout << "Press any key! CTRL-D to end" << endl;
	while (1)
	{
		unsigned char x = _getch();
		if ('x' != x)
		{ 
			p_dummySystem->DoWork(x);
		}
		printf("key = %02x\n", x);
		if (x == 4) break;
	}
	return 0;
}

