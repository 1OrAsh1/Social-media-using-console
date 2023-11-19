#pragma once
#include "AdminException.h"

class RemoveUserFromFanpageException : public AdminException
{
private:
	string m_str;
public:
	RemoveUserFromFanpageException(string user, string fanpage);
	virtual const char* what()                                  const override;
};