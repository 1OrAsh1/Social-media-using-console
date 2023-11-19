#include"AddUserToUserException.h"

AddUserToUserException::AddUserToUserException(string user1, string user2) 
{
	m_str = "<< Exception: " + user1 + " is already a friend of " + user2 + ". >>";
}

 const char* AddUserToUserException::what() const 
{
	return m_str.c_str();
}