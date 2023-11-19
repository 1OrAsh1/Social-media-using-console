#define _CRT_SECURE_NO_WARNINGS
#define __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#define _CRT_NONSTDC_NO_WARNINGS
using namespace std;
#include <iostream>
#include "fstream"
#include <string.h>
#include "FanPage.h"



FanPage::~FanPage()
{
	delete feed;
}

FanPage::FanPage(string fanpageName) noexcept(false) :name(fanpageName)
{
	if (fanpageName.length() == 0)
	{
		delete this->feed;
		throw FanPageException();
	}
	this->feed = new BulletinBoard();
}

FanPage::FanPage(ifstream& in)
{
	int len;
	char ch;
	string tmp;
	in.read((char*)&(len), sizeof(int));  //len of name
	for (int i = 0; i < len; i++)
	{
		in.read((char*)&ch, sizeof(char));
		tmp = ch;
		this->name += tmp;
	}
	this->feed = new BulletinBoard(in);
}

void FanPage::save(ofstream& out) const
{
	vector<User*>::const_iterator itr = this->fans.begin();
	vector<User*>::const_iterator itrEnd = this->fans.end();
	int lenName = this->name.length();
	out.write((const char*)&lenName, sizeof(lenName));  //length of name
	for (int i = 0; i < lenName; i++)
	{
		out.write((const char*)&this->name[i], sizeof(char));  //each char
	}
	(this->feed)->save(out);  //bulletin board
	int num=(this->fans).size();
	out.write((const char*)&num, sizeof(int));  //num of fans
	for (; itr != itrEnd; ++itr)
	{
		lenName = (*itr)->getName().length();
		out.write((const char*)&lenName, sizeof(lenName));  //length of name
		for (int i = 0; i < lenName; i++)
		{
			out.write((const char*)&(*itr)->getName()[i], sizeof(char));  //each char
		}
		
	}

	

}
string FanPage::getName() const
{
	return this->name;
}

vector<User*> FanPage::getFans() const
{
	return this->fans;
}

BulletinBoard* FanPage::getBulletinBoard() const
{
	return this->feed;
}

int FanPage::getFansSize() const
{
	return this->fans.size();
}

void FanPage::setFeed(BulletinBoard* feed)
{
	this->feed;
}

void FanPage::addStatusToBulletinBoard(string newStatus, const int& statusType, string path)
{
	(this->feed)->addStatus(newStatus,statusType,path);
}

void FanPage::addNewFan(User* user)
{
	this->fans.push_back(user);
}

void FanPage::showFanPage() const
{
	cout << "Name: " << this->name;
}

void FanPage::removeFan(const User* user)
{
	bool found = false;
	vector<User*>::iterator itr = this->fans.begin();
	vector<User*>::iterator itrEnd = this->fans.end();
	if (1 != this->fans.size()) //not the only fan
	{
		vector<User*>::iterator itrNext = this->fans.begin();
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
	this->fans.pop_back();
}

void FanPage::showFans() const
{
	if (this->fans.size() == 0)
	{
		cout << "This page has no fans yet." << endl;
	}
	else
	{
		vector<User*>::const_iterator itr = this->fans.begin();
		vector<User*>::const_iterator itrEnd = this->fans.end();

		for (; itr != itrEnd; ++itr)
		{
			(*itr)->showUser();
			cout << endl;
		}
	}
}

const FanPage& FanPage::operator+=(User& newUser)
{
	addNewFan(&newUser);
	return *this;
}

bool FanPage::operator>(const User& user2) const
{
	return (this->getFansSize() > user2.getFriendsSize());
}

bool FanPage::operator>(const FanPage& fanPage2) const
{
	return (this->getFansSize() > fanPage2.getFansSize());
}