//Driver program for Client class
//

#include "Client.h";
#include <iostream>;

int main()
{
	Client client01("Barton", "Martha", "L.", "4521 Oak", "Kansas City", "MO", "64110");
	Client client02("Engle", "Harold", "", "1711 E. 68th St.", "Kansas City", "MO", "64129");
	Client client03("Worthington", "Burton", "Ray", "2735 Bellefontaine", "Kansas City", "MO", "64109");
	Client client04;

	client01.displayClient();
	client02.displayClient();
	client03.displayClient();
	client04.displayClient();

	std::cout << std::endl;
	system("pause");
	return 0;
}