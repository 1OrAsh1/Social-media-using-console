#include "Status.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "fstream"
using namespace std;
#include <string> 
#include "string.h" 

Status::Status(string content) noexcept(false):program("simple program"), color("B&W")
{
	if (content.length()==0)
		throw StatusException();
	else
		this->text=content ;
}

Status::Status(ifstream& in):publishDate(in),publishHour(in)
{
	char ch;
	int len;
	string tmp;
	in.read((char*)&len, sizeof(int));  //length of text
	for (int i = 0; i < len; i++)
	{
		in.read((char*)&ch, sizeof(char));
		tmp = ch;
		this->text += tmp;
	}
	in.read((char*)&len, sizeof(int));  //length of color
	for (int i = 0; i < len; i++)
	{
		in.read((char*)&ch, sizeof(char));
		tmp = ch;
		this->color += tmp;
	}
	in.read((char*)&len, sizeof(int));  //length of program
	for (int i = 0; i < len; i++)
	{
		in.read((char*)&ch, sizeof(char));
		tmp = ch;
		this->program += tmp;
	}
	

}

void Status::save(ofstream& out) const
{
	this->publishDate.save(out);
	this->publishHour.save(out);
	char ch;
	int len=this->text.length();
	
	out.write((const char*)&len, sizeof(int));  //length of text
	for (int i = 0; i < len; i++)
	{
		ch = this->text[i];
		out.write((const char*)&ch, sizeof(char));
	}
	
	len = this->color.length();     //length of color
	out.write((const char*)&len, sizeof(int));
	for (int i = 0; i < len; i++) 
	{
		ch = this->color[i];
		out.write((const char*)&ch, sizeof(char));
	}
	
	len = this->program.length();     //length of program
	out.write((const char*)&len, sizeof(int));
	for (int i = 0; i < len; i++)
	{
		ch = this->program[i];
		out.write((const char*)&ch, sizeof(char));
	}
}

Status::Status(const Status& other)
{
	this->text = other.getText();
}

Status:: ~Status() {};

const Date& Status::getPublishDate() const
{
	return this->publishDate;
}

const Clock& Status::getPublishHour() const
{
	return this->publishHour;
}

 const string Status::getText() const
{
	return this->text;
}

void Status::showDate() const
{
	this->publishDate.show();
}

void Status::showHour() const
{
	this->publishHour.show();
}

void Status::showText() const
{
	cout << this->text << endl;
}

void Status::show() const
{
	cout << "\nText: ";
	this->showText();
	cout << "Was published at ";
	this->showDate();
	this->showHour();
	cout << "\n<This text is shown using a " << this->program <<">"<< endl;
	cout << "<This text is printed in "<<this->color<<">"<<endl;
}

bool Status::operator==(const Status& status) const
{
	return (this->getText() == status.getText());
}

bool Status::operator!=(const Status& status) const
{
	return!(*this == status);
}