#include "AlreadyExistException.h"
using namespace std;
#include <string>

AlreadyExistException::AlreadyExistException(string name)
{
	m_str = "<< Exception: " + name + " is already exist in system. >>";
}

const char* AlreadyExistException::what() const
{
	return m_str.c_str();
}