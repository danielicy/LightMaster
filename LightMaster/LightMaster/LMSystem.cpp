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

	// read the pushbutton input pin:
	buttonState = digitalRead(BUTTONPIN);

	// compare the buttonState to its previous state
	if (buttonState != lastButtonState) {
		// if the state has changed, increment the counter
		if (buttonState == HIGH) {
			// if the current state is HIGH then the button went from off to on:
			return true;
			Serial.println("on");
			Serial.print("number of button pushes: ");
			//Serial.println(buttonPushCounter);
		}
		else {
			// if the current state is LOW then the button went from on to off:
			return false;
			Serial.println("off");
		}
		// Delay a little bit to avoid bouncing
		delay(50);
	}
	// save the current state as the last state, for next time through the loop
	lastButtonState = buttonState;

}


void LMSystem::DoWork()
{

	if (IsButtonChanged())
	{
		SetIndex();
		_selector->Select(index);
		
		//TO Do: change Program acordingly
	}


	//TO DO: run selected Program
	_selector->RunProgram();
	


	

	
}

void LMSystem::Init()
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


void LMSystem::SetIndex()
{
	if (index < 8)
	{
		index++;
	}
	else
	{
		index = 1;
	}
	//Serial.println(index);
}



