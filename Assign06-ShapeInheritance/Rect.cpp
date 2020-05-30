#include "Rect.h"

using namespace std;

//Constructors
Rectangle::Rectangle()
{
	setWidth (2);
	setHeight(1);
}
Rectangle::Rectangle(int newX, int newY, int newWidth, int newHeight)
		 : Shape(newX, newY)
{
	setWidth (newWidth);
	setHeight(newHeight);
}

//Getters
int  Rectangle::getWidth()			const
{
	return width;
}
int  Rectangle::getHeight()			const
{
	return height;
}
double Rectangle::getArea()			const
{
	return getWidth() * getHeight();
}
double Rectangle::getPerimeter()	const
{
	return 2 * (getHeight() + getWidth());
}

//Setters
void Rectangle::setWidth(int newWidth)
{
	width = newWidth;
}
void Rectangle::setHeight(int newHeight)
{
	height = newHeight;
}

//Misc
void Rectangle::display()			const
{
	cout << "Rectangle: (" << setw(2) << getX() << ',' << setw(2) << getY() << ')'
	     << "  width:  "   << setw(2) << getWidth()
	     << "  height: "   << setw(2) << getHeight() 
		 << "    area:"    << setw(8) << getArea()
		 << "   perimeter:"<< setw(8) << getPerimeter()
		 << '\n';
}
