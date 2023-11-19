#include "StatusException.h"
using namespace std;

StatusException::StatusException()
{
	m_str = "<< Exception: Status can't be Empty. >>";
}

 const char* StatusException::what() const 
{
	return m_str.c_str();
}