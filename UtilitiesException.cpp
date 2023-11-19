#include "UtilitiesException.h"
using namespace std;

UtilitiesException::UtilitiesException()
{
	m_str = "<< Exception: Utilities exception. >>";
}

const char* UtilitiesException::what() const
{
	return m_str.c_str();
}
