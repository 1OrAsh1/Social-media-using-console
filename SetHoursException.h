#pragma once
#include "ClockException.h"

class SetHoursException :public ClockException
{
private:
	string m_str;
public:
	SetHoursException();
	virtual const  char* what()  const override;
};