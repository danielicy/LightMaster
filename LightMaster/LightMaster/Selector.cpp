// 
// 
// 
//#include<stdio.h>

 
//#include <stdio.h>
//#include "stdafx.h"
//#include <iostream>
//using namespace std;

#include "ColorManager.h"
#include "Selector.h"




Selector::Selector()
{
	m_colorManager = new ColorManager();
}

Selector::~Selector()
{
}

void Selector::ChangeSelection(int & index, int param)
{
	TurnOffPreviousPin();

	if (index < param)
	{
		index++;
	}
	else
	{
		index = 1;
	}
	Serial.println("Selection changed:" + index);

	delay(1000);
}
  




void Selector::SelectColors()
{
	ChangeSelection(m_colorIndex, PROGRAMS_CNT);

	
	//resets buffer
	memset(m_pinBuffer, 0, sizeof(m_pinBuffer));

	int *col = nullptr;
	switch (m_colorIndex)
	{
	case 1:
		col = m_colorManager->SetRed();
		break;
	case 2:
		col = m_colorManager->SetYellow();
		break;
	case 3:
		col = m_colorManager->SetGreen();
		break;
	case 4:
		col = m_colorManager->SetRedYellow();
		break;
	case 5:
		col = m_colorManager->SetRedGreen();
		break;
	case 6:
		col = m_colorManager->SetYellowGreen();
		break;
	case 7:
		col = m_colorManager->SetRedYellowGreen();
	default:		
		break;
	}

	int i = 0;
	while (col[i] >= 0)
	{

		m_pinBuffer[i][0] = col[i];
		m_pinBuffer[i][1] = LOW;

		i++;
	}
}


void Selector::RunProgram(int i)
{
	switch (i)
	{
	case 1:		 
		Fade(REDPIN);
		break;
	case 2:		 
		Fade(YELLOWPIN);
		break;
	case 3:		 
		Fade(GREENPIN);
		break;
		 case 4:
			 DisolveTwo(REDPIN, YELLOWPIN);
		break;
		case 5:
			DisolveTwo(REDPIN, GREENPIN);
		break;
		case 6:
			DisolveTwo(GREENPIN, YELLOWPIN);
		break;
		case 7:
			DisolveThree(REDPIN, YELLOWPIN, GREENPIN);
		break;
		/*case 8:
		Prog8();
		break;*/
	}
}

void Selector::TurnOffPreviousPin()
{
	//turns off previouspin
	analogWrite(previouspin, LOW);
}

void Selector::Fade(int pin)
{	 
	
	Serial.println("Fading:");
	Serial.println(pin);

	analogWrite(pin, brightness);

	// change the brightness for next time through the loop:
	brightness = brightness + fadeAmount;

	// reverse the direction of the fading at the ends of the fade:
	if (brightness <= 0 || brightness >= 255) {
		fadeAmount = -fadeAmount;
	}
	// wait for 30 milliseconds to see the dimming effect
	delay(30);
	previouspin = pin;
	 
}

void Selector::Fade(int pins[])
{
	for (int i =0; i < sizeof(pins);i++)
	{

	}
}

void Selector::DisolveTwo(int pin1, int pin2)
{

}

void Selector::DisolveThree(int pin1, int pin2,int pin3)
{

}


 