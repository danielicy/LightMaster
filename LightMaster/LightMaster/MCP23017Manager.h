#pragma once

#include "Adafruit_MCP23017.h"
#include "Arduino.h"

class MCP23017Manager
{
public:
	MCP23017Manager();
	~MCP23017Manager();

	void DigitalWrite(int pin, int val);	
private:
	void Setup();
	
	void DisplayBinary(int count);
	boolean IsButtonBeingPressed();
	void DoThingWithButton();
	void McpSetup();

	byte GetPin(byte lampName, byte & val);

	// setup the port expander
	Adafruit_MCP23017 mcp0;  // assign each expander its own mcp name
	Adafruit_MCP23017 mcp1;
	 
};

