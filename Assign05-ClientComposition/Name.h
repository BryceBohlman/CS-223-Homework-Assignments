#pragma once
#include <iostream>
#include <string>
using namespace std;
class Name
{
private:
	string last;
	string first;
	string middle;
public:
	Name();
	Name(string l, string f, string m);

	void setName(string lName, string fName, string mid);
	void displayName() const;
};

