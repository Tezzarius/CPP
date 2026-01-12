#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Alpha");
	ClapTrap b("Beta");

	a.attack(b.getName());
	a.takeDamage(3);
	a.beRepaired(2);

	for (int i = 0; i < 11; i++)
		a.attack("Dummy");

	a.beRepaired(5);

	b.takeDamage(100);
	std::cout << b.getName() << " has " << b.getHitPoints() << " hitpoints left" << std::endl;

	b.attack("Nobody");
	b.beRepaired(10);

	return 0;
}
