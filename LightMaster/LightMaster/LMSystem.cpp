
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"

#include "Wire.h"
#else
#include "stdfax.h"
#endif

#include "LMSystem.h"
#include "LampsManager.h"
#include "Selector.h"
#include "ColorManager.h"
#include "OutputManger.h"

//https://github.com/esp8266/Arduino


/*
void SetWire()
{
	//setup
	//http://www.esp8266learning.com/esp8266-mcp23017-example.php
	Wire.begin(); // wake up I2C bus
				  // set I/O pins to outputs
	Wire.beginTransmission(0x20);
	Wire.write(0x00); // IODIRA register
	Wire.write(0x00); // set all of port A to outputs
	Wire.endTransmission();
}

void WriteWire()
{
	//loop
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
*/
LMSystem::LMSystem()
{
	m_outputManager = new COutputManger();
	
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
	pinMode(ORANGEPIN, OUTPUT);
	pinMode(YELLOWPIN, OUTPUT);
	pinMode(GREENPIN, OUTPUT);

	// set initial LED state
	 
	DigitalWrite(new int[3]{ ORANGEPIN,YELLOWPIN,GREENPIN }, LOW);	
#endif

	//SetWire();

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
			m_outputManager->Log("button pressed");
			retval = true;
		}
		else
		{
			retval = false;
		}
	}
	else
	{
		m_outputManager->Log("off");

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
	 m_outputManager->Log("program selection changed:");
	

		m_selector->SelectProgram();
	}

	if (IsBtnPressed(COLRBTN) || c == 'c')
	{		
		m_outputManager->Log("Color Button Pressed:");
		
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
