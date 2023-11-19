#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
#include "Date.h"
#include "Utilities.h"
#include <time.h>

Date::Date()
{
	time_t t = time(0);   // get time now
	tm* now = localtime(&t);
	int day = now->tm_mday;
	int month = now->tm_mon + 1;
	int year = now->tm_year + START_YEAR;

	this->day = day;
	this->month = month;
	this->year = year;
}
 
Date::Date(ifstream& in)
{
	in.read((char*)this, sizeof(*this));
}

void Date::save(ofstream& out) const
{
	out.write((const char*)this, sizeof(*this));
}

Date::Date(int day, int month, int year)noexcept(false) :day(day), month(month)
{
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	int thisYear = now->tm_year + START_YEAR;

	if (!(day >= 1 && day <= 31 &&
		month >= 1 && month <= 12 &&
		year >= START_YEAR && year <= thisYear)) //not valid
	{
		throw DateException();
	}
	this->year = year;
}

int Date::getDay() const
{
	return this->day;
}

int Date::getMonth() const
{
	return this->month;
}

int Date::getYear() const
{
	return this->year;
}

void Date::show() const
{
	cout << "Date: ";
	cout << (this->day < 10 ? "0" : "") << this->day << "/" << (this->month < 10 ? "0" : "") << this->month << "/" << this->year;
}

