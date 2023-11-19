#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "fstream"
using namespace std;
#include "Clock.h"
#include "ClockException.h"
#include "SetMinutesException.h";
#include "SetHoursException.h";
#include <time.h>

Clock::Clock()
{
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	int hours = now->tm_hour;
	int mins = now->tm_min;
	this->hours = hours;
	this->minutes = mins;
}

Clock::Clock(ifstream& in)
{
	in.read((char*)this, sizeof(*this));
}

void Clock::save(ofstream& out) const
{
	out.write((const char*)this, sizeof(*this));
}

bool Clock::setMinutes(const int& newMinutes) noexcept(false)
{
	bool res = false;
	if (newMinutes < 0 || newMinutes >= 60)
	{
		throw SetMinutesException();
	}
	else
	{
		minutes = newMinutes;
		res= true;
	}
	return res;
}

bool Clock::setHours(const int& newHours) noexcept(false)
{
	bool res = false;
	if (newHours < 0 || newHours >= 24)
	{
		throw SetHoursException();
	}
	else
	{
		hours = newHours;
		res = true;
	}
	return res;
}

int Clock::getMinutes() const
{
	return this->minutes;
}

int Clock::getHours() const
{
	return this->hours;
}

void Clock::show() const
{
	cout << " Hour: ";
	cout << (this->hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes;
}

void Clock::tick()
{
	addMinutes(1);
}

void Clock::addMinutes(const int& add)
{
	minutes += add;
	hours += minutes / 60;
	minutes /= 60;
	hours %= 24;
}

