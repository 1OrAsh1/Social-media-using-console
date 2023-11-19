#include "Status.h"
#include <string>  


class VideoStatus : public Status
{

private:
	string color;
	string program;
	string path;

public:
	VideoStatus(string content, string path);
	VideoStatus(ifstream& in);
	virtual void save(ofstream& out) const override;
	void show()                      const;


};
