#include "Zombie.hpp"

Zombie::Zombie() : _name("Zombie") {
	std::cout << "Zombie is created" << std::endl;
}

Zombie::Zombie(std::string _name) : _name(_name) {
	std::cout << _name << " is created" << std::endl;
}

Zombie::Zombie(const Zombie &other) {
	_name = other._name;
	std::cout << _name << " was copied" << std::endl;
}

Zombie &Zombie::operator=(const Zombie &other) {
	if (this != &other) {
		_name = other._name;
	}
	std::cout << _name << " was assigned" << std::endl;
	return *this;
}

Zombie::~Zombie() {
	std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}