#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("") {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " is constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "FragTrap " << name << " was copied" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "Copy assignment operator called for FragTrap " << name << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " is destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " wants a high five ✋" << std::endl;
}
