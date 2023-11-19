#include "RemoveUserFromUserException.h"
using namespace std;


RemoveUserFromUserException::RemoveUserFromUserException(string user1, string user2)
{
	m_str = "<< Exception: " + user1 + " is not a friend of " + user2 + ". >>";
}

 const char* RemoveUserFromUserException::what() const 
{
	return m_str.c_str();
}