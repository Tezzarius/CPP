#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("") {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " is constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.name) {
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "ScavTrap " << name << " was copied" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {

}

ScavTrap::~ScavTrap() {

}

void ScavTrap::guardGate() {

}
