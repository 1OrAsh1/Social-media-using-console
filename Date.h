#ifndef __DATE_H_
#define __DATE_H_
#define START_YEAR 1900
#include "DateException.h"

class Date
{
private:
	 int day;
	 int month;
	 int year;

public:
	Date() ;
	Date(ifstream& in);
	Date(int day, int month, int year)noexcept(false);
	virtual void save(ofstream& out)                    const;
	int getDay()                                        const;
	int getMonth()                                      const;
	int getYear()                                       const;
	void show()                                         const;
};

#endif // !__DATE_H_
