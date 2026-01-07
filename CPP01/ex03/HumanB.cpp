#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	this->is_armed = false;
	std::cout << name << " is created" << std::endl;
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
		std::cout << name << " attacks with their " << weapon->getType() << "." << std::endl;
	else
		std::cout << name << " attacks with their fists." << std::endl;
}