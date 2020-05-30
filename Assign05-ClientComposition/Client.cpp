#include "Client.h"

Client::Client():
	clientName(), 
	clientAddr()
{
	clientID = ++clientNumber;
}

Client::Client(string l, string f, string m, string a, string c, string s, string z):
	clientName(l, f, m), 
	clientAddr(a, c, s, z)
{
	clientID = ++clientNumber;
}

void Client::displayClient() const
{
	std::cout << clientID << '\n';
	clientName.displayName();
	clientAddr.displayAddr();
}
