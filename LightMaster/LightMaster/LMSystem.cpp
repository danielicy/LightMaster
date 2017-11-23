// 
// 

#include "LMSystem.h"
#include "Selector.h"


Selector* _selector = new Selector();

LMSystem::LMSystem()
{
	Serial.begin(9600);
	pinMode(PRGBTN, INPUT);
	pinMode(COLRBTN, INPUT);

	pinMode(REDPIN, OUTPUT);
	pinMode(YELLOWPIN, OUTPUT);
	pinMode(GREENPIN, OUTPUT);

	// set initial LED state
	 
	DigitalWrite(new int[3]{ REDPIN,YELLOWPIN,GREENPIN }, LOW);	
}


void LMSystem::DigitalWrite(int  pins[],int value)
{	
	for (int i = 0; i < sizeof(pins); i++)
	{
		digitalWrite(pins[i], value);		 
	}	
}

LMSystem::~LMSystem()
{
}


bool LMSystem::IsPrgBtn(int btn)
{ 
	bool retval = false;
	// read the pushbutton input pin:
	 buttonState = digitalRead(btn);	 
		 
	if (buttonState == HIGH)
	{
		if (buttonState != lastButtonState || buttonState != lastcolorBtn)
		{
			Serial.println("button ON");
			retval = true;
		}
		else
		{
			retval = false;
		}
	}
	else
	{
		Serial.println("off");
		retval = false;
	}
	// Delay a little bit to avoid bouncing
	delay(50);
	if(btn == PRGBTN)
	lastButtonState = buttonState;

	if (btn == COLRBTN)
		lastcolorBtn = buttonState;

	return retval;

}

void LMSystem::DoWork()
{
	if (IsPrgBtn(PRGBTN))
	{
		Serial.println("program selection changed:");
		 		
		_selector->Select();		
	}

	if (IsPrgBtn(COLRBTN))
	{
		Serial.println("Color Button Pressed:");
		delay(7000);
	}
		
	_selector->RunProgram();	
}
 


 