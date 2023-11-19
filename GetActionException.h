#pragma once
#include "UtilitiesException.h"

class GetActionException : public UtilitiesException
{
private:
	string m_str;
public:
	GetActionException();
	virtual const char* what()                                  const override;
};