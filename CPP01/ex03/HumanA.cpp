#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon){
	this->name = name;
	std::cout << name << " is created" << std::endl;
}

HumanA::~HumanA() {
	std::cout << name << " is destroyed" << std::endl;
}

void HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << "." << std::endl;
}