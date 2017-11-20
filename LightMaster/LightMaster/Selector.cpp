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



void Selector::Select(int i)
{

	selectedProgram = i;
	
}

void Selector::RunProgram()
{
	switch (selectedProgram)
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
		/*case 4:
		Prog4();
		break;
		case 5:
		Prog5();
		break;
		case 6:
		Prog6();
		break;
		case 7:
		Prog7();
		break;
		case 8:
		Prog8();
		break;*/
	}
}

int previousPin;

void Selector::Fade(int pin)
{
	brightness = 5;
	//turns off previouspin
	analogWrite(previousPin, LOW);

	analogWrite(pin, brightness);

	// change the brightness for next time through the loop:
	brightness = brightness + fadeAmount;

	// reverse the direction of the fading at the ends of the fade:
	if (brightness <= 0 || brightness >= 255) {
		fadeAmount = -fadeAmount;
	}
	// wait for 30 milliseconds to see the dimming effect
	delay(30);
	previousPin = pin;
	 
}



/*


void Prog2()
{
Serial.println(2);
}


void Prog3()
{
Serial.println(3);
}


void Prog4()
{
Serial.println(4);
}


void Prog5()
{
Serial.println(5);
}
void Prog6()
{
Serial.println(6);
}

void Prog7()
{
Serial.println(7);
}

void Prog8()
{
Serial.println(8);
}




*/