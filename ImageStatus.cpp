#include "ImageStatus.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include "fstream"

ImageStatus::ImageStatus(string content, string path) : Status(content), color("colored"), program("simple program"), path(path) {}

ImageStatus::ImageStatus(ifstream& in):Status(in), color("colored"), program("simple program")
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

void ImageStatus::save(ofstream& out) const
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


void ImageStatus::show() const
{
	Status::show();
	cout << "Image: " << path << endl;
	cout << "<This image is printed in " << this->color<<">"<<endl;
	cout << "<This image is shown using a " <<this->program<<">"<<endl;
}

