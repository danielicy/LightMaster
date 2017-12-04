#pragma once
#include "ActionManager.h"
#include "ColorManager.h"
#include "Selector.h"


//#define LMSYSIMP __declspec(dllimport)

#define PINCNT 20

class DummySystem
{
public:
	DummySystem();
	~DummySystem();
	Selector* m_selector;
	ActionManager* m_ActionManager;
	ColorManager* m_colorManager;
private:
	int m_pinBuffer[PINCNT][2];
};

