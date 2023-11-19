#pragma once
#include "AdminException.h"

class AlreadyExistException : public AdminException
{
private:
	string m_str;
public:
	AlreadyExistException(string name);
	virtual  const char* what()                                 const override;
};