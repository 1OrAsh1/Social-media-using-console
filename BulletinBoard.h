#ifndef __BULLETINBOARD_H_
#define __BULLETINBOARD_H_
#include <vector>
#include "Status.h"
#include "ImageStatus.h"
#include "VideoStatus.h"


class BulletinBoard
{
private:
	vector<Status*> statuses;

public:
	BulletinBoard();
	BulletinBoard(ifstream& in);
	BulletinBoard(const BulletinBoard& newBoard);
	virtual void save(ofstream& out)                                         const;
	~BulletinBoard();
	void deleteStatusesPtr();
	vector<Status*> getStatuses()                                            const;
	void addStatus(string newStatus, const int& statusType, string path);
	void show()                                                              const;
	void showLast10Statuses()                                                const;
};

#endif // !__BULLETINBOARD_H_
