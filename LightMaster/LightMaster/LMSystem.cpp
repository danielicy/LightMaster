// 
// 

#include "LMSystem.h"
#include "Selector.h"


Selector* _selector = new Selector();
 
 

//void DoWork();

LMSystem::LMSystem()
{
	Serial.begin(9600);
	pinMode(BUTTONPIN, INPUT);

	pinMode(REDPIN, OUTPUT);
	pinMode(YELLOWPIN, OUTPUT);
	pinMode(GREENPIN, OUTPUT);

	// set initial LED state
	digitalWrite(REDPIN, ledState);
	digitalWrite(YELLOWPIN, ledState);
	digitalWrite(GREENPIN, ledState);
	//Serial.println("Writing pinArray");
	//DigitalWrite(new int[3]{ REDPIN,YELLOWPIN,GREENPIN }, LOW);

	
}


void LMSystem::DigitalWrite(int  pins[],int value)
{
	int pinsCnt = 0;
	while (pinsCnt <= sizeof(pins))
	{
		digitalWrite(pins[pinsCnt], value);
		pinsCnt++;
		Serial.println("pin: " + sizeof(pins));
	}
	
}

LMSystem::~LMSystem()
{
}


bool LMSystem::IsButtonChanged()
{ 
	bool retval = false;
	// read the pushbutton input pin:
	 buttonState = digitalRead(BUTTONPIN);
	Serial.println("buttonState is:");
	Serial.println(buttonState);
		 
	if (buttonState == HIGH)
	{
		if (buttonState != lastButtonState)
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
	lastButtonState = buttonState;

	return retval;

}


void LMSystem::DoWork()
{
	bool buttonPushed = LMSystem::IsButtonChanged();
	Serial.println("pushed:");
	Serial.println(buttonPushed);

	if (buttonPushed)
	{
		SetIndex();
		_selector->Select(index);
		
		//TO Do: change Program acordingly
	}


	//TO DO: run selected Program
	_selector->RunProgram();
	


	

	
}
 


void LMSystem::SetIndex()
{
	if (index < 3)
	{
		index++;
	}
	else
	{
		index = 1;
	}
	//Serial.println(index);
}



