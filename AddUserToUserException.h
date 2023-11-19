#pragma once
#include "AdminException.h"

class AddUserToUserException : public AdminException
{
private:
	string m_str;
public:
	AddUserToUserException(string user1, string user2);
	virtual  const char* what()                                 const override;
};