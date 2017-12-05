// 
// 

#include "LMSystem.h"
#include "Selector.h"
#include "ColorManager.h"




LMSystem::LMSystem()
{
	
	//m_ActionManager = new ActionManager(m_pinBuffer);
	m_colorManager = new ColorManager();
	m_selector = new Selector(m_colorManager,m_ActionManager);
 

	Serial.begin(9600);
	pinMode(PRGBTN, INPUT);
	pinMode(COLRBTN, INPUT);

	pinMode(REDPIN, OUTPUT);
	pinMode(YELLOWPIN, OUTPUT);
	pinMode(GREENPIN, OUTPUT);

	// set initial LED state
	 
	DigitalWrite(new int[3]{ REDPIN,YELLOWPIN,GREENPIN }, LOW);	
}


LMSystem::~LMSystem()
{
}

void LMSystem::DigitalWrite(int  pins[], int value)
{
	for (int i = 0; i < sizeof(pins); i++)
	{
		digitalWrite(pins[i], value);
	}
}


bool LMSystem::IsBtnPressed(int btn)
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
	if (IsBtnPressed(PRGBTN))
	{
		Serial.println("program selection changed:");
		
		TurnOffPreviousPin();

		m_selector->SelectProgram();
	}

	if (IsBtnPressed(COLRBTN))
	{		
		Serial.println("Color Button Pressed:");
		m_selector->SelectColors();
		delay(7000);
	}
		
	//m_ActionManager->Execute();
}
 

 

void LMSystem::TurnOffPreviousPin()
{
	//turns off previouspin
	analogWrite(previouspin, LOW);
}


 