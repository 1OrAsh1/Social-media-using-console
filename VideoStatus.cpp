#include "VideoStatus.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;
#include "fstream"

VideoStatus::VideoStatus(string content, string path) :Status(content), color("colored"), program("media program"), path(path) {}

VideoStatus::VideoStatus(ifstream& in):Status(in), color("colored"), program("media program")
{
	char ch;
	string tmp;
	int len;
	in.read((char*)&len, sizeof(int)); //length of path
	for (int i = 0; i < len; i++)
	{
		in.read((char*)&ch, sizeof(char));
		tmp = ch;
		this->path += tmp;
	}
}

void VideoStatus::save(ofstream& out) const
{
	char ch;
	Status::save(out);
	int len = this->path.length();
	out.write((const char*)&len, sizeof(int));  //length of path
	for (int i = 0; i < len; i++)
	{
		ch = this->path[i];
		out.write((const char*)&ch, sizeof(char));
	}
}

void VideoStatus::show() const
{
	Status::show();
	cout << "Video: " << path << endl;
	cout << "<This video status is printed in " <<this->color<<">"<<endl;
	cout << "<This video status is shown using a "<<this->program<<">"<<endl;
}
