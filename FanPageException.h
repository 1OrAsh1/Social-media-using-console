#pragma once
#include <string>
using namespace std;

class FanPageException : public exception
{
private:
	string m_str;
public:
	FanPageException();
	virtual const  char* what()              const override;
};