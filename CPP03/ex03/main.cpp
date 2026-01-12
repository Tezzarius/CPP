#include "DiamondTrap.hpp"

int main() {
	ClapTrap a("Alpha");
	ClapTrap b("Beta");

	a.attack(b.getName());
	b.takeDamage(3);
	b.beRepaired(2);

	for (int i = 0; i < 11; i++)
		a.attack("Titan");

	b.attack("Nobody");
	b.beRepaired(10);

	std::cout << std::endl;

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

	std::cout << std::endl;

	FragTrap e("Epsilon");
	FragTrap z("Zeta");

	e.attack(z.getName());
	z.takeDamage(e.getAttackDamage());
	z.beRepaired(20);

	e.highFivesGuys();

	std::cout << "FragTrap " << e.getName() << " lose 94 energy" << std::endl;
	e.setEnergyPoints(5);

	for (int i = 0; i < 7; i++) {
		e.attack(d.getName());
		if (z.getHitPoints() > 0)
			z.takeDamage(e.getAttackDamage());
	}

	z.attack("Nobody");
	z.beRepaired(10);
	z.highFivesGuys();

	std::cout << std::endl;

	DiamondTrap et("Eta");
	DiamondTrap t("Theta");

	et.attack(t.getName());
	t.takeDamage(et.getAttackDamage());
	t.beRepaired(20);

	et.whoAmI();

	std::cout << "FragTrap " << et.getName() << " lose 44 energy" << std::endl;
	et.setEnergyPoints(5);

	for (int i = 0; i < 7; i++) {
		et.attack(d.getName());
		if (t.getHitPoints() > 0)
			t.takeDamage(et.getAttackDamage());
	}

	t.attack("Nobody");
	t.beRepaired(10);
	t.whoAmI();

	return 0;
}
