#pragma once
#include "ClockException.h"

class SetMinutesException :public ClockException
{
private:
	string m_str;
public:
	SetMinutesException();
	virtual const char* what()                 const override;
};