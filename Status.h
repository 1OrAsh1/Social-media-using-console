#ifndef __STATUS_H_
#define __STATUS_H_
#include "Date.h"
#include "Clock.h"
#include <string>  
#include "StatusException.h"

class Status
{
protected:
	const Date publishDate;
	const Clock publishHour;
	string text;
	string color;
	string program;


public:
	Status(string content) noexcept(false);
	Status(const Status& other);
	Status(ifstream& in);
	virtual void save(ofstream& out)              const;
	virtual ~Status();
	const Date& getPublishDate()                  const;
	const Clock& getPublishHour()                 const;
	const string getText()                        const;
	void showDate()                               const;
	void showHour()                               const;
	void showText()                               const;
	virtual void show()                           const;
	bool operator==(const Status& status)         const;
	bool operator!=(const Status& status)         const;
};
#endif // !__STATUS_H_
