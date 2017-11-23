// 
// 
// 

#include "Selector.h"

Selector::Selector(int pin)
{

}

Selector::Selector()
{

}

Selector::~Selector()
{
}



void Selector::Select()
{
	
	TurnOffPreviousPin();
	
	if (m_prgidx < PRGCNT)
	{
		m_prgidx++;
	}
	else
	{
		m_prgidx = 1;
	}
	Serial.println("Selection changed:" + m_prgidx);
 
	delay(1000);
	
}

void Selector::RunProgram()
{
	switch (m_prgidx)
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


 