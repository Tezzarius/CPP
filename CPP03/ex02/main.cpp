#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std::cout << "ClapTrap:" << std::endl << std::endl;

	ClapTrap a("Alpha");
	ClapTrap b("Beta");

	a.attack(b.getName());
	b.takeDamage(3);
	b.beRepaired(2);

	for (int i = 0; i < 11; i++)
		a.attack("Dummy");

	std::cout << std::endl << "ScavTrap:" << std::endl << std::endl;

	ScavTrap g("Gamma");
	ScavTrap d("Delta");

	g.attack(d.getName());
	d.takeDamage(g.getAttackDamage());
	d.beRepaired(10);

	g.guardGate();

	std::cout << "ScavTrap " << g.getName() << " lose 44 energy" << std::endl;
	g.setEnergyPoints(5);

	for (int i = 0; i < 7; i++) {
		g.attack(d.getName());
		if (d.getHitPoints() > 0)
			d.takeDamage(g.getAttackDamage());
	}

	d.attack("Nobody");
	d.beRepaired(10);
	d.guardGate();

	std::cout << std::endl << "FragTrap:" << std::endl << std::endl;

	FragTrap e("Epsilon");
	FragTrap z("Zeta");

	e.attack(z.getName());
	z.takeDamage(e.getAttackDamage());
	z.beRepaired(20);

	e.highFivesGuys();

	std::cout << "FragTrap " << g.getName() << " lose 94 energy" << std::endl;
	g.setEnergyPoints(5);

	for (int i = 0; i < 7; i++) {
		g.attack(d.getName());
		if (z.getHitPoints() > 0)
			z.takeDamage(g.getAttackDamage());
	}

	z.attack("Nobody");
	z.beRepaired(10);
	z.highFivesGuys();

	return 0;
}
