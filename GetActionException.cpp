#include "GetActionException.h"
using namespace std;

GetActionException::GetActionException()
{
	m_str = "<< Exception: value is illigal and should be number between 1-12. >>";
}

const char* GetActionException::what() const
{
	return m_str.c_str();
}
