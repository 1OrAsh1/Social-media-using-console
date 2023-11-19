#include "RemoveUserFromFanpageException.h"
using namespace std;


RemoveUserFromFanpageException::RemoveUserFromFanpageException(string user, string fanpage) 
{
	m_str = "<< Exception: " + user + " is not a fan of " + fanpage + ". >>";
}

 const char* RemoveUserFromFanpageException::what() const 
{
	return m_str.c_str();
}