#include "Date.h"

using namespace std;

istream&	operator>>(istream& inObj, Date& dateObj)			// overloaded extraction operator - friend to Date class
{
	inObj >> dateObj.month >> dateObj.day >> dateObj.year;

	return inObj;
}
ostream&	operator<<(ostream& outObj, const Date& dateObj)
{
	outObj << setfill(' ') << setw(2) << dateObj.month << '/'
		   << setfill('0') << setw(2) << dateObj.day   << '/'
		                   << setw(4) << dateObj.year  << '\n';
	return outObj;
}

Date::Date()
{
	setDefaultDate();
}
Date::Date(int m, int d, int y)									// constructor with month day year parameters
{
	setDate(m, d, y);
}


void	Date::setDate(int mm, int dd, int yyyy)
{
	month = mm;
	day	  = dd;
	year  = yyyy;
}
void	Date::setDefaultDate()									// set default date - 1/01/1970
{
	setDate(1, 1, 1970);
}

void	Date::displayDate()	const
{
	cout << setfill(' ') << setw(2) << month << '/'
		 << setfill('0') << setw(2) << day   << '/'
		                 << setw(4) << year;
}

bool	Date::operator==(const Date& compDate) const			// overloaded equals operator				 ==
{
	return ((month == compDate.month) &&
			(day   == compDate.day  ) &&
			(year  == compDate.year ));
}
bool	Date::operator!=(const Date& compDate) const			// overloaded not equal operator			 !=
{
	return ((month != compDate.month) ||
			(day   != compDate.day	) ||
			(year  != compDate.year ));
}
bool	Date::operator<(const  Date& compDate) const			// overloaded less than operator			 <
{
	return ((year <  compDate.year)								||
			(year == compDate.year && month <   compDate.month) ||
			(year == compDate.year && month ==  compDate.month  && day < compDate.day));
}
bool	Date::operator>(const  Date& compDate) const			// overloaded greater than operator			 >
{
	return ((year >  compDate.year)								||
			(year == compDate.year && month >   compDate.month) ||
			(year == compDate.year && month ==  compDate.month  && day > compDate.day));
}
bool	Date::operator<=(const Date& compDate) const			// overloaded less than or equal operator    <=
{
	if (year < compDate.year)
		 return true;
	else if (year == compDate.year && month <  compDate.month)
		 return true;
	else if (year == compDate.year && month == compDate.month && day <= compDate.day)
		 return true;
	else return false;
}
bool	Date::operator>=(const Date& compDate) const			// overloaded greater than or equal operator =>
{
	if (year > compDate.year)
		 return true;
	else if (year == compDate.year && month >  compDate.month)
		 return true;
	else if (year == compDate.year && month == compDate.month && day >= compDate.day)
		 return true;
	else return false;
}

