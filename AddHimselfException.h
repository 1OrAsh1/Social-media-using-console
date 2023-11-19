#pragma once
#include "AdminException.h"
#include <string>

class AddHimselfException : public AdminException
{
private:
	string m_str;
public:
	AddHimselfException();
	virtual const char* what()                                  const override;
};