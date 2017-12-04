#include "stdafx.h"
#include "DummySystem.h"

#include "ActionManager.h"
//#include "ColorManager.h"
//#include "Selector.h"




DummySystem::DummySystem()
{
	m_ActionManager = new ActionManager(m_pinBuffer);
	//m_colorManager = new ColorManager();
	//m_selector = new Selector(m_colorManager, m_ActionManager);
}


DummySystem::~DummySystem()
{
}
