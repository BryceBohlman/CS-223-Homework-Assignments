#include "Circle.h"
#include <iostream>
#include <iomanip>

const double PI = 3.14159;

Circle::Circle()												//Default constructor
{
	radius = 1.0;
}

Circle::Circle(double initialRadius)							//Constructor with Radius perameter
{
	radius = initialRadius;
}

double Circle::getRadius()   const								//Returns radius
{																
	return radius;												
}

double Circle::getDiameter() const								//Calculates and returns diameter
{
	return radius * 2.0;
}

double Circle::getArea()     const								//Calculates and returns area
{
	return radius * radius * PI;
}

double Circle::getCircumference() const							//Calculates and returns circumference
{
	return getDiameter() * PI;
}

void   Circle::displayCircleInfo(string circleName)																									//Outputs to console:
{
	cout << fixed << setprecision(2);
	cout << '\n' << circleName << ":  Radius -"     << setw(8) << getRadius() << "   " << "Diameter      -" << setw(8) << getDiameter()				//On first  line: NAME, RADIUS, DIAMETER
		 << '\n' << setw(11)   << ' ' << "Area   -" << setw(8) << getArea()   << "   " << "Circumference -" << setw(8) << getCircumference()		//On second line: AREA, CIRCUMFERENCE
		 << '\n';
}

void   Circle::setRadius(double newRadius)						//Change circle size following object declaration
{
	radius = newRadius;
}
