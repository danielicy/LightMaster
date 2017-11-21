// 
// 
// 

#include "LMSystem.h"
#include "Selector.h"


Selector* _selector = new Selector();


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
	Serial.println("Writing pinArray");
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

void LMSystem::DoWork()
{

	// read the state of the switch into a local variable:
	int reading = digitalRead(BUTTONPIN);

	// check to see if you just pressed the button
	// (i.e. the input went from LOW to HIGH), and you've waited long enough
	// since the last press to ignore any noise:

	// If the switch changed, due to noise or pressing:
	if (reading != lastButtonState) {
		// reset the debouncing timer
		lastDebounceTime = millis();

	}

	if ((millis() - lastDebounceTime) > debounceDelay) {
		// whatever the reading is at, it's been there for longer than the debounce
		// delay, so take it as the actual current state:

		// if the button state has changed:
		if (reading != buttonState) {
			buttonState = reading;

			// only toggle the LED if the new button state is HIGH
			if (buttonState == HIGH) {
				ledState = !ledState;
				SetIndex();
			}
		}
	}


	_selector->Select(index);


	// set the LED:
	//digitalWrite(REDPIN, ledState);

	// save the reading. Next time through the loop, it'll be the lastButtonState:
	lastButtonState = reading;
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
	Serial.println(index);
}



