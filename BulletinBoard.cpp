#include "BulletinBoard.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "fstream"
using namespace std;

BulletinBoard::BulletinBoard(){}
BulletinBoard::BulletinBoard(const BulletinBoard& newBoard){}

BulletinBoard::BulletinBoard(ifstream& in)
{
	int statusType;
	int len;
	in.read((char*)&len, sizeof(int)); //num of statuses
	for (int i = 0; i < len; i++)
	{
		in.read((char*)&statusType, sizeof(int));   //type of status
		if (statusType == 1)
		{
			this->statuses.push_back(new Status(in));
		}
		else if (statusType == 2)
		{
			this->statuses.push_back(new ImageStatus(in));
		}
		else if (statusType == 3)
		{
			this->statuses.push_back(new VideoStatus(in));
		}
	}
}

BulletinBoard::~BulletinBoard()
{
	deleteStatusesPtr();
}

void BulletinBoard::save(ofstream& out) const
{
	int print;
	vector<Status*>::const_iterator itr = this->statuses.begin();
	vector<Status*>::const_iterator itrEnd = this->statuses.end();
	int num=this->statuses.size();
	out.write((const char*)&num, sizeof(num)); //num of statuses
	for (; itr != itrEnd; ++itr)
	{
		if (strcmp(typeid(**itr).name(), typeid(Status).name())==0) //normal status
		{
			print = 1;
			out.write((const char*)&print, sizeof(int));
			(*itr)->save(out);
		}
		else if (strcmp(typeid(**itr).name(), typeid(ImageStatus).name())==0) //image status
		{
			print = 2;
			out.write((const char*)&print, sizeof(int));
			(*itr)->save(out);

		}
		else if (strcmp(typeid(**itr).name(), typeid(VideoStatus).name())==0) //video status
		{
			print = 3;
			out.write((const char*)&print, sizeof(int));
			(*itr)->save(out);
		}

	}
}

void BulletinBoard::deleteStatusesPtr()
{
	vector<Status*>::iterator itr = this->statuses.begin();
	vector<Status*>::iterator itrEnd = this->statuses.end();

	for (;itr!= itrEnd;++itr)
	{
		delete *itr;
	}
}

vector<Status*> BulletinBoard::getStatuses() const
{
	return this->statuses;
}

void BulletinBoard::addStatus(string newStatus, const int& statusType, string path)
{
	if (statusType == 1)
	{
		this->statuses.push_back(new Status(newStatus));
	}
	else if (statusType == 2)
	{
		this->statuses.push_back(new ImageStatus(newStatus,path));
	}
	else if (statusType == 3)
	{
		this->statuses.push_back(new VideoStatus(newStatus,path));
	}
	cout << "The status has been created succesfully!" << endl;
}

void BulletinBoard::show() const
{
	int i=1;
	vector<Status*>::const_iterator itr = this->statuses.begin();
	vector<Status*>::const_iterator itrEnd= this->statuses.end();
	for (;itr!=itrEnd;++itr)
	{
		cout << "status #" << i << "-";
		(*itr)->show();
		i++;
	}
}

void BulletinBoard::showLast10Statuses() const 
{
	int c = 1;
	vector<Status*>::const_iterator itr = this->statuses.begin();
	vector<Status*>::const_iterator itrEnd = this->statuses.end();
	if (this->statuses.size() == 0)
	{
		cout<< "The user has no statuses."<<endl;
	}
	else
	{
		if (this->statuses.size() > 10)
		{
			while (this->statuses.size() - c != 10)
			{
				++itr;
				c++;
			}
			++itr;
		}

		c = 1;
		while (c <= this->statuses.size() && itrEnd != itr && c <= 10)
		{
			cout << "\nstatus #" << c << "-";
			(*itr)->show();
			++itr;
			c++;
		}
	}
}