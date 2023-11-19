#pragma once
#ifndef CLOCK_H
#define CLOCK_H
#include "ClockException.h"

class Clock
{
private:
	int hours;
	int minutes;

public:

	Clock();
	Clock(ifstream& in);
	virtual void save(ofstream& out)                        const;
	int getMinutes()                                        const;
	int getHours()                                          const;
	bool setMinutes(const int& newMinutes)noexcept(false);
	bool setHours(const int& newHours)noexcept(false);
	void show()                                             const;
	void tick();
	void addMinutes(const int& add);
};

#endif //