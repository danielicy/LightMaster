#include "Selector.h"

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 3;      // the number of the LED pin

						   // Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

int index = 0;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 10;    // the debounce time; increase if the output flickers


           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 1;    // how many points to fade the LED by


Selector* _selector = new Selector();

void setup() {
	pinMode(buttonPin, INPUT);
	pinMode(ledPin, OUTPUT);

	// set initial LED state
	digitalWrite(ledPin, ledState);
	Serial.begin(9600);
}

void loop() {
	DoWork();
}

void DoWork()
{

	 
	// read the state of the switch into a local variable:
	int reading = digitalRead(buttonPin);

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
	digitalWrite(ledPin, ledState);

	// save the reading. Next time through the loop, it'll be the lastButtonState:
	lastButtonState = reading;
}

void SetIndex()
{
	if (index < 8)
	{
		index = index + 1;
	}
	else
	{
		index = 1;
	}
	Serial.println(index);
}
 


void Prog2()
{
	Serial.println(2);
}


void Prog3()
{
	Serial.println(3);
}


void Prog4()
{
	Serial.println(4);
}


void Prog5()
{
	Serial.println(5);
}
void Prog6()
{
	Serial.println(6);
}

void Prog7()
{
	Serial.println(7);
}

void Prog8()
{
	Serial.println(8);
}


