
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"


#else
#include "stdfax.h"
#endif

#include "LMSystem.h"
#include "LampsManager.h"
#include "Selector.h"
#include "ColorManager.h"
#include "OutputManger.h"

//https://github.com/esp8266/Arduino

  

volatile byte programInterruptCnt = 1;
volatile byte colorInterruptCnt = 1;

void handleProgramButton() {

	programInterruptCnt++;

}

void handleColorButton() {

	colorInterruptCnt++;

}

LMSystem::LMSystem()
{
	m_outputManager = new COutputManger();

	m_colorManager = new ColorManager();
	m_lampsManager = new LampsManager(m_colorManager, m_outputManager);
	m_ActionManager = new ActionManager(m_lampsManager);
	
	
	m_selector = new Selector(m_ActionManager,m_lampsManager);
 	

#if defined(ARDUINO) && ARDUINO >= 100

	Serial.begin(9600);
	pinMode(PRGBTN, INPUT_PULLUP);
	pinMode(COLRBTN, INPUT_PULLUP);

	attachInterrupt(digitalPinToInterrupt(PRGBTN), handleProgramButton, FALLING);
	attachInterrupt(digitalPinToInterrupt(COLRBTN), handleColorButton, FALLING);


	pinMode(REDPIN, OUTPUT);
	pinMode(ORANGEPIN, OUTPUT);
	pinMode(YELLOWPIN, OUTPUT);
	pinMode(GREENPIN, OUTPUT);

	// set initial LED state	 
	DigitalWrite(new int[4]{ REDPIN,ORANGEPIN,YELLOWPIN,GREENPIN }, LOW);
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



void LMSystem::DoWork(char c)
{	
 
	if (colorInterruptCnt > 0 || c == 'c') {

		colorInterruptCnt--;
		m_selector->SelectColors();

	}

	if (programInterruptCnt > 0 || c == 'p') {

		programInterruptCnt--;
		m_selector->SelectProgram();
		
	}

	m_ActionManager->Execute();	
}
 
 