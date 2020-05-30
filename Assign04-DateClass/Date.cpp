#include "Date.h"
#include <iostream>
#include <iomanip>
//#include <string>

using namespace std;

//Constructors

Date::Date()											// default constructor (no parameters)
{
	setDefaultDate();
}
Date::Date(int m, int d, int y)							// constructor with month day year parameters - check for validity
{
	setDate(m, d, y);
}

//Setters

void	Date::setDate(int mm, int dd, int yyyy)
{
	year  = yyyy;
	month = mm;
	day   = dd;

	if (!validDate())
		setDefaultDate();
}
void	Date::setDefaultDate()							// set month day year values to default date ( 1/01/1970)
{
	year  = 1970;
	month =    1;
	day   =    1;
}

//Getters

int		Date::getMonth()	const						// return current month value
{
	return month;
}
int		Date::getDay()		const						// return current day   value
{
	return day;
}
int		Date::getYear()		const						// return current 4-digit year value
{
	return year;
}

//Display Function

void	Date::displayDate()	const						// display current date  value in mm/dd/yyyy format
{
	cout << setfill(' ') << setw(2) << month << '/' << setfill('0') << setw(2) << day << '/' << year << '\n';
	/*string monthStr;
	string daySuffix;

		if (day == 1 || day == 21 || day == 31)
			daySuffix = "st";
		else if (day == 2 || day == 22)
			daySuffix = "nd";
		else if (day == 3 || day == 23)
			daySuffix = "rd";
		else
			daySuffix = "th";
	
	switch (month)
	{
	case 1:  monthStr = "January ";
		break;
	case 2:  monthStr = "February ";
		break;
	case 3:  monthStr = "March ";
		break;
	case 4:  monthStr = "April ";
		break;
	case 5:  monthStr = "May ";
		break;
	case 6:  monthStr = "June ";
		break;
	case 7:  monthStr = "July ";
		break;
	case 8:  monthStr = "August ";
		break;
	case 9:  monthStr = "September ";
		break;
	case 10: monthStr = "October ";
		break;
	case 11: monthStr = "November ";
		break;
	case 12: monthStr = "December ";
		break;
	}

	cout << monthStr << ' ' << day << daySuffix << ", " << year << '\n';*/
}

//Checkers

bool	Date::validMonth()	const						// check for valid month range
{
	return (month > 0 && month <= 12);
}
bool	Date::validDay()	const						// check for valid day   range
{
	if (day > 0)
	{
		int maxDay = 31;

		if (month == 4 || month == 6 || month == 9 || month == 11)
			maxDay = 30;
		if (month == 2)
		{
			maxDay = 28;
			if (year % 4 == 0)
				maxDay = 29;
			if (year % 100 == 0)
				maxDay = 28;
			if (year % 400 == 0)
				maxDay = 29;
		}
		return (day <= maxDay);
	}
	return false;
}
bool	Date::validYear()								// check for valid year  value (must be >= zero)
{
	if (year >= 0)
	{
		if (year <= 30)
			setDate(month, day, year + 2000);
		else if (year < 100)
			setDate(month, day, year + 1900);

		return true;
	}
	return false;
}
bool	Date::validDate()								// check for valid month, day, and year
{
	return (validYear() && validMonth() && validDay());
}

//Data members

int		month;											// current month value
int		day;											// current day   value
int		year;
