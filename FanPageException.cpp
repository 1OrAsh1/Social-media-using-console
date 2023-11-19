#include "FanPageException.h"
using namespace std;

FanPageException::FanPageException()
{
	m_str = "<< Exception: Fan page's name can't be empty. >>";
}

 const  char* FanPageException::what() const 
{
	return m_str.c_str();
}