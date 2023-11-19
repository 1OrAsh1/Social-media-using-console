#include "AdminException.h"
using namespace std;

AdminException::AdminException()
{
	m_str = "<< Exception: Admin exception. >>";
}

 const char* AdminException::what() const 
{
	return m_str.c_str();
}