using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include "fstream"
#include "Admin.h"
#include "AdminException.h"
#include "UserException.h"
#include "FanpageException.h"
#include "AddUserToFanpageException.h"
#include "AddUserToUserException.h";
#include "RemoveUserFromFanpageException.h";
#include "RemoveUserFromUserException.h";
#include "AddUserToUserException.h";
#include "SetMinutesException.h";
#include "SetHoursException.h";
#include "FanpageOrUserNotInSystemException.h";
#include "fstream"


void Admin::save(ofstream& out) const
{
	vector<User*>::const_iterator itr = this->allUsers.begin();
	vector<User*>::const_iterator itrEnd = this->allUsers.end();
	vector<FanPage*>::const_iterator itrFanPage = this->allFanPages.begin();
	vector<FanPage*>::const_iterator itrFanPageEnd = this->allFanPages.end();
	int lenName;
	//all friends- for each one we save bday, name, statuses
	int size = this->allUsers.size();
	out.write((const char*)&size, sizeof(int));  //size of users
	for (; itr != itrEnd; ++itr)
	{
		(*itr)->save(out);
	}

	//all fanpages- for each one we save name, statuses, fans
	size = this->allFanPages.size();
	out.write((const char*)&size, sizeof(int));  //size of fan pages
	for (; itrFanPage != itrFanPageEnd; ++itrFanPage)
	{
		(*itrFanPage)->save(out);
	}
	itr = this->allUsers.begin();
	int numFriends;

	//all friends of each friend- for each one we save name
	for (; itr != itrEnd; ++itr)//every user
	{
		numFriends = (*itr)->getFriends().size(); //num of friends of this user
		out.write((const char*)&numFriends, sizeof(int));

		//save all the friends of this user
		vector<User*> friends = (*itr)->getFriends();
		vector<User*>::const_iterator itrFriend = friends.begin();
		vector<User*>::const_iterator itrFriendEnd = friends.end();

		for (; itrFriend != itrFriendEnd; ++itrFriend)
		{
			lenName = (*itrFriend)->getName().length(); //length of name
			out.write((const char*)&lenName, sizeof(int));
			for (int i = 0; i < lenName; i++)
			{
				out.write((const char*)&((*itrFriend)->getName()[i]), sizeof(char));  //each char
			}
		}
	}
}

Admin::~Admin()
{
	ofstream outFile("dataBase.bin", ios::binary | ios::trunc);
	this->save(outFile);
	outFile.close();

	DeleteFriendsArray(this->allUsers);
	DeleteFanPageArray(this->allFanPages);
}


//Admin::Admin(ifstream& in)
Admin::Admin()
{
	ifstream inFile("dataBase.bin", ios::binary | ios::in);
	bool fEOF = false;
	int len, num, lenName, indxFan;
	char ch;
	string tmp;
	inFile.read((char*)&len, sizeof(int)); //number of users
	for (int i = 0; i < len; i++)
	{
		this->allUsers.push_back(new User(inFile));
	}
	inFile.read((char*)&len, sizeof(int)); //number of fanpages

	for (int i = 0; i < len; i++)  //add fanpages
	{
		//add the fanpage to the array
		this->allFanPages.push_back(new FanPage(inFile));

		//get the fans of this fanpage
		inFile.read((char*)&(num), sizeof(int));  //number of fans
		for (int j = 0; j < num; j++)  //for every fan
		{
			//get the name
			string name;
			inFile.read((char*)&(lenName), sizeof(int));  //length of fan name
			for (int k = 0; k < lenName; k++)
			{
				inFile.read((char*)&ch, sizeof(char));
				tmp = ch;
				name += tmp;
			}

			//check if exist and add him
			indxFan = checkIfUserExist(name);
			if (indxFan != NOT_FOUND) addUserToFanpage(i, indxFan);
		}
		continue;
	}

	int indxUser;
	for (int i = 0; i < this->allUsers.size(); i++) //getting every user friends, now they are all in system!
	{
		inFile.read((char*)&num, sizeof(int)); //getting num of friends of user number 'i'
		for (int friendsNum = 0; friendsNum < num; friendsNum++)
		{
			string name;
			inFile.read((char*)&(lenName), sizeof(int));  //length of user name
			for (int k = 0; k < lenName; k++)
			{
				inFile.read((char*)&ch, sizeof(char));
				tmp = ch;
				name += tmp;
			}
			indxUser = checkIfUserExist(name);
			try
			{
				addUserToUser(i, indxUser);
			}
			catch (AddUserToUserException& e) {}
		}

	}
	inFile.close();
}

void Admin::DeleteFriendsArray(vector<User*> arr)
{
	vector<User*>::const_iterator itr = arr.begin();
	vector<User*>::const_iterator itrEnd = arr.end();
	for (; itr != itrEnd; ++itr)
	{
		delete* itr;
	}
}

void Admin::DeleteFanPageArray(vector<FanPage*> arr)
{
	vector<FanPage*>::const_iterator itr = arr.begin();
	vector<FanPage*>::const_iterator itrEnd = arr.end();
	for (; itr != itrEnd; ++itr)
	{
		delete* itr;
	}
}

vector<User*> Admin::getallUsers() const
{
	return this->allUsers;
}

vector<FanPage*> Admin::getallFanPages() const
{
	return this->allFanPages;
}

void Admin::setAllFanPages(vector<FanPage*> allFanPages)
{
	this->allFanPages = allFanPages;
}

void Admin::addUserToSystem(string name, const int& day, const int& month, const int& year)
{
	this->allUsers.push_back(new User(name, day, month, year));
	cout << "The user \"" << (*(this->allUsers).back()).getName() << "\" has been created succesfully!" << endl;
}

void Admin::addFanpageToSystem(string name)
{
	this->allFanPages.push_back(new FanPage(name));
	cout << "The fan page \"" << (*(this->allFanPages).back()).getName() << "\" has been created succesfully!" << endl;
}

int Admin::checkIfUserExist(string name) const
{
	int res = NOT_FOUND;
	int i = 0;
	vector<User*>::const_iterator itr = this->allUsers.begin();
	vector<User*>::const_iterator itrEnd = this->allUsers.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == name)
		{
			res = i;
		}
		i++;
	}
	return res;
}

int Admin::checkIfFanpageExist(string name) const
{
	int res = NOT_FOUND;
	int i = 0;
	vector<FanPage*>::const_iterator itr = this->allFanPages.begin();
	vector<FanPage*>::const_iterator itrEnd = this->allFanPages.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == name)
		{
			res = i;
		}
		i++;
	}
	return res;
}

void Admin::addStatusToUser(string newStatus, const int& indxUser, const int& statusType, string path) const
{
	vector<User*>::const_iterator userItr = this->allUsers.begin();
	userItr += indxUser;
	(*userItr)->addStatusToBulletinBoard(newStatus, statusType, path);
}

void Admin::addStatusToFanpage(string newStatus, const int& indxFanPage, const int& statusType, string path) const
{
	vector<FanPage*>::const_iterator fanpageItr = this->allFanPages.begin();
	fanpageItr += indxFanPage;
	(*fanpageItr)->addStatusToBulletinBoard(newStatus, statusType, path);
}

void Admin::addUserToFanpage(const int& indxFanPage, const int& indxUser) const noexcept(false)
{
	bool isExist;
	vector<User*>::const_iterator userItr = this->allUsers.begin();
	vector<FanPage*>::const_iterator fanpageItr = this->allFanPages.begin();
	userItr += indxUser;
	fanpageItr += indxFanPage;

	isExist = (*userItr)->isFanOfFanpage(*(*fanpageItr));
	if (isExist)
	{
		throw AddUserToFanpageException((*userItr)->getName(), (*fanpageItr)->getName());

	}
	else //connect between fanpage and user
	{
		//add the fanpage to the fanpage array in user
		*(*userItr) += *((*fanpageItr));

		// add the user to the fans array in fanpage
		*(*fanpageItr) += *((*userItr));

		cout << (*userItr)->getName() << " is now a new fan of " << (*fanpageItr)->getName() << "." << endl;
	}
}

void Admin::addUserToUser(const int& indxUser, const int& indxUser2) const noexcept(false)
{
	bool isExist = false;//they are already friends
	vector<User*>::const_iterator user1Itr = this->allUsers.begin();
	vector<User*>::const_iterator user2Itr = this->allUsers.begin();
	user1Itr += indxUser;
	user2Itr += indxUser2;

	isExist = (*user1Itr)->isFriendOfUser(*(*user2Itr));
	if (isExist)
	{
		throw AddUserToUserException((*user1Itr)->getName(), (*user2Itr)->getName());
	}
	else //connect between 2 users
	{
		//add user #1 to the friends array of user #2
		*(*user1Itr) += *((*user2Itr));

		//add user #2 to the friends array of user #1
		*(*user2Itr) += *((*user1Itr));

		cout << (*user1Itr)->getName() << " is a new friend of " << (*user2Itr)->getName() << "." << endl;
	}
}

void Admin::cleanBuffer() const
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

void Admin::showStatusesOfUser(const int& indx) const
{
	vector<User*>::const_iterator userItr = this->allUsers.begin();
	userItr += indx;
	(*userItr)->getBulletinBoard()->show();
}

void Admin::showStatusesOfFanPage(const int& indx) const
{
	vector<FanPage*>::const_iterator fanpageItr = this->allFanPages.begin();
	fanpageItr += indx;
	(*fanpageItr)->getBulletinBoard()->show();
}

void Admin::show10LastStatusesOfaFriendUser(const int& indxUser) const
{
	vector<User*>::const_iterator userItr = this->allUsers.begin();
	vector<User*>::const_iterator userItrEnd = this->allUsers.end();
	userItr += indxUser;

	if ((*userItr)->getFriends().size() == 0)
	{
		cout << "This user has no friends." << endl;
	}
	else
	{
		vector<User*> friends = (*userItr)->getFriends();
		vector<User*>::const_iterator friendItr = friends.begin();
		vector<User*>::const_iterator friendItrEnd = friends.end();

		for (; friendItr != friendItrEnd; ++friendItr)
		{
			cout << "\n\nStatuses of the User: " << (*friendItr)->getName() << endl;
			(*friendItr)->getBulletinBoard()->showLast10Statuses();
		}
	}
}

void Admin::show10LastStatusesOfaFriendFanPage(const int& indxFanPage) const
{
	vector<FanPage*>::const_iterator fanpageItr = this->allFanPages.begin();
	vector<FanPage*>::const_iterator fanpageItrEnd = this->allFanPages.end();
	fanpageItr += indxFanPage;
	if ((*fanpageItr)->getFans().size() == 0)
	{
		cout << "This fan page has no fans yet." << endl;
	}
	else
	{
		vector<User*> fans = (*fanpageItr)->getFans();
		vector<User*>::const_iterator fansItr = fans.begin();
		vector<User*>::const_iterator fansItrEnd = fans.end();

		for (; fansItr != fansItrEnd; ++fansItr)
		{
			cout << "Statuses of the Fan: " << (*fansItr)->getName() << endl;
			(*fansItr)->getBulletinBoard()->showLast10Statuses();
		}
	}
}

void Admin::showAllMembers() const
{
	if (this->allUsers.size() == 0)
	{
		cout << "There are no useres in system." << endl;
	}
	else
	{
		cout << "All the users in system:" << endl;
		showAllUsers();
	}
	if (this->allFanPages.size() == 0)
	{
		cout << "There are no fan pages in system." << endl;
	}
	else
	{
		cout << "All the fan pages in system:" << endl;
		showAllFanPages();
	}
}

void Admin::showAllUsers() const
{
	int i = 1;
	vector<User*>::const_iterator itr = this->allUsers.begin();
	vector<User*>::const_iterator itrEnd = this->allUsers.end();
	for (; itr != itrEnd; ++itr)
	{
		cout << "User #" << i << " ";
		(*itr)->showUser();
		cout << endl;
		i++;
	}
}

void Admin::showAllFanPages() const
{
	int i = 1;
	vector<FanPage*>::const_iterator itr = this->allFanPages.begin();
	vector<FanPage*>::const_iterator itrEnd = this->allFanPages.end();
	for (; itr != itrEnd; ++itr)
	{
		cout << "FanPage #" << i << " ";
		(*itr)->showFanPage();
		cout << endl;
		i++;
	}
}

void Admin::removeUserFromUser(const int& indxUser, const int& indxUser2) noexcept(false)
{
	bool isExist = false;

	vector<User*>::iterator user1Itr = this->allUsers.begin();
	vector<User*>::iterator user2Itr = this->allUsers.begin();
	user1Itr += indxUser;
	user2Itr += indxUser2;
	isExist = (*user1Itr)->isFriendOfUser(*(*user2Itr));

	if (!isExist)
	{
		throw RemoveUserFromUserException((*user1Itr)->getName(), (*user2Itr)->getName());
	}
	else // they are friends- we'll remove the friendship
	{
		//remove user #1 to the friends array of user #2
		(*user1Itr)->removeFriend((*user2Itr));

		//remove user #2 to the friends array of user #1
		(*user2Itr)->removeFriend((*user1Itr));

		cout << "The friendship has been removed successfully." << endl;
	}
}

void Admin::removeUserFromFanpage(const int& indxFanPage, const int& indxUser) noexcept(false)
{
	bool isExist;
	vector<User*>::iterator userItr = this->allUsers.begin();
	vector<FanPage*>::iterator fanpageItr = this->allFanPages.begin();
	userItr += indxUser;
	fanpageItr += indxFanPage;
	isExist = (*userItr)->isFanOfFanpage(*(*fanpageItr));
	if (!isExist)
	{
		throw RemoveUserFromFanpageException((*userItr)->getName(), (*fanpageItr)->getName());
	}
	else // the user is a fan of this page- we'll remove it
	{
		//remove the fanpage from the array of fanpages of the user
		(*userItr)->removeFanPage((*fanpageItr));

		//remove user #2 to the friends array of user #1
		(*fanpageItr)->removeFan((*userItr));

		cout << "The friendship has been removed successfully." << endl;
	}
}

void Admin::showUserFriends(const int& indxUser) const
{
	vector<User*>::const_iterator userItr = this->allUsers.begin();
	userItr += indxUser;
	(*userItr)->showFriends();
}

void Admin::showFanPageFans(const int& indxFanPage) const
{
	vector<FanPage*>::const_iterator fanpageItr = this->allFanPages.begin();
	fanpageItr += indxFanPage;
	(*fanpageItr)->showFans();
}

