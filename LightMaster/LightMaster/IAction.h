#pragma once


class  IAction
{
public:
	virtual void Execute() = 0;
	virtual void Dispose() =0;

};
