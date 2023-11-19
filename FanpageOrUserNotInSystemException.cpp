#include "FanpageOrUserNotInSystemException.h"
using namespace std;


FanpageOrUserNotInSystemException::FanpageOrUserNotInSystemException(string name)
{
	m_str = "<< Exception: " + name + " is not in system. >>";
}

const char* FanpageOrUserNotInSystemException::what() const
{
	return m_str.c_str();
}