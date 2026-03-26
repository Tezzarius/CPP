#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: _name(name), _is_armed(false) {
	std::cout << name << " is created" << std::endl;
}

HumanB::HumanB(const HumanB &other) 
	: _name(other._name), _weapon(other._weapon), _is_armed(other._is_armed) {
	std::cout << _name << " was copied" << std::endl;
}

HumanB &HumanB::operator=(const HumanB &other) {
	if (this != &other) {
		_name = other._name;
		_weapon = other._weapon;
		_is_armed = other._is_armed;
	}
	std::cout << _name << " was assigned" << std::endl;
	return *this;
}

HumanB::~HumanB() {
	std::cout << _name << " is destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
	this->_is_armed = true;
}

void HumanB::attack() {
	if (_is_armed)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their fists." << std::endl;
}