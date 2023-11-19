#include "UserException.h"
using namespace std;

UserException::UserException()
{
	m_str = "<< Exception: User's name can't be empty >>";
}

 const char* UserException::what() const 
{
	return m_str.c_str();
}