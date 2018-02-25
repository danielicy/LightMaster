#include <Wire.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp;

# define BLINKPIN 0
# define INPUTPIN 1
# define ECHOPIN 13

// blinks MCP pin 0 on and off
// turns MCP pin 13 on when MCP pin 1 is high or unplugged

void setup() {  
  mcp.begin();      // use default address 0x20 (0,0,0)

  mcp.pinMode(BLINKPIN, OUTPUT);

  mcp.pinMode(INPUTPIN, INPUT);
  mcp.pullUp(INPUTPIN, HIGH);  // turn on a 100K pullup internally
}

void loop() {
  delay(100);
  mcp.digitalWrite(BLINKPIN, HIGH);
  delay(100);
  mcp.digitalWrite(BLINKPIN, LOW);

  // ECHO only updates every 200 ms
  digitalWrite(ECHOPIN, mcp.digitalRead(INPUTPIN));
}