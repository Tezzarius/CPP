#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: name(name), is_armed(false) {
	std::cout << name << " is created" << std::endl;
}

HumanB::HumanB(const HumanB &other) 
	: name(other.name), weapon(other.weapon), is_armed(other.is_armed) {
	std::cout << name << " was copied" << std::endl;
}

HumanB &HumanB::operator=(const HumanB &other) {
	if (this != &other) {
		name = other.name;
		weapon = other.weapon;
		is_armed = other.is_armed;
	}
	std::cout << name << " was assigned" << std::endl;
	return *this;
}

HumanB::~HumanB() {
	std::cout << name << " is destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
	this->is_armed = true;
}

void HumanB::attack() {
	if (is_armed)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " attacks with their fists." << std::endl;
}