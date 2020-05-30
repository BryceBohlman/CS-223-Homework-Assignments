#pragma once
#include <iostream>
#include <string>
using namespace std;
class Addr
{
private:
	string streetAddr;
	string city;
	string state;
	string zip;
public:
	Addr();
	Addr(string a, string c, string s, string z);

	void setAddr(string a, string c, string s, string z);
	void displayAddr() const;
};

