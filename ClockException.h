#pragma once
#include <string>
using namespace std;

class ClockException : public exception
{
private:
	string m_str;
public:
	ClockException();
	virtual  const char* what()      const override;
};