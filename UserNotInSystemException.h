#pragma once
#include "AdminException.h"

class UserNotInSystemException : public AdminException
{
private:
	string m_str;
public:
	UserNotInSystemException(string name);
	virtual const char* what()                                  const override;
};