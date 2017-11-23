// 
// 

#include "LMSystem.h"
#include "Selector.h"


Selector* _selector = new Selector();
 
 

//void DoWork();

LMSystem::LMSystem()
{
	Serial.begin(9600);
	pinMode(PRGBTN, INPUT);
	pinMode(COLRBTN, INPUT);



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


bool LMSystem::IsPrgBtn()
{ 
	bool retval = false;
	// read the pushbutton input pin:
	 buttonState = digitalRead(PRGBTN);
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
	 

	if (IsPrgBtn())
	{
		Serial.println("program selection changed:");
		 		
		_selector->Select();		
	}
		
	_selector->RunProgram();
	
}
 


 