#pragma once
#include <string>
using namespace std;

class DateException : public exception
{
private:
	string m_str;
public:
	DateException();
	virtual const char* what()    const override;
};