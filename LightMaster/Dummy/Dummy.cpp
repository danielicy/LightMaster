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



template<size_t N>
int Count(int(&arr)[N])
{
		size_t count = N; 

		return N;
}



void Runner(int leds[],int length)
{
		for (int runner = 0; runner < length; runner++)
		{
				if (runner > 0)
				{
						//turn off
				}
				//turn on

		} 
}


int main()
{
		int ledarray[] = { 1,2,3,4,5,6 };

		
		Runner(ledarray, Count(ledarray));

	

	
	/*p_lmSystem = new LMSystem();

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

	cout << "You Pressed q, End Of Program" << endl;*/
	return 0;

}

