#pragma once
#include <string>

using namespace std;

class Circle
{
public:
	Circle();
	Circle(double initialRadius);
	double getRadius()        const;
	double getDiameter()      const;
	double getArea()          const;
	double getCircumference() const;
	void   setRadius(double newRadius);
	void   displayCircleInfo(string);
private:
	double radius;
};

