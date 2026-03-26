#include "Weapon.hpp"

Weapon::Weapon() {
	
}

Weapon::Weapon(const std::string &type) {
	this->_type = type;
}

Weapon::Weapon(const Weapon &other) {
	_type = other._type;
}

Weapon &Weapon::operator=(const Weapon &other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Weapon::~Weapon() {

}

std::string const& Weapon::getType() {
	return _type;
}

void Weapon::setType(const std::string &type) {
	this->_type = type;
}