#pragma once
class ActionManager
{
public:
	ActionManager(int buffer[][2]);//int &pinbuffer);
	~ActionManager();
private:
	void Fade();
	int* m_buffer;// [][2];
};

