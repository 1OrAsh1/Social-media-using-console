#pragma once
#include <string>
using namespace std;

class AdminException : public exception
{
private:
	string m_str;
public:
	AdminException();
	virtual const char* what() const override;
};