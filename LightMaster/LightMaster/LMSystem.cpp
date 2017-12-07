
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif


#include "LMSystem.h"
#include "Selector.h"
#include "ColorManager.h"



LMSystem::LMSystem()
{
	
	m_ActionManager = new ActionManager();
	m_colorManager = new ColorManager();
	m_selector = new Selector(m_colorManager,m_ActionManager);
 
#if defined(ARDUINO) && ARDUINO >= 100

	Serial.begin(9600);
	pinMode(PRGBTN, INPUT);
	pinMode(COLRBTN, INPUT);

	pinMode(REDPIN, OUTPUT);
	pinMode(YELLOWPIN, OUTPUT);
	pinMode(GREENPIN, OUTPUT);

	// set initial LED state
	 
	DigitalWrite(new int[3]{ REDPIN,YELLOWPIN,GREENPIN }, LOW);	
#endif

}

LMSystem::~LMSystem()
{
}

void LMSystem::DigitalWrite(int  pins[], int value)
{

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
 	for (int i = 0; i < sizeof(pins); i++)
	{
		digitalWrite(pins[i], value);
	}
#endif

}

bool LMSystem::IsBtnPressed(int btn)
{ 
	bool retval = false;
#if defined(ARDUINO) && ARDUINO >= 100
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
#endif

	

	return retval;

}

void LMSystem::DoWork(char c)
{
 if (IsBtnPressed(PRGBTN) || c =='p')
	{
		//Serial.println("program selection changed:");
		
		TurnOffPreviousPin();

		m_selector->SelectProgram();
	}

	if (IsBtnPressed(COLRBTN) || c == 'c')
	{		
		//Serial.println("Color Button Pressed:");
		m_selector->SelectColors();
		//delay(7000);
	}
#if defined(ARDUINO) && ARDUINO >= 100

#else
 
#endif
		
		
	m_ActionManager->Execute();
}
 
void LMSystem::TurnOffPreviousPin()
{
#if defined(ARDUINO) && ARDUINO >= 100
 	//turns off previouspin
	analogWrite(previouspin, LOW);
#endif

}


 