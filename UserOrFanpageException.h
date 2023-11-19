#pragma once
#include "UtilitiesException.h"

class UserOrFanpageException : public UtilitiesException
{
private:
	string m_str;
public:
	UserOrFanpageException();
	virtual const char* what()                                  const override;
};