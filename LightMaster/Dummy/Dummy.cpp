// Dummy.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include <vector>
#include <conio.h>

#include "../LightMaster/LMSystem.h"

 

LMSystem* p_lmSystem;

 

#include <conio.h>

using namespace std;

// Get Input
bool getInput(char *c)
{
	if (_kbhit())
	{
		*c = _getch();
		return true; // Key Was Hit
	}
	return false; // No keys were pressed
}

void ResetKey(char *k)
{
	*k = 32;
}


int main()
{
	p_lmSystem = new LMSystem();

	cout << "Press press c to change color" << endl;
	cout << "p to change program" << endl;
	cout << "or x to exit" << endl;


	char key = ' ';

	while (key != 'q')
	{
		while (!getInput(&key))
		{
			// Update your timer here
			p_lmSystem->DoWork(key);
			ResetKey(&key);
		}

		// Update Program Logic Here
		cout << "You Pressed: " << key << endl;
	}

	cout << "You Pressed q, End Of Program" << endl;
	return 0;




	/*while (1)
	{
		unsigned char x = _getch();
		if ('x' != x)
		{ 
			p_lmSystem->DoWork(x);
		}
		printf("key = %02x\n", x);
		if (x == 4) break;
	}*/
	return 0;
}

