#pragma once
#include "Addr.h"
#include "Name.h"
static int clientNumber = 1000;
class Client
{
private:
	int  clientID;
	Name clientName;
	Addr clientAddr;
public:
	Client();
	Client(string l, string f, string m, string a, string c, string s, string z);
	void displayClient() const;
};

