#pragma once
#include "AdminException.h"

class FanpageOrUserNotInSystemException : public AdminException
{
private:
	string m_str;
public:
	FanpageOrUserNotInSystemException(string name);
	virtual const char* what()                                  const override;
};