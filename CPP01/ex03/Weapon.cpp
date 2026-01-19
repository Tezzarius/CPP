#include "Weapon.hpp"

Weapon::Weapon() {
	
}

Weapon::Weapon(const std::string &type) {
	this->type = type;
}

Weapon::Weapon(const Weapon &other) {
	type = other.type;
}

Weapon &Weapon::operator=(const Weapon &other) {
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

Weapon::~Weapon() {

}

std::string const& Weapon::getType() {
	return type;
}

void Weapon::setType(const std::string &type) {
	this->type = type;
}