#include "UserOrFanpageException.h"
using namespace std;

UserOrFanpageException::UserOrFanpageException()
{
	m_str = "<< Exception: value is illigal and should be number 1 or 2. >>";
}

const char* UserOrFanpageException::what() const
{
	return m_str.c_str();
}
