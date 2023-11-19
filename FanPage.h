#ifndef __FANPAGE_H_
#define __FANPAGE_H_
#include <iostream>
#include <vector>
#include "BulletinBoard.h"
#include "User.h"
#include "FanPageException.h"
class User;

class FanPage 
{
private:
	string name;
	vector<User*> fans;
	BulletinBoard* feed;

public:
	~FanPage();
	FanPage(string fanpageName) noexcept(false);
	FanPage(ifstream& in);
	virtual void save(ofstream& out)                                                const;
	string getName()                                                                const;
	vector<User*> getFans()                                                         const;
	BulletinBoard* getBulletinBoard()                                               const;
	int getFansSize()                                                               const;
	void setFeed(BulletinBoard* feed);
	void addStatusToBulletinBoard(string newStatus, const int& statusType, string path);
	void addNewFan(User* user);
	void showFanPage()                                                              const;
	void removeFan(const User* user);
	void showFans()                                                                 const;
	const FanPage& operator+=(User& newUser);
	bool operator>(const User& user2)                                               const;
	bool operator>(const FanPage& fanPage2)                                         const;
};

#endif // !__FANPAGE_H_
