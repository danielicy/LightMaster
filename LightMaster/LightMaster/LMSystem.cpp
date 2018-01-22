
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "Wire.h"
#include "LMSystem.h"
#include "LampsManager.h"
#include "Selector.h"
#include "ColorManager.h"

//https://github.com/esp8266/Arduino
//http://www.esp8266learning.com/esp8266-mcp23017-example.php


void SetWire()
{
	Wire.begin(); // wake up I2C bus
				  // set I/O pins to outputs
	Wire.beginTransmission(0x20);
	Wire.write(0x00); // IODIRA register
	Wire.write(0x00); // set all of port A to outputs
	Wire.endTransmission();
}

void WriteWire()
{
	Wire.beginTransmission(0x20);
	Wire.write(0x12); // address bank A
	Wire.write((byte)0xAA); // value to send
	Wire.endTransmission();
	delay(500);
	Wire.beginTransmission(0x20);
	Wire.write(0x12); // address bank A
	Wire.write((byte)0x55); // value to send
	Wire.endTransmission();
	delay(500);
}

LMSystem::LMSystem()
{
	m_lampsManager = new LampsManager();
	m_ActionManager = new ActionManager(m_lampsManager);
	m_colorManager = new ColorManager();
	
	m_selector = new Selector(m_colorManager,m_ActionManager,m_lampsManager);
 
	m_selector->SelectColors();
	m_selector->SelectProgram();
	

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

	SetWire();

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
	int i = 0;
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
 
	m_ActionManager->Execute();	
}
 
void LMSystem::TurnOffPreviousPin()
{
#if defined(ARDUINO) && ARDUINO >= 100
 	//turns off previouspin
	analogWrite(previouspin, LOW);
#endif

}
