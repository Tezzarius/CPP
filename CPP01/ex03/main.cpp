#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA alpha("Alpha", club);
		alpha.attack();
		club.setType("some other type of club");
		alpha.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB beta("Beta");
		beta.attack();
		beta.setWeapon(club);
		beta.attack();
		club.setType("some other type of club");
		beta.attack();
	}
	return 0;
}