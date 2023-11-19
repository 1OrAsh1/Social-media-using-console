#include"SetHoursException.h"
using namespace std;

SetHoursException::SetHoursException()
{
	m_str = "<< Exception: Hours have to be between 0 to 24, the value didn't change. >>";
}

const  char* SetHoursException::what() const
{
	return m_str.c_str();
}