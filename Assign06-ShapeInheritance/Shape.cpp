#include "Shape.h"

//Constructors
Shape::Shape()
{
	moveTo(0, 0);
}
Shape::Shape(int newX, int newY)
{
	moveTo(newX, newY);
}

//Getters
int Shape::getX() const
{
	return x;
}
int Shape::getY() const
{
	return y;
}

//Setters
void Shape::setX(int newX)
{
	x = newX;
}
void Shape::setY(int newY)
{
	y = newY;
}

//Misc
void Shape::moveTo(int newX, int newY)
{
	setX(newX);
	setY(newY);
}
void Shape::rMoveTo(int deltaX, int deltaY)
{
	moveTo(getX() + deltaX, getY() + deltaY);
}
void Shape::display() const
{
}