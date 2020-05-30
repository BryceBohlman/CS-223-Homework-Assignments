#include "Square.h"

using namespace std;

Square::Square()
{
	setSide(1);
}
Square::Square(int newX, int newY, int length)
	  : Rectangle(newX, newY, length, length)
{
	setSide(length);
}
int Square::getSide()			const
{
	return side;
}
void Square::setSide(int newLength)
{
	side = newLength;
	Rectangle::setWidth(newLength);
	Rectangle::setHeight(newLength);
}
void Square::display()			const
{
	cout << "Square   : ("  << setw(2) << getX()  << ", " << setw(2) << getY() << ") "
		 << "    length of side: "     << setw(2) << getSide() 
		 << "    area:"     << setw(8) << getArea()
		 << "   perimeter:" << setw(8) << getPerimeter()
		 << '\n';
}

