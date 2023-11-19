#include "AddUserToFanpageException.h"
using namespace std;
#include <string>

AddUserToFanpageException::AddUserToFanpageException(string user, string fanpage)
{
	m_str ="<< Exception: "+ user + " is already a fan of " + fanpage + ". >>";
}

 const char* AddUserToFanpageException::what() const 
{
	return m_str.c_str();
}