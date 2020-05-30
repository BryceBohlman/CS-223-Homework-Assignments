#include "FuelTank.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
FuelTank::FuelTank()								// default constructor (capacity = 0.0, level = 0.0)
{
	capacity = 0.0;
	level = 0.0;
}
FuelTank::FuelTank(double cap)						// construct setting fuel capacity (level = 0.0)
{
	setCapacity(cap);
	level = 0.0;
}
FuelTank::FuelTank(double cap, double lvl)			// construct setting fuel capacity and level
{
	setCapacity(cap);
	level = lvl;
}
void	FuelTank::setCapacity(double amt)			// set or change capacity
{
	capacity = amt;
	if (level > amt)
		level = amt;
}
double	FuelTank::addFuel(double amt)				// add to level - return amount added
{
	double addedAmt;
	if ((level + amt) > getCapacity())
	{
		addedAmt = getUnusedCapacity();
		level   += getUnusedCapacity();
	}
	else
	{
		level = level + amt;
		addedAmt = amt;
	}

	return addedAmt;
}
double	FuelTank::useFuel(double amt)				// subtract from level - return amount used
{
	double usedAmt;
	if (amt > level)
	{
		usedAmt = level;
		level = 0.0;
	}
	else
	{
		level = level - amt;
		usedAmt = amt;
	}

	return usedAmt;
}
double	FuelTank::fillUp()							// return amount used
{
	double addedAmt = getUnusedCapacity();
	level += getUnusedCapacity();
	return addedAmt;
}

//Getters
double	FuelTank::getCapacity()				const	// return fuel tank capacity
{
	return capacity;
}
double	FuelTank::getLevel()				const	// return current fuel level in tank
{
	return level;
}
double	FuelTank::getUnusedCapacity()		const	// return available (unused) fuel capacity
{
	return capacity - level;
}

//Misc
void	FuelTank::displayFuelTankInfo()		const	// show capacity, current level, unused capacity
{
	cout << fixed << setprecision(1) << '\n';

	cout << " fuel capacity:"        << setw(6) << getCapacity()
		 << "   fuel on hand:"       << setw(6) << getLevel()
		 << "   remaining capacity:" << setw(6) << getUnusedCapacity();

	if (isFull())
		cout << "   FULL";
	if (isEmpty())
		cout << "   EMPTY";

	cout << '\n';
}
bool	FuelTank::isFull()					const	// return true if tank is full, else false
{
	return ((level == capacity) && (level != 0.0));
}

bool	FuelTank::isEmpty()					const 
{
	return !level;
}
