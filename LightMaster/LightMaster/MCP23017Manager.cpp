#pragma once

#include "MCP23017Manager.h"
#include "Arduino.h"

#include <Wire.h>

#include "Adafruit_MCP23017.h"  // https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library

MCP23017Manager::MCP23017Manager()
{
}


MCP23017Manager::~MCP23017Manager()
{
}





const unsigned int onTime = 300;
const unsigned int offTime = 1000;
unsigned long previousMillis = 0;
unsigned long rgbPMillis = 0;
const unsigned long rgbOnTime = 200;
unsigned long tt = onTime;
boolean LEDstate = true;
const byte rgbLED[3] = { 8, 9, 10 };
const byte blinkLED = 7;
int count = 0;
int lastCount = 1;

// using a structure to group together the button controls.
struct MCP_BUTTONS {
	const byte buttns[4] = { 4, 5, 6, 7 };   // buttons are attached to these GPIO ports
	boolean btnState[4] = { false, false, false, false };
	boolean btnPressed = false;
	byte btnKey = 0;
};

MCP_BUTTONS btns;

// http://forum.arduino.cc/index.php?topic=119261.0
void MCP23017Manager::DisplayBinary(int count) {
	char binary[4] = { 0 };
	count += 8;                 // fix the length to four bytes  3 + 8 = 11  = 0b1011
	itoa(count, binary, 2);       // convert count to a base 2 char array  
	char* string = binary + 1;  // remove the most significant (first) bit   = 0b011

	for (byte i = 0; i < 3; i++) {
		mcp0.digitalWrite(rgbLED[i], string[i] - '0'); // - '0' converts the bit to HIGH or LOW
	}
}

boolean MCP23017Manager::IsButtonBeingPressed() {

	boolean b;

	// check to see that the button has been released before setting the settings
	if (btns.btnPressed == true && mcp1.digitalRead(btns.buttns[btns.btnKey]) == true) {
		btns.btnPressed = false;
		btns.btnState[btns.btnKey] = !(btns.btnState[btns.btnKey]); // toggle the logic
		return true;
	}

	// read the four buttons, see if one is being pressed
	for (byte i = 0; i < 4; i++) {
		b = mcp1.digitalRead(btns.buttns[i]);
		if (b == false) {
			btns.btnKey = i;
			btns.btnPressed = true;
			break;
		}
	}
	return false;
}

void MCP23017Manager::DoThingWithButton() {

	boolean b;
	// the fourth button switches all LEDs off and resets the button state
	if (btns.btnState[3] == true) {
		for (byte i = 0; i < 4; i++) {
			mcp1.digitalWrite(rgbLED[i], true);
			btns.btnState[i] = false;
		}
		return;
	}

	for (byte i = 0; i < 3; i++) {
		b = !(btns.btnState[i]);  //  invert the logic for common anode LED: HIGH = off, LOW = on.
		mcp1.digitalWrite(rgbLED[i], b);
	}
}

void MCP23017Manager::McpSetup() {

	// setup the RGB LEDs - the RGB LEDs are common anode, so the output needs to be high to turn them off.
	for (byte i = 0; i < 3; i++) {
		mcp0.pinMode(rgbLED[i], OUTPUT);
		mcp0.digitalWrite(rgbLED[i], HIGH);  // turn LEDS off

		mcp1.pinMode(rgbLED[i], OUTPUT);
		mcp1.digitalWrite(rgbLED[i], HIGH);  // turn LEDS off
	}

	// setup the buttons
	for (byte i = 0; i < 4; i++) {
		mcp1.pinMode(btns.buttns[i], INPUT);
		mcp1.pullUp(btns.buttns[i], HIGH);       // activate internal pullup resistor
	}

}

void MCP23017Manager::Setup() {
	delay(1000);
	Serial.begin(9600);

	Wire.begin();
	mcp0.begin(0);    // 0 = i2c address 0x20
	mcp1.begin(1);    // 1 = i2c address 0x21

	McpSetup();
	mcp0.pinMode(blinkLED, OUTPUT);    // setup the blink led
	mcp0.digitalWrite(blinkLED, LOW);

	Serial.println("ready");

}

//void loop() {

	//mcp0.digitalWrite(blinkLED, LEDstate);

	//// only change the RGB colour when the counter has changed
	//if (count != lastCount) {
	//	displayBinary(count);
	//	lastCount = count;
	//}

	//boolean btn = isButtonBeingPressed();
	//if (btn == true) {
	//	doThingWithButton();
	//}
	//unsigned long currentMillis = millis();

	//// the blinking LED is lit for a sorter time than it is off
	//// I forgot where I got this code from, but will update once I do.
	//if ((currentMillis - previousMillis) >= tt) {
	//	if (LEDstate) {
	//		tt = offTime;
	//	}
	//	else {
	//		tt = onTime;
	//	}
	//	LEDstate = !(LEDstate);
	//	previousMillis = currentMillis;
	//}

	//// increment the counter every rgbOnTime millis, then reset it when all three bits are true (0b111)
	//if ((currentMillis - rgbPMillis) >= rgbOnTime) {
	//	count++;
	//	if (count > 7) {
	//		count = 0;
	//	}
	//	rgbPMillis = currentMillis;
	//}

//}