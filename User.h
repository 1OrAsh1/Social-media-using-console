#ifndef __USER_H_
#define __USER_H_
#include "Date.h"
#include "BulletinBoard.h"
#include "FanPage.h"
#include "UserException.h"

class FanPage;

class User
{
private:
	string name;
	const Date birthday;
	BulletinBoard * feed;
	vector<User*> friends;
	vector<FanPage*>  fanPages;

public:
	User(string personName, int day, int month, int year)noexcept(false);
	User(ifstream& in);
	virtual void save(ofstream& out)                                          const;
	User(const User& other);
	~User();
	string getName()                                                          const;
	vector<FanPage*> getFanPage()                                             const;
	const Date getBirthday()                                                  const;
	BulletinBoard * getBulletinBoard()                                        const;
	int getFriendsSize()                                                      const;
	void addStatusToBulletinBoard(string newStatus, const int& statusType, string path);
	bool isFanOfFanpage(const FanPage& name)                                  const;
	bool isFriendOfUser(const User& name)                                     const;
	void addNewFanpage(FanPage* newFanpage);
	void addNewFriend(User* newUser);
	vector<User*>  getFriends()                                               const;
	void showUser()                                                           const;
	void removeFriend(const User* user);
	void removeFanPage(const FanPage* fanpage);
	void showFriends()                                                        const;
	void showFanPages()                                                       const;
	const User& operator+=(User& newUser);
	const User& operator+=(FanPage& newFanpage);
	bool operator>(const User& user2)                                         const;
	bool operator>(const FanPage& fanPage2)                                   const;

};

#endif !__USER_H_
