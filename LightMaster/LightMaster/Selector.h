// Selector.h
#pragma once

#ifndef _SELECTOR_h
#define _SELECTOR_h



#define PROGRAMS_CNT 12

#endif
#ifndef Selector_h
#define Selector_h



#include "ActionManager.h"
#include "Lamp.h"
#include "LampsManager.h"



class ActionManager;
class LampsManager;

class Selector
{
public:	
	Selector();
	Selector(ActionManager* actionManager, LampsManager* lampsManager);
	~Selector();
	void ChangeSelection(byte &index, byte param);
	void SelectColors();
	void SelectProgram();
	
	
private:
	void LoadColors();
	void LoadProgram();

	byte m_colorIndex; //the currrent color combination
	byte m_progIndex  ;        //the current program selected

	
	ActionManager* m_actionManager;
	LampsManager* m_lampsManager;
};

#endif

