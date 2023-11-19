#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include <string>
#include "Utilities.h"
#include "AddUserToFanpageException.h"
#include "AddUserToUserException.h"
#include "AdminException.h"
#include "ClockException.h"
#include "DateException.h"
#include "FanPageException.h"
#include "RemoveUserFromFanpageException.h"
#include "RemoveUserFromUserException.h"
#include "SetHoursException.h"
#include "SetMinutesException.h"
#include "StatusException.h"
#include "UserException.h"
#include "GetActionException.h"
#include "UtilitiesException.h"
#include "UserOrFanpageException.h"
#include "FanpageOrUserNotInSystemException.h"
#include "AlreadyExistException.h"
#include "AddHimselfException.h"

void Utilities::createDataBase(Admin* facebook) const
{
	create3Users(facebook);
	cout << endl;
	create3FanPages(facebook);
	cout << endl;
	create2StatusUseresFangPages(facebook);
	cout << endl;
	createConnectionsUsers(facebook);
	cout << endl;
	createConnectionsUsersAndFanPages(facebook);
}

void Utilities::create3Users(Admin* facebook) const
{
	string name1;
	string name2;
	string name3;
	name1 = "Keren Schoss";
	name2 = "Or Asherov";
	name3 = "Keren Kalif";
	facebook->addUserToSystem(name1, 5, 5, 2000);
	facebook->addUserToSystem(name2, 13, 8, 2001);
	facebook->addUserToSystem(name3, 20, 11, 1999); //cause you look like you're 23 ;) 
}


void Utilities::create3FanPages(Admin* facebook) const
{
	string name1;
	string name2;
	string name3;
	name1 = "Keren Kalif lovers";
	name2 = "Keren Kalif supporters";
	name3 = "Keren Kalif fans";
	facebook->addFanpageToSystem(name1);
	facebook->addFanpageToSystem(name2);
	facebook->addFanpageToSystem(name3);
}

void Utilities::create2StatusUseresFangPages(Admin* facebook) const
{
	int indx;
	string status;
	string name;
	//adding 2 statuses to the 3 users
	name = "Or Asherov";
	status = "I know you love me. xoxo gossip girl.";
	indx = facebook->checkIfUserExist(name);
	facebook->addStatusToUser(status, indx,1,"");
	status = "Everyone says you're a jungle freak who's a less hot version of me.";
	facebook->addStatusToUser(status, indx,1,"");

	name = "Keren Schoss";
	indx = facebook->checkIfUserExist(name);
	status = "Don't be a drug just be a queen.";
	facebook->addStatusToUser(status, indx,1,"");
	status = "Or Asherov was here looolllll";
	facebook->addStatusToUser(status, indx,1,"");

	name = "Keren Kalif";
	indx = facebook->checkIfUserExist(name);
	status = "Intresting sense of style, ten million dollar smile. Think I can handle that. (B.S)";
	facebook->addStatusToUser(status, indx,2,".\media\Kitten.jpg");
	status = "Dance the night away...Finish me lol XDXDXD";
	facebook->addStatusToUser(status, indx,3,".\media\Earth.mov");

	//adding 2 statuses to the 3 fan pages
	name = "Keren Kalif lovers";
	indx = facebook->checkIfFanpageExist(name);
	status = "Dani, 35, single. Actually I've been single for too long and I'm looking for my dream girl,\n\ the one that will make me feel complete since I've been feeling so lonely and unloved.\n\ God I wish it was Keren Kalif. lol keep dreaming... ";
	facebook->addStatusToFanpage(status, indx,1,"");
	status = "Eww L-O-S-E-R... BLOCKEDD hahaha\n\ p.s. Keren Kalif is mine";
	facebook->addStatusToFanpage(status, indx,1,"");

	name = "Keren Kalif fans";
	indx = facebook->checkIfFanpageExist(name);
	status = "Roses are red, violets are blue. Keren Kalif I'm in love with you.";
	facebook->addStatusToFanpage(status, indx,1,"");
	status = "Of a scale of 1-10 I love Keren Kalif 1000000020033399399939292999344366";
	facebook->addStatusToFanpage(status, indx,1,"");

	name = "Keren Kalif supporters";
	indx = facebook->checkIfFanpageExist(name);
	status = "Stop bullying it's not cool";
	facebook->addStatusToFanpage(status, indx,1,"");
	status = "Now I'm the bad guy. Call me Chun-Li\n\Nickiiii Minajjjj is the queen of rap!! try me.";
	facebook->addStatusToFanpage(status, indx,1,"");
}

void Utilities::createConnectionsUsers(Admin* facebook) const
{
	facebook->addUserToUser(0, 1);
	facebook->addUserToUser(1, 2);
}

void Utilities::createConnectionsUsersAndFanPages(Admin* facebook)const
{
	facebook->addUserToFanpage(0, 1);
	facebook->addUserToFanpage(1, 0);
	facebook->addUserToFanpage(1, 2);
	facebook->addUserToFanpage(2, 1);
}

void Utilities::printMenu() const
{
	cout << endl << "-------------------------------------------------------------------------------------" << endl << endl;
	cout << "      Enter a number between 1-12:" << endl << endl;
	cout << "      1- Add user" << endl;
	cout << "      2- Add fanpage" << endl;
	cout << "      3- Add status" << endl;
	cout << "      4- All statuses of a friend or a fanpage" << endl;
	cout << "      5- 10 most updated statuses of your friends" << endl;
	cout << "      6- Connect between two friends" << endl;
	cout << "      7- Delete friendship between two friends" << endl;
	cout << "      8- Add a fan to a fanpage " << endl;
	cout << "      9- Remove fan from a page " << endl;
	cout << "      10- View all the members " << endl;
	cout << "      11- View all friend of a specific user or all the fans of a specific page" << endl;
	cout << "      12- Exit" << endl;
	cout << endl << "-------------------------------------------------------------------------------------" << endl << endl;
}

void Utilities::printWelcome() const
{
	cout << "              ________________________________                  " << endl;
	cout << "             |                                |                 " << endl;
	cout << "             |      W E L C O M E   T O       |                 " << endl;
	cout << "             |                                |                 " << endl;
	cout << "             |        T H E   R E A L         |                 " << endl;
	cout << "             |                                |                 " << endl;
	cout << "             |        F A C E B O O K         |                 " << endl;
	cout << "             |                                |                 " << endl;
	cout << "             |________________________________|                 " << endl;
	cout << "                                                                " << endl;
	cout << "                BY OR ASHEROV & KEREN SCHOSS                    " << endl;
	cout << "                   322235284 & 319129995                        " << endl;
	cout << "                                                                " << endl;
	cout << "                  * Beware of Copycats *                        " << endl;
	cout << "                                                                " << endl;
}

void Utilities::getAction(Admin* facebook, bool& toExit ) const noexcept(false)
{
	int action, type, indx;
	int userIndx, fanpageIndx, userIndx2;
	string username, status, fanpagename, name, username2, tmpaction;

	try
	{
		cout << "Enter your action: ";
		cin >> action;
		if (!(action >= ONE && action <= TWELVE))
		{
			throw GetActionException();
		}
		//else {
		if (action == ONE)
		{
			action1(facebook, username);
		}
		else if (action == TWO)
		{
			action2(facebook, fanpagename);
		}
		else if (action == TREE)
		{
			action3(facebook, name, status);
		}
		else if (action == FOUR)
		{
			action4(facebook, name);
		}
		else if (action == FIVE)
		{
			action5(facebook, name);
		}
		else if (action == SIX)
		{
			action6(facebook, username, username2);
		}
		else if (action == SEVEN)
		{
			action7(facebook, username, username2);
		}
		else if (action == EIGHT)
		{
			action8(facebook, username, fanpagename);
		}
		else if (action == NINE)
		{
			action9(facebook, username, fanpagename);
		}
		else if (action == TEN)
		{
			facebook->showAllMembers();
		}
		else if (action == ELEVEN)
		{
			action11(facebook, name);
		}
		else //action=12
		{
			toExit = true;
		}

	}
	catch (AddHimselfException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (AlreadyExistException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (FanpageOrUserNotInSystemException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (AddUserToFanpageException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (AddUserToUserException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (RemoveUserFromFanpageException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (RemoveUserFromUserException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (SetHoursException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (SetMinutesException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (StatusException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (UserException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (GetActionException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (UserOrFanpageException& e) {
		cout << endl << e.what() << endl;
	}
	catch (UtilitiesException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (AdminException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (ClockException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (DateException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (FanPageException& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (...)
	{
		cout << "<< some general exception. >>";
	}

}


void Utilities::action1(Admin* facebook, string username) const
{
	cout << "Enter the user name: ";
	cleanBuffer();
	getline(cin, username);
	if (username.length() == 0)
	{
		throw UserException();
	}
	else
	{
		alreadyExistUserPropriety(&username, facebook);
		//now I have the name of a new User, we'll get his birthday
		int day, month, year;
		cout << "Enter your birth day, month and year (seperated by spaces): ";
		cin >> day >> month >> year;
		if (!(day >= 1 && day <= 31 &&
			month >= 1 && month <= 12 &&
			year >= START_YEAR && year <= 2023)) //not valid
		{
			throw DateException();
		}
		else
		{
			facebook->addUserToSystem(username, day, month, year);
		}
	}
}

void Utilities::action2(Admin* facebook, string fanpagename) const
{
	cout << "Enter the fan page name: ";
	cleanBuffer();
	getline(cin, fanpagename);
	alreadyExistFanPagePropriety(&fanpagename, facebook);
	//now I have the name of a new User, we'll get his birthday
	facebook->addFanpageToSystem(fanpagename);
}

void Utilities::action3(Admin* facebook, string name, string status) const
{
	string path="";
	int type, indx, statusType;
	cout << endl << "Enter 1- to add status to user <or> 2- to add status to fan page: ";
	cin >> type;
	while (type != ONE && type != TWO)
	{
		throw UserOrFanpageException();
		cout << "Enter 1- to add status to user <or> 2- to add status to fan page: ";
		cin >> type;
	}
	cout << "Enter the name: ";
	cleanBuffer();
	getline(cin, name);
	if (type == ONE) //to user
	{
		indx = notExistUserPropriety(&name, facebook);
		cout << "Enter 1- to add text status <or> 2- to add text and image status <or> 3- to add text and video status: ";
		cin >> statusType;
		cleanBuffer();
		cout << "Enter your text: ";
		getline(cin, status);
		if (statusType == 2 || statusType == 3)
		{
			cout << "Enter path: ";
			getline(cin,path);
		}
		facebook->addStatusToUser(status, indx,statusType,path);
	}
	else //to fan page
	{
		indx = notExistFanPagePropriety(&name, facebook);
		cout << "Enter 1- to add text status <or> 2- to add text and image status <or> 3- to add text and video status: ";
		cin >> statusType;
		cleanBuffer();
		cout << "Enter your status: ";
		getline(cin, status);
		if (statusType == 2 || statusType == 3)
		{
			cout << "Enter path: ";
			getline(cin, path);
		}
		facebook->addStatusToFanpage(status, indx,statusType,path);
	}
}

void Utilities::action4(Admin* facebook, string name) const
{
	int type, indx;
	cout << endl << "Enter 1- to show statuses of a user <or> 2- to show statuses of a fan page: ";
	cin >> type;
	while (type != ONE && type != TWO)
	{
		throw UserOrFanpageException();
		cout << "Enter 1- to show statuses of a user <or> 2- to show statuses of a fan page ";
		cin >> type;
	}
	cout << "Enter the name: ";
	cleanBuffer();
	getline(cin, name);
	if (type == ONE) //to user
	{
		indx = notExistUserPropriety(&name, facebook);
		facebook->showStatusesOfUser(indx);
	}
	else //to fan page
	{
		indx = notExistFanPagePropriety(&name, facebook);
		facebook->showStatusesOfFanPage(indx);
	}
}

void Utilities::action5(Admin* facebook, string name) const
{
	int type, indx;
	cout << endl << "Enter 1- if you are a user <or> 2- if you are a fan page: ";
	cin >> type;
	while (type != ONE && type != TWO)
	{
		throw UserOrFanpageException();
		cout << "Enter 1- if you are a user <or> 2- if you are a fan page: ";
		cin >> type;
	}
	cout << "Enter your name: ";
	cleanBuffer();
	getline(cin, name);
	if (type == ONE) //user
	{
		indx = notExistUserPropriety(&name, facebook);
		facebook->show10LastStatusesOfaFriendUser(indx);
	}
	else //fan page
	{
		indx = notExistFanPagePropriety(&name, facebook);
		facebook->show10LastStatusesOfaFriendFanPage(indx);
	}

}
void Utilities::action6(Admin* facebook, string username, string username2) const
{
	int userIndx, userIndx2;
	cout << "Enter user #1 name: ";
	cleanBuffer();
	getline(cin, username);
	userIndx = notExistUserPropriety(&username, facebook);

	cout << "Enter user #2 name: ";
	getline(cin, username2);
	userIndx2 = notExistUserPropriety(&username2, facebook);

	//now I have a valid username and fanpage name
	while (username == username2)
	{
		throw AddHimselfException();
		cout << "Enter user #2 name: ";
		getline(cin, username2);
	}
	facebook->addUserToUser(userIndx, userIndx2);
}

void Utilities::action7(Admin* facebook, string username, string username2) const
{
	int userIndx, userIndx2;
	cout << "Enter user #1 name: ";
	cleanBuffer();
	getline(cin, username);
	userIndx = notExistUserPropriety(&username, facebook);

	cout << "Enter user #2 name: ";
	getline(cin, username2);
	userIndx2 = notExistUserPropriety(&username2, facebook);

	//now I have a valid username and fanpage name
	while (username == username2)
	{
		throw AddHimselfException();
		cout << "Enter user #2 name: ";
		getline(cin, username2);
	}
	facebook->removeUserFromUser(userIndx, userIndx2);
}

void Utilities::action8(Admin* facebook, string username, string fanpagename) const
{
	int fanpageIndx, userIndx;
	cout << "Enter the fan page name: ";
	cleanBuffer();
	getline(cin, fanpagename);
	fanpageIndx = notExistFanPagePropriety(&fanpagename, facebook);

	cout << "Enter the user name: ";
	getline(cin, username);
	userIndx = notExistUserPropriety(&username, facebook);

	//now I have a valid username and fanpage name
	facebook->addUserToFanpage(fanpageIndx, userIndx);
}

void Utilities::action9(Admin* facebook, string username, string fanpagename) const
{
	int userIndx, fanpageIndx;
	cout << "Enter the fan page name: ";
	cleanBuffer();
	getline(cin, fanpagename);
	fanpageIndx = notExistFanPagePropriety(&fanpagename, facebook);

	cout << "Enter the user name: ";
	getline(cin, username);
	userIndx = notExistUserPropriety(&username, facebook);

	//now I have a valid username and fanpage name
	facebook->removeUserFromFanpage(fanpageIndx, userIndx);
}

void Utilities::action11(Admin* facebook, string name) const
{
	int type, indx;
	cout << endl << "Enter 1- if you are a user <or> 2- if you are a fan page: ";
	cin >> type;
	while (type != ONE && type != TWO)
	{
		throw UserOrFanpageException();
		cout << "Enter 1- if you are a user <or> 2- if you are a fan page: ";
		cin >> type;
	}
	cout << "Enter name: ";
	cleanBuffer();
	getline(cin, name);
	if (type == ONE) //user
	{
		indx = notExistUserPropriety(&name, facebook);
		facebook->showUserFriends(indx);
	}
	else //fan page
	{
		indx = notExistFanPagePropriety(&name, facebook);
		facebook->showFanPageFans(indx);
	}
}

void Utilities::cleanBuffer() const
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

void Utilities::alreadyExistUserPropriety(string* name, Admin* facebook) const
{
	int inSystem = facebook->checkIfUserExist(*name);
	while (inSystem != NOT_FOUND)
	{
		throw AlreadyExistException(*name);
		cout << "Enter the user name: ";
		getline(cin, *name);
		inSystem = facebook->checkIfUserExist(*name);
	}
}

void Utilities::alreadyExistFanPagePropriety(string* name, Admin* facebook) const
{
	int inSystem = facebook->checkIfFanpageExist(*name);
	while (inSystem != NOT_FOUND)
	{
		throw AlreadyExistException(*name);
		cout << "Enter the fan page name: ";
		getline(cin, *name);
		inSystem = facebook->checkIfFanpageExist(*name);
	}
}

int Utilities::notExistUserPropriety(string* name, Admin* facebook) const
{
	int inSystem = facebook->checkIfUserExist(*name);
	while (inSystem == NOT_FOUND)
	{
		throw FanpageOrUserNotInSystemException(*(name));
		cout << "Enter the user name: ";
		getline(cin, *name);
		inSystem = facebook->checkIfUserExist(*name);
	}
	return inSystem;
}

int Utilities::notExistFanPagePropriety(string* name, Admin* facebook) const
{
	int inSystem = facebook->checkIfFanpageExist(*name);
	while (inSystem == NOT_FOUND)
	{
		throw FanpageOrUserNotInSystemException(*(name));
		cout << "Enter the fan page name: ";
		getline(cin, *name);
		inSystem = facebook->checkIfFanpageExist(*name);
	}
	return inSystem;
}