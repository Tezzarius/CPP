#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(const std::string &type) {
	this->type = type;
}

Weapon::~Weapon() {}

std::string const& Weapon::getType() {
	return type;
}

void Weapon::setType(const std::string &type) {
	this->type = type;
}