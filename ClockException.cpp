#include "ClockException.h"
using namespace std;

ClockException::ClockException() 
{
	m_str = "<< Exception: Clock setting exception. >>";

}

 const char* ClockException::what()  const 
{
	return m_str.c_str();
}