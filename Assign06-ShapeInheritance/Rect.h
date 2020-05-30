#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
private:
	int width;
	int height;
public:
	Rectangle();
	Rectangle(int newX, int newY, int newWidth, int newHeight);

	int  getWidth()			const;
	int  getHeight()		const;
	double getArea()		const;
	double getPerimeter()	const;

	void setWidth(int newWidth);
	void setHeight(int newHeight);

	void display()			const;
};

