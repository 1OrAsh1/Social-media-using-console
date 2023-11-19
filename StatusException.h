#pragma once
#include <string>
using namespace std;

class StatusException : public exception
{
private:
	string m_str;
public:
	StatusException();
	virtual const  char* what()          const override;
};