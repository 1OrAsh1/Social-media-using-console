#pragma once
#include "AdminException.h"
#include <string>

class AddUserToFanpageException : public AdminException
{
private:
	string m_str;
public:
	AddUserToFanpageException(string user, string fanpage);
	virtual const char*  what()                                  const override;
};