#ifndef __ADMIN_H
#define __ADMIN_H

#include <iostream>
#include "Date.h"
#include "User.h"
#include "FanPage.h"
#include "AdminException.h"
#define NOT_FOUND -1

class Admin
{
private:
	vector<User*> allUsers;
	vector<FanPage*> allFanPages;

public:
	~Admin();
	//Admin(ifstream& in);
	Admin();
	virtual void save(ofstream& out)                                                                         const;
	vector<User*> getallUsers()                                                                              const;
	vector<FanPage*> getallFanPages()                                                                        const;
	void setAllFanPages(vector<FanPage*> allFanPages);
	void addUserToSystem(string name, const int& day, const int& month, const int& year);
	void addFanpageToSystem(string name);
	int checkIfUserExist(string name)                                                                        const;
	int checkIfFanpageExist(string name)                                                                     const;
	void addStatusToUser(string text, const int& indxUser, const int& statusType, string path)               const;
	void addStatusToFanpage(string text, const int& indxFanPage, const int& statusType, string path)         const;
	void addUserToFanpage(const int& indxFanPage, const int& indxUser)                                       const noexcept(false);
	void addUserToUser(const int& indxUser, const int& indxUser2)                                            const noexcept(false);
	void show10LastStatusesOfaFriendUser(const int& indxUser)                                                const;
	void show10LastStatusesOfaFriendFanPage(const int& indxUser)                                             const;
	void showAllMembers()                                                                                    const;
	void showAllUsers()                                                                                      const;
	void showAllFanPages()                                                                                   const;
	void removeUserFromUser(const int& indxUser, const int& indxUser2) noexcept(false);
	void removeUserFromFanpage(const int& indxFanPage, const int& indxUser) noexcept(false);
	void showUserFriends(const int& indxUser)                                                                const;
	void showFanPageFans(const int& indxFanPage)                                                             const;

	void DeleteFriendsArray(vector<User*> arr);
	void DeleteFanPageArray(vector<FanPage*> arr);
	void cleanBuffer()                                                                                       const;
	void showStatusesOfUser(const int& indx)                                                                 const;
	void showStatusesOfFanPage(const int& indx)                                                              const;
};

#endif // !__ADMIN_H
