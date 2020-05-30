#include "Name.h"
Name::Name()
{
	last   = "";
	first  = "NO NAME";
	middle = "";
}

Name::Name(string l, string f, string m)
{
	last   = l;
	first  = f;
	middle = m;
}

void Name::setName(string lName, string fName, string mName)
{
	last   = lName;
	first  = fName;
	middle = mName;
}

void Name::displayName() const
{
	std::cout << first << ' ' << middle << ' ' << last << '\n';
}