#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &_weapon)
	: _name(_name), _weapon(_weapon) {
	std::cout << _name << " is created" << std::endl;
}

HumanA::HumanA(const HumanA &other)
	: _name(other._name), _weapon(other._weapon) {
	std::cout << _name << " was copied" << std::endl;
}

HumanA &HumanA::operator=(const HumanA &other) {
	if (this != &other) {
		_name = other._name;
		_weapon = other._weapon;
	}
	std::cout << _name << " was assigned" << std::endl;
	return *this;
}

HumanA::~HumanA() {
	std::cout << _name << " is destroyed" << std::endl;
}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}