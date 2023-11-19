#include "AddHimselfException.h"
using namespace std;
#include <string>

AddHimselfException::AddHimselfException()
{
	m_str = "<< Exception: user can't have friendship himself. >>";
}

const char* AddHimselfException::what() const
{
	return m_str.c_str();
}