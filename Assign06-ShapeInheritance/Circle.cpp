#include "Circle.h"

using namespace std;

//Constructors
Circle::Circle()
{
	setRadius(1);
}
Circle::Circle(int newX, int newY, int newRadius)
	  : Shape(newX, newY)
{
	setRadius(newRadius);
}

//Getters
int Circle::getRadius()			const
{
	return radius;
}
double Circle::getArea()		const
{
	return PI * (getRadius() * getRadius());
}
double Circle::getPerimeter()	const
{
	return 2 * PI * getRadius();
}

//Setters
void Circle::setRadius(int newRadius)
{
	radius = newRadius;
}

//Misc
void Circle::display()			const
{
	cout << fixed << setprecision(3);
	cout << "Circle   : (" << setw(2) << getX() << ',' << setw(2)  << getY() << ')'
		 << "  radius: "   << setw(2) << getRadius()   
		 << setw(21) << "area:"   << setw(8) << getArea() 
		 << "   " << "perimeter:" << setw(8) << getPerimeter() 
		 << '\n';
}
