#pragma once
#include <string>
using namespace std;

class UtilitiesException : public exception
{
private:
	string m_str;
public:
	UtilitiesException();
	virtual const char* what() const override;
};