#include <iostream>
using namespace std;
#include "Admin.h"
#include "BulletinBoard.h"
#include "Clock.h"
#include "Date.h"
#include "FanPage.h"
#include "Status.h"
#include "User.h"
#include "Utilities.h"
#include "fstream"

void main()
{
	//ifstream inFile("dataBase.bin", ios::binary | ios::in);
	//inFile.close();
	//min* facebook = new Admin(inFile);
	Admin* facebook = new Admin();
	bool toExit = false;

	Utilities u1;
	//u1.createDataBase(facebook);
	u1.printWelcome();

	do {
		u1.printMenu();
		u1.getAction(facebook, toExit);
	} while (!toExit);
	delete facebook;
}