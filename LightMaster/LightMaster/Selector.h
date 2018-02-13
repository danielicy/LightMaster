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
	void ChangeSelection(int &index, int param);
	void SelectColors();
	void SelectProgram();

	
	
private:
	void LoadColors();
	void LoadProgram();


	int m_colorIndex; //the currrent color combination
	int m_progIndex  ;        //the current program selecte

	ActionManager* m_actionManager;
	LampsManager* m_lampsManager;
};

#endif

