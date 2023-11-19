#include"SetMinutesException.h"
using namespace std;

 SetMinutesException::SetMinutesException()
 {
	 m_str = "<< Exception: Minutes have to be between 0 to 24, the value didn't change. >>";
 }

 const  char* SetMinutesException::what() const
 {
	 return m_str.c_str();
 }