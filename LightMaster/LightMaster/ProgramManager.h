#pragma once
class ProgramManager
{
public:
	ProgramManager(int buffer[][2]);//int &pinbuffer);
	~ProgramManager();
private:
	void Fade();
	int* m_buffer;// [][2];
};

