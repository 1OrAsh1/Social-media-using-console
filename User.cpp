#define _CRT_SECURE_NO_WARNINGS
#define __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#define _CRT_NONSTDC_NO_WARNINGS
#include <string.h>
#include "fstream"
#include <iostream>
using namespace std;
#include "User.h"
#include "Date.h"

User::User(string personName, int day, int month, int year)noexcept(false) :birthday(day, month, year),name(personName)
{
	if (personName.length() == 0)
	{
		delete feed;
		throw UserException();
	}
	this->feed = new BulletinBoard();
	this->friends;
	this->fanPages;
}

User::User(ifstream& in):birthday(in)
{
	int len;
	char ch;
	string tmp;
	in.read((char*)&(len), sizeof(int));
	for (int i = 0; i < len; i++)
	{
		in.read((char*)&ch, sizeof(char));
		tmp = ch;
		this->name += tmp;
	}
	this->feed = new BulletinBoard(in);
	this->friends;
	this->fanPages;

}

User::User(const User& other) {}

User::~User()
{
	delete feed;
}

void User::save(ofstream& out) const
{
	this->birthday.save(out);
	//(this->birthday).save(out);  //birthday
	int lenName = this->name.length();
	out.write((const char*)&lenName, sizeof(lenName));  //length of name
	for (int i = 0; i < lenName; i++)
	{
		out.write((const char*)&this->name[i], sizeof(char));  //each char
	}
	(this->feed)->save(out);  //bulletin board
}

string User::getName() const
{
	return this->name;
}

vector<FanPage*> User::getFanPage() const
{
	return this->fanPages;
}

const Date User::getBirthday() const
{
	return this->birthday;
}

BulletinBoard* User::getBulletinBoard() const
{
	return this->feed;
}

int User::getFriendsSize() const
{
	return this->friends.size();
}

void User::addStatusToBulletinBoard(string newStatus, const int& statusType, string path)
{
	(this->feed)->addStatus(newStatus,statusType,path);
}

bool User::isFanOfFanpage(const FanPage& name) const
{
	bool alreadyFan = false;
	vector<FanPage*>::const_iterator itr = this->fanPages.begin();
	vector<FanPage*>::const_iterator itrEnd = this->fanPages.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == name.getName()) //name is uniqe
			alreadyFan = true;
	}
	return alreadyFan;
}

bool User::isFriendOfUser(const User& name) const
{
	bool alreadyFriend = false;
	vector<User*>::const_iterator itr = this->friends.begin();
	vector<User*>::const_iterator itrEnd = this->friends.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == name.getName()) //name is uniqe
			alreadyFriend = true;
	}
	return alreadyFriend;
}

void User::addNewFanpage(FanPage* newFanpage)
{
	this->fanPages.push_back(newFanpage);
}

void User::addNewFriend(User* newUser)
{
	this->friends.push_back(newUser);
}

vector<User*> User::getFriends() const
{
	return this->friends;
}

void User::showUser() const
{
	cout << "Name: " << this->name << ", Birthday ";
	this->birthday.show();
}

void User::removeFriend(const User* user)
{
	bool found = false;
	vector<User*>::iterator itr = this->friends.begin();
	vector<User*>::iterator itrEnd = this->friends.end();

	if (1 != this->friends.size()) //not the only friend
	{
		vector<User*>::iterator itrNext = this->friends.begin();
		++itrNext;

		for (; itrNext != itrEnd; ++itr)
		{
			if (found)
			{
				(*itr) = (*itrNext);
			}
			else if ((*itr) == user)
			{
				(*itr) = (*itrNext);
				found = true;
			}
			itrNext++;
		}
	}
	this->friends.pop_back();

}

void User::removeFanPage(const FanPage* fanpage)
{
	bool found = false;
	vector<FanPage*>::iterator itr = this->fanPages.begin();
	vector<FanPage*>::iterator itrEnd = this->fanPages.end();
	if (1 != this->fanPages.size()) //not the only fanpage
	{
		vector<FanPage*>::iterator itrNext = this->fanPages.begin();
		++itrNext;

		for (; itrNext != itrEnd; ++itr)
		{
			if (found)
			{
				(*itr) = (*itrNext);
			}
			else if ((*itr) == fanpage)
			{
				(*itr) = (*itrNext);
				found = true;
			}
			itrNext++;
		}
	}
	this->fanPages.pop_back();
}

void User::showFriends() const 
{
	if (this->friends.size() == 0)
	{
		cout<< "This user has no friends yet."<<endl;
	}
	else
	{
		vector<User*>::const_iterator itr = this->friends.begin();
		vector<User*>::const_iterator itrEnd = this->friends.end();
		for (; itr != itrEnd; ++itr)
		{
			(*itr)->showUser();
			cout << endl;
		}
	}
}

void User::showFanPages() const
{
	if (this->fanPages.size() == 0)
	{
		cout<< "This user is not a fan of any fan page yet.\n";
	}
	else
	{
		vector<FanPage*>::const_iterator itr = this->fanPages.begin();
		vector<FanPage*>::const_iterator itrEnd = this->fanPages.end();
		for (; itr != itrEnd; ++itr)
		{
			(*itr)->showFanPage();
			cout << endl;
		}
	}
}

const User& User::operator+=(User& newUser)
{
	addNewFriend(&newUser);
	return *this;
}

const User& User::operator+=(FanPage& newFanpage)
{
	addNewFanpage(&newFanpage);
	return *this;
}

bool User::operator>(const User& user2) const
{
	return (this->getFriendsSize() > user2.getFriendsSize());
}

bool User::operator>(const FanPage& fanPage2) const
{
	return (this->getFriendsSize() > fanPage2.getFansSize());
}
