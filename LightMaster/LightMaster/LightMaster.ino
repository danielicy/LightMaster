/*
 Name:		LightMaster.ino
 Created:	11/19/2017 12:42:37 PM
 Author:	administrator
*/

// the setup function runs once when you press reset or power the board
#include "OutputManger.h"

#include "Selector.h"
#include "LMSystem.h"


LMSystem* _lightMasterSystem = new LMSystem();

void setup() {

}

// the loop function runs over and over again until power down or reset
void loop() {
  
	_lightMasterSystem->DoWork('0');
}
