#include "Status.h"
#include <string>  


class ImageStatus : public Status
{

private:
	string color;
	string program;
	string path;

public:
	ImageStatus(string content, string path);
	ImageStatus(ifstream& in);
	virtual void save(ofstream& out)              const override;
	void show()                                   const;
};

