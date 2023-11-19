#pragma once
#include <string>
using namespace std;

class UserException : public exception
{
private:
	string m_str;
public:
	UserException();
	virtual const char* what()     const override;
};