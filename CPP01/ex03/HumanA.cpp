#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	: name(name), weapon(weapon) {
	std::cout << name << " is created" << std::endl;
}

HumanA::HumanA(const HumanA &other)
	: name(other.name), weapon(other.weapon) {
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
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}