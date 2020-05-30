#include "Addr.h"
Addr::Addr()
{
	streetAddr = "NO ADDRESS";
	city	   = "NO CITY";
	state	   = "NO STATE";
	zip		   = "";
}

Addr::Addr(string a, string c, string s, string z)
{
	streetAddr = a;
	city	   = c;
	state	   = s;
	zip		   = z;
}

void Addr::setAddr(string a, string c, string s, string z)
{
	streetAddr = a;
	city	   = c;
	state	   = s;
	zip		   = z;
}

void Addr::displayAddr() const
{
	std::cout << streetAddr   << '\n' 
			  << city << ", " << state << ' ' << zip << "\n\n";
}