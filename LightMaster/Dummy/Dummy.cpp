// Dummy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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

int main()
{
	//m_lightMasterSystem = new LMSystem();

	while (true)
	{
		ChangeSelection(test, 10,y);
		
	}
    return 0;
}

