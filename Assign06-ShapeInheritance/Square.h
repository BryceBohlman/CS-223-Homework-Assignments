#pragma once
#include "Rect.h"
class Square : public Rectangle
{
private:
	int side;
public:
	Square();
	Square(int newX, int newY, int length);
	int getSide()			const;
	void setSide(int newLength);
	void display()			const;
};

