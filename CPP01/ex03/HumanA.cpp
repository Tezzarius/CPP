#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon) {
	this->name = name;
	std::cout << name << " is created" << std::endl;
}

HumanA::HumanA(const HumanA &other) : weapon(other.weapon) {
	name = other.name;
	std::cout << name << " was copied" << std::endl;
}

HumanA &HumanA::operator=(const HumanA &other) {
	if (this != &other) {
		name = other.name;
		weapon = other.weapon;
	}
	std::cout << name << " was assigned" << std::endl;
	return *this;
}

HumanA::~HumanA() {
	std::cout << name << " is destroyed" << std::endl;
}

void HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << "." << std::endl;
}