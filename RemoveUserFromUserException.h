#pragma once
#include "AdminException.h"

class RemoveUserFromUserException : public AdminException
{
private:
	string m_str;
public:
	RemoveUserFromUserException(string user1, string user2);
	virtual const char* what()                                  const override;
};