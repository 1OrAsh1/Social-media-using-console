#ifndef __UTILITIES_H_
#define __UTILITIES_H_

#include "Status.h"
#include "Date.h"
#include "User.h"
#include "Admin.h"
#include "UtilitiesException.h"

#define ZERO 0
#define ONE 1
#define TWO 2
#define TREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define TEN 10
#define ELEVEN 11
#define TWELVE 12

class Utilities
{
public:
	void printMenu()                                                   const;
	void printWelcome()                                                const;
	void getAction(Admin* facebook, bool& toExit)      const noexcept(false);
	void action1(Admin* facebook, string username)                     const;
	void action2(Admin* facebook, string fanpagename)                  const;
	void action3(Admin* facebook, string name, string status)          const;
	void action4(Admin* facebook, string name)                         const;
	void action5(Admin* facebook, string name)                         const;
	void action6(Admin* facebook, string username, string username2)   const;
	void action7(Admin* facebook, string username, string username2)   const;
	void action8(Admin* facebook, string username, string fanpagename) const;
	void action9(Admin* facebook, string username, string fanpagename) const;
	void action11(Admin* facebook, string name)                        const;
	void createDataBase(Admin* facebook)                               const;
	void create3Users(Admin* facebook)                                 const;
	void create3FanPages(Admin* facebook)                              const;
	void create2StatusUseresFangPages(Admin* facebook)                 const;
	void createConnectionsUsers(Admin* facebook)                       const;
	void createConnectionsUsersAndFanPages(Admin* facebook)            const;
	void alreadyExistUserPropriety(string* name,Admin* facebook)       const;
	void alreadyExistFanPagePropriety(string* name, Admin* facebook)   const;
	int notExistUserPropriety(string * name ,Admin* facebook)          const;
	int notExistFanPagePropriety(string * name, Admin* facebook)       const;

	void cleanBuffer()                                                 const;
};
#endif // !__UTILITIES_H_


