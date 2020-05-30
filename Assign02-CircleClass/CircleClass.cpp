//CircleClassSeperate.cpp
//

#include "Circle.h"
#include <iostream>

using namespace std;

int main()
{
	Circle circle01;
	Circle circle02(5.7);
	Circle circle03;
	Circle circle04;

	cout << '\n';
	
	circle01.displayCircleInfo("Circle01");

	circle02.displayCircleInfo("Circle02");

	circle03.setRadius(9.75);
	circle03.displayCircleInfo("Circle03");

	circle04 = circle02;
	circle04.displayCircleInfo("Circle04");

	cout << endl;
	system("pause");
	return 0;
}