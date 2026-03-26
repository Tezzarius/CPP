#include "ScavTrap.hpp"

int main() {
	std::cout << "ClapTrap:" << std::endl << std::endl;

	ClapTrap a("Alpha");
	ClapTrap b("Beta");

	a.attack(b.getName());
	b.takeDamage(3);
	b.beRepaired(2);

	for (int i = 0; i < 11; i++) {
		a.attack("Dummy");
	}

	std::cout << std::endl << "ScavTrap:" << std::endl << std::endl;

	ScavTrap g("Gamma");
	ScavTrap d("Delta");

	g.attack(d.getName());
	d.takeDamage(20);
	d.beRepaired(10);

	g.guardGate();

	std::cout << "ScavTrap " << g.getName() << " lose 44 energy" << std::endl;
	g.setEnergyPoints(5);

	for (int i = 0; i < 7; i++) {
		g.attack(d.getName());
		if (d.getHitPoints() > 0) {
			d.takeDamage(g.getAttackDamage());
		}
	}

	d.attack("Nobody");
	d.beRepaired(10);
	d.guardGate();

	return 0;
}
