#include "DateException.h"
using namespace std;

DateException::DateException()
{
	m_str = "<< Exception: Date is invalid. >>";
}

 const char* DateException::what() const 
{
	return m_str.c_str();
}