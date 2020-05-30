#pragma once
#include "Shape.h"
class Circle : public Shape
{
private:
	int radius;
	const double PI = 3.1416;
public:
	Circle();
	Circle(int newX, int newY, int newRadius);

	int getRadius()			const;
	double getArea()		const;
	double getPerimeter()	const;

	void setRadius(int newRadius);

	void display()			const;
};

